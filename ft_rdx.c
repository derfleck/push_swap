/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:30:10 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/20 18:13:49 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//initializes the moves array and calls sort_stack function
int	*calc_moves(int *order, int values)
{
	int	pos;
	int	i;
	int	*moves_temp;
	int	*moves_start;

	pos = 0;
	i = 0;
	while (to_power(2, pos) < values)
		pos++;
	moves_temp = calloc(pos * values * 2, sizeof(int));
	moves_start = moves_temp;
	while (i < pos)
	{
		sort_stack(order, moves_temp, values, i++);
		while (*moves_temp)
			moves_temp++;
	}
	return (moves_start);
}

t_set	*set_settings(int *a, int *b, int len_a, int len_b)
{
	t_set	*set;

	set = malloc(sizeof(t_set));
	set->a = a;
	set->b = b;
	set->len_a = len_a;
	set->len_b = len_b;
	return (set);
}

//checks which move to perform
void	perform_moves(t_set	*set, int step)
{
	if (step == 1)
	{
		set->moves[set->i++] = 1;
		push(set->b, set->a, set->len_b--, set->len_a++);
	}
	else if (step == 2)
	{
		set->moves[set->i++] = 2;
		push(set->a, set->b, set->len_a--, set->len_b++);
	}
	else if (step == 3)
	{
		set->moves[set->i++] = 3;
		rotate(set->a, set->len_a);
	}
}

//perform radix sort on binary value
//stop = 0
//pa = 1
//pb = 2
//ra = 3
void	sort_stack(int *a, int *moves, int values, int pos)
{
	/*
	int	i;
	int	len_a;
	int	len_b;
	int	*b;

	i = 0;
	len_a = values;
	b = malloc(sizeof(int) * values);
	len_b = 0;
	*/
	t_set	*set;

	set = set_settings(a, malloc(sizeof(int) * values), values, 0);
	set->moves = moves;
	while (set->i < values)
	{
		if ((a[0] >> pos) & 0x01)
			perform_moves(set, 3);
		else
			perform_moves(set, 2);
		set->i++;
	}
	while (set->len_b)
		perform_moves(set, 1);
	moves[set->i] = 0;
	free(set->b);
}

//performs swap (sa/sb)
void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//performs push (pa/pb)
void	push(int *src, int *dst, int len_src, int len_dst)
{
	int	i;

	i = 0;
	while (len_dst)
	{
		dst[len_dst] = dst[len_dst - 1];
		len_dst--;
	}
	dst[0] = *src;
	while (i < len_src)
	{
		src[i] = src[i + 1];
		i++;
	}
}

//performs rotate (ra/rb)
void	rotate(int *values, int len)
{
	int	tmp;
	int	i;

	tmp = *values;
	i = 0;
	while (i < len - 1)
	{
		*(values + i) = *(values + i + 1);
		i++;
	}
	*(values + i) = tmp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:30:10 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/22 17:00:44 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

//initializes the moves array and calls sort_stack function
int	*calc_moves(int *order, int values)
{
	int		pos;
	int		i;
	t_set	*set;

	pos = 0;
	i = 0;
	while (to_power(2, pos) < values)
		pos++;
	set = set_settings(order, malloc(sizeof(int) * values), values, 0);
	set->moves = calloc(pos * values * 2, sizeof(int));
	while (i < pos)
		sort_stack(set, i++);
	set->moves[set->i] = 0;
	return (set->moves);
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
void	sort_stack(t_set *set, int pos)
{
	int	i;

	i = 0;
	while (i < set->len_a)
	{
		if ((set->a[0] >> pos) & 0x01)
			perform_moves(set, 3);
		else
			perform_moves(set, 2);
		i++;
	}
	while (set->len_b)
		perform_moves(set, 1);
	//free(set->b);
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

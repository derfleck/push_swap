/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:15:35 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/06 15:38:33 by mleitner         ###   ########.fr       */
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
	int	*b;

	b = malloc(sizeof(int) * values);
	pos = 0;
	i = 0;
	while (to_power(2, pos) < values)
		pos++;
	moves_temp = calloc(pos * values * 2, sizeof(int));
	moves_start = moves_temp;
	while (i < pos)
	{
		sort_stack(order, b, moves_temp, values, i++);
		while (*moves_temp)
			moves_temp++;
	}
	free(b);
	return (moves_start);
}

//perform radix sort on binary value
//stop = 0
//pa = 1
//pb = 2
//ra = 3
//rra = 4
//sa = 5
void	sort_stack(int *a, int *b, int *moves, int values, int pos)
{
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = values;
	len_b = 0;
	while (i < values)
	{
		if ((a[0] >> pos) & 0x01)
		{
			moves[i] = 3;
			rotate(a, len_a);
		}
		else
		{
			moves[i] = 2;
			push(a, b, --len_a, ++len_b);
		}
		i++;
	}
	while (len_b)
	{
		moves[i++] = 1;
		push(b, a, --len_b, ++len_a);
	}
	moves[i] = 0;
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
	while (len_dst > 1)
	{
		dst[len_dst - 1] = dst[len_dst - 2];
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

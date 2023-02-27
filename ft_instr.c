/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:15:50 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/27 16:16:33 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//performs reverse rotate on stack (last becomes first)
void	r_rotate(int *values, int len, int print)
{
	int	tmp;
	int	i;

	tmp = values[len - 1];
	i = len - 1;
	while (i)
	{
		*(values + i) = *(values + i - 1);
		i--;
	}
	*(values + i) = tmp;
	if (print == 1)
		write(1, &"rra\n", 4);
	else if (print == 2)
		write(1, &"rrb\n", 4);
}

//performs swap (sa/sb)
void	swap(int *a, int *b, int print)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	if (print == 1)
		write(1, &"sa\n", 3);
	if (print == 2)
		write(1, &"sb\n", 3);
}

//performs push (pa/pb)
void	push(int *src, int *dst, int len_src, int len_dst)
{
	int	i;

	i = len_dst;
	while (i)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = *src;
	while (i < len_src)
	{
		src[i] = src[i + 1];
		i++;
	}
}

//performs rotate (ra/rb)
void	rotate(int *values, int len, int print)
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
	if (print == 1)
		write(1, &"ra\n", 3);
	else if (print == 2)
		write(1, &"rb\n", 3);
}

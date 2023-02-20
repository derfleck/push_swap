/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:59:25 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/20 17:05:26 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_max(int *val, int num)
{
	int	i;
	int	max;

	i = 1;
	max = val[0];
	while (i < num)
	{
		if (val[i] > max)
			max = val[i];
		i++;
	}
	return (max);
}

int	find_min(int *val, int num)
{
	int	i;
	int	min;

	i = 1;
	min = val[0];
	while (i < num)
	{
		if (val[i] < min)
			min = val[i];
		i++;
	}
	return (min);
}

void	medium_sort(int *val, int num)
{
	int	*b;
	int	len_b;
	//int	max;
	//int	min;

	len_b = 0;
	b = malloc(sizeof(int) * (num - 3));
	//max = find_max(val, num);
	//min = find_min(val, num);
	while (len_b <= (num - 3))
	{
		push(&val[0], &b[0], num--, len_b++);
		write(1, &"pb\n", 3);
	}
	small_sort(val);
	if (b[1] > b[0] && len_b == 2)
	{
		swap(&b[0], &b[1]);
		write(1, &"sb\n", 3);
	}
	while (len_b)
	{
		if (b[0] == find_max(&b[0], len_b))
		{
			while (val[0] != find_min(val, num))
			{
				rotate(val, num);
				write(1, &"ra\n", 3);
			}
			push(b, val, len_b--, num++);
			write(1, &"pa\n", 3);
		}
		else
		{
			while (val[0] < b[0])
			{
				rotate(val, num);
				write(1, &"ra\n", 3);
			}
			push(b, val, len_b--, num++);
			write(1, &"pa\n", 3);
		}
	}
	free(b);
	while (val[0] != find_min(val, num))
	{
		rotate(val, num);
		write(1, &"ra\n", 3);
	}
}
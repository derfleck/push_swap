/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:04:59 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/20 17:27:54 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	r_rotate(int *values, int len)
{
	int	tmp;
	int	i;

	tmp = values[len - 1];
	i = len - 2;
	while (i)
	{
		*(values + i) = *(values + i - 1);
		i--;
	}
	*(values + i) = tmp;
}

void	small_sort(int *val)
{
	if (val[0] > val[1] && val[0] > val[2] && val[2] < val[1])
	{
		swap(&val[0], &val[2]);
		write(1, &"sa\nrra\n", 7);
	}
	else if (val[0] > val[1] && val[0] > val[2] && val[2] > val[1])
	{
		rotate(&val[0], 3);
		write(1, &"ra\n", 3);
	}
	else if (val[2] < val[0] && val[2] < val[1] && val[0] < val[1])
	{
		r_rotate(&val[0], 3);
		write(1, &"rra\n", 4);
	}
	else if (val[0] < val[1] && val[0] < val[2] && val[2] < val[1])
	{
		swap(&val[1], &val[2]);
		write(1, &"sa\nra\n", 6);
	}
	else if (val[2] > val[0] && val[2] > val[1] && val[0] > val[1])
	{
		swap(&val[0], &val[1]);
		write(1, &"sa\n", 3);
	}
}

int	*res_arr(t_value **arr, int argc)
{
	int	i;
	int	*val;

	i = 0;
	val = malloc(sizeof(int) * argc - 1);
	while (i < argc - 1)
	{
		val[i] = arr[i]->value;
		i++;
	}
	free_list(*arr, arr, NULL, NULL);
	return (val);
}

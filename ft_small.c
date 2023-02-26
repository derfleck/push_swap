/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:04:59 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/25 11:35:12 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	small_sort(int *val)
{
	int	max;
	int	min;

	max = find_max(val, 3);
	min = find_min(val, 3);
	if (val[1] == min && val[2] == max)
		swap(&val[0], &val[1], 1);
	else if (val[1] == max && val[2] == min)
		r_rotate(val, 3, 1);
	else if (val[0] == max && val[1] == min)
		rotate(val, 3, 1);
	else if (val[0] == max && val[2] == min)
	{
		swap(&val[0], &val[1], 1);
		r_rotate(val, 3, 1);
	}
	else if (val[0] == min && val[1] == max)
	{
		swap(&val[0], &val[1], 1);
		rotate(val, 3, 1);
	}
}

int	*res_arr(t_value **arr, int n)
{
	int	i;
	int	*val;

	i = 0;
	val = malloc(sizeof(int) * n);
	if (!val)
		return (NULL);
	while (i < n)
	{
		val[i] = arr[i]->value;
		i++;
	}
	free_list(*arr, arr, NULL, NULL);
	return (val);
}

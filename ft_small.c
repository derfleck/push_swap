/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:04:59 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/27 14:22:48 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//performs optimal sort on three values
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

/*
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
*/

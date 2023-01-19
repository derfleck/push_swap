/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:12:46 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/19 14:00:18 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_range(int *arr, int *range)
{
	int	i;

	i = 0;
	range[1] = arr[i];
	range[0] = arr[i++];
	while (arr[i])
	{
		if (arr[i] > range[1])
			range[1] = arr[i];
		if (arr[i] < range[0])
			range[0] = arr[i];
		i++;
	}
	return (range[1] - range[0]);
}

int	values(int num)
{
	int	val;

	val = 0;
	while (num > 0)
	{
		num /= 10;
		val++;
	}
	return (val);
}

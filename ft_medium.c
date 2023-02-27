/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:59:25 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/27 19:02:43 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//searches for max value in int array
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

//searches for min value in int array
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

//checks if int array is sorted (ascending)
int	arr_sorted(int *arr, int num)
{
	int	i;

	i = 1;
	while (i < num)
	{
		if (arr[i - 1] > arr[i])
			return (0);
		i++;
	}
	return (1);
}

//sorts stacks a and b for medium sort
void	medium_sort_helper(int *a, int *b, int len_a, int len_b)
{
	while (len_b)
	{
		if (b[0] < find_min(a, len_a) || b[0] > find_max(a, len_a))
		{
			while (a[0] != find_min(a, len_a))
				rotate(a, len_a, 1);
		}
		else
		{
			while (a[0] < b[0])
				rotate(a, len_a, 1);
		}
		push(b, a, --len_b, len_a++);
		write(1, &"pa\n", 3);
	}
	while (a[0] != find_min(a, len_a))
		rotate(a, len_a, 1);
}

//performs sort for stack of 4 to 5 values
void	medium_sort(int *val, int num)
{
	int	*b;
	int	len_b;

	len_b = 0;
	b = malloc(sizeof(int) * (num - 3));
	while (num > 3)
	{
		push(val, b, --num, len_b++);
		write(1, &"pb\n", 3);
	}
	if (!arr_sorted(val, num))
		small_sort(val);
	if (len_b == 2)
	{
		if (b[1] < b[0])
			swap(&b[0], &b[1], 2);
	}
	medium_sort_helper(val, b, num, len_b);
	free(b);
}

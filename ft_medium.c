/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:59:25 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/23 20:01:15 by mleitner         ###   ########.fr       */
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

void	print_stack(int *arr, int num, char stk)
{
	int	i;

	i = 0;
	printf("Stack %c: ", stk);
	while (i < num)
		printf("%i ", arr[i++]);
	printf("\n");
}

void	medium_sort(int *val, int num)
{
	int	*b;
	int	len_b;

	len_b = 0;
	b = malloc(sizeof(int) * (num - 3));
	while (num > 3)
	{
		push(&val[0], &b[0], num--, len_b++);
		write(1, &"pb\n", 3);
	}
	if (!arr_sorted(val, num))
		small_sort(val);
	if (b[1] < b[0] && len_b == 2)
		swap(&b[0], &b[1], 2);
	while (len_b)
	{
		if (b[0] < find_min(val, num) || b[0] > find_max(val, num))
		{
			while (val[0] != find_min(val, num))
				rotate(val, num, 1);
		}
		else
		{
			while (val[0] < b[0])
				rotate(val, num, 1);
		}
		push(b, val, len_b--, num++);
		write(1, &"pa\n", 3);
	}
	free(b);
	while (val[0] != find_min(val, num))
		rotate(val, num, 1);
}

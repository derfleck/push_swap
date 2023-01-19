/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:35 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/19 12:51:06 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort(int *begin, int *end)
{
	int	*ptr;
	int	*split;

	if (end - begin < 1)
		return ;
	ptr = begin;
	split = begin + 1;
	while (++ptr <= end)
	{
		if (*ptr < *begin)
		{
			swap(ptr, split);
			++split;
		}
	}
	swap(begin, split - 1);
	quicksort(begin, split - 1);
	quicksort(split, end);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*arr;
	int	*ord_bef;
	int	*ord_aft;

	i = 0;
	arr = malloc((argc - 1) * sizeof(int));
	ord_bef = malloc((argc - 1) * sizeof(int));
	ord_aft = malloc((argc - 1) * sizeof(int));
	if (argc == 1 || !arr)
		return (0);
	while (argv[i + 1])
	{
		arr[i] = atoi(argv[i + 1]);
		ord_bef[i] = i;
		i++;
	}
	i = 0;
	printf("Unsorted: ");
	while (i < (argc - 1))
	{
		printf("%i ", arr[i]);
		i++;
	}
	quicksort(arr, arr + argc - 2);
	i = 0;
	printf("Sorted: ");
	while (i < (argc - 1))
	{
		printf("%i ", arr[i]);
		i++;
	}
	return (0);
}

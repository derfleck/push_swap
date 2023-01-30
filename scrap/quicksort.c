/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:35 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/30 20:12:11 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

//prints current values on a and b stack
void	print_stack(int *a, int *b, int len_a, int len_b)
{
	int	i;

	i = 0;
	printf("a: ");
	while (i < len_a)
		printf("%i ", a[i++]);
	printf("\nb: ");
	i = 0;
	while (i < len_b)
		printf("%i ", b[i++]);
	printf("\n");
}

//helper for printing value, pos_sor and pos_uns
void	showvalue(t_value **arr)
{
	t_value	*lst;

	lst = *arr;
	while (lst != NULL)
	{
		printf("%i ", lst->value);
		lst = lst->next;
	}
	lst = *arr;
	printf("\n");
	while (lst != NULL)
	{
		printf("%i ", lst->pos_sor);
		lst = lst->next;
	}
	lst = *arr;
	printf("\n");
	while (lst != NULL)
	{
		printf("%i ", lst->pos_uns);
		lst = lst->next;
	}
	printf("\n");
}

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

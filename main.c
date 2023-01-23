/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/23 00:41:36 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//math helper, performs to the power
//used to convert binary to decimal
//also used to calculate number of binary values
int	to_power(int nb, int power)
{
	if (!power)
		return (1);
	else
	{
		power--;
		return ((nb * to_power(nb, power)));
	}
}

//helper for printing value, pos_sor and pos_uns
void	showvalue(t_value **arr, int values)
{
	int	i;

	i = 0;
	while (i < values)
		printf("%i ", arr[i++]->value);
	i = 0;
	printf("\n");
	while (i < values)
		printf("%i ", arr[i++]->pos_sor);
	i = 0;
	printf("\n");
	while (i < values)
		printf("%i ", arr[i++]->pos_uns);
	printf("\n");
}

//helper function, just assigns values from src to dst
void	list_ass(t_value *src, t_value *dst)
{
	dst->pos_sor = src->pos_sor;
	dst->pos_uns = src->pos_uns;
	dst->sorted = src->sorted;
	dst->value = src->value;
	dst->str = src->str;
}

//swaps node values, but keeps actual structure intact
void	swap_nodes(t_value	*src, t_value *dst)
{
	t_value	*tmp;

	if (!src || !dst)
		return ;
	tmp = ft_lstnew(NULL, dst->str, dst->pos_uns);
	list_ass(src, dst);
	list_ass(tmp, src);
	free(tmp);
}

//partitions linked list
//also performs quicksort swap if value smaller than pivot value
t_value	*partition(t_value *first, t_value *last)
{
	t_value	*store;
	t_value	*pivot;

	store = first;
	pivot = first;
	while (store != NULL && store != last)
	{
		if (store->value < last-> value)
		{
			pivot = first;
			swap_nodes(first, store);
			first = first->next;
		}
		store = store->next;
	}
	swap_nodes(first, last);
	return (pivot);
}

//performs quicksort on linked list
void	quicksort_list(t_value *first, t_value *last)
{
	t_value	*pivot;

	if (first == last)
		return ;
	pivot = partition(first, last);
	if (pivot != NULL && pivot->next != NULL)
		quicksort_list(pivot->next, last);
	if (pivot != NULL && first != pivot)
		quicksort_list(first, pivot);
}

//relabels the pos_sor field to new sorting
void	relabel(t_value *lst)
{
	t_value	*lst2;
	int		i;

	lst2 = lst;
	i = 0;
	while (lst2)
	{
		lst2->pos_sor = i++;
		lst2 = lst2->next;
	}
}

//writes original order to integer array
int	*sort_array(t_value *arr, int values)
{
	t_value	*lst2;
	int		*sort;

	sort = malloc(sizeof(int) * values);
	if (!sort)
		return (NULL);
	lst2 = arr;
	while (lst2)
	{
		sort[lst2->pos_uns] = lst2->pos_sor;
		lst2 = lst2->next;
	}
	return (sort);
}

//performs swap (sa/sb)
void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//performs push (pa/pb)
void	push(int *src, int *dst, int len_src, int len_dst)
{
	int	i;

	i = 0;
	while (i < len_dst)
	{
		dst[i + 1] = dst[i];
		i++;
	}
	dst[0] = *src;
	i = 0;
	while (i < len_src)
	{
		src[i] = src[i + 1];
		i++;
	}
}

//performs rotate (ra/rb)
void	rotate(int *values, int len)
{
	int	tmp;
	int	i;

	tmp = values[0];
	i = 0;
	while (i < len)
	{
		values[i] = values[i + 1];
		i++;
	}
	values[len - 1] = tmp;
}

//perform radix sort on binary value
void	sort_stack(int *a, int *b, int *moves, int values, int pos)
{
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = values;
	len_b = 0;
	while (i < values)
	{
		if (a[i] >> pos & 0x01)
		{
			moves[i] = 2;
			push(a, b, len_a--, len_b++);
		}
		else
		{
			moves[i] = 3;
			rotate(a, len_a);
		}
		i++;
	}
	while (len_b)
	{
		moves[i++] = 1;
		push(b, a, len_a++, len_b--);
	}
	moves[i] = 0;
	printf("%i: %i\n", i, moves[i]);
}
/*
stop = 0;
pa = 1;
pb = 2;
ra = 3;
*/

//initializes the moves array and calls sort_stack function
int	*calc_moves(int *order, int values)
{
	int	pos;
	int	i;
	int	*moves;
	int	*a;
	int	*b;

	a = order;
	b = malloc(sizeof(int) * values);
	pos = 0;
	i = 0;
	while (to_power(2, pos) < values)
		pos++;
	moves = calloc(pos * values * 2, sizeof(int));
	while (i < pos)
	{
		sort_stack(a, b, moves, values, i++);
		while (*moves)
			moves++;
	}
	return (moves);
}

int	main(int argc, char **argv)
{
	t_value	**arr;
	int		i;
	int		*sort;
	int		*moves;

	i = 0;
	arr = malloc((argc - 1) * sizeof(t_value *));
	while (argv[i + 1])
	{
		if (i == 0)
			arr[i] = ft_lstnew(NULL, argv[i + 1], i);
		else
			arr[i] = ft_lstnew(arr[i - 1], argv[i + 1], i);
		i++;
	}
	showvalue(arr, argc - 1);
	quicksort_list(*arr, ft_lstlast(*arr));
	relabel(*arr);
	sort = sort_array(*arr, argc - 1);
	moves = calc_moves(sort, argc - 1);
	i = 0;
	while (moves[i])
		printf("%i ", moves[i++]);
	//while (i < argc - 1)
	//	printf("%i ", sort[i++]);
	return (0);
}

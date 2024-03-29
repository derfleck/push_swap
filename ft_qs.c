/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:06:19 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/27 14:40:12 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//swaps node values, but keeps actual structure intact
void	swap_nodes(t_value	*src, t_value *dst)
{
	t_value	*tmp;

	if (!src || !dst || src == dst)
		return ;
	tmp = ft_lstnew(NULL, src->value, src->pos_uns);
	list_ass(dst, src);
	list_ass(tmp, dst);
	free(tmp);
}

//partitions linked list
//performs quicksort swap if value smaller than pivot value
t_value	*partition(t_value *first, t_value *last)
{
	t_value	*store;
	t_value	*pivot;

	store = first;
	pivot = first;
	while (store != NULL && store != last)
	{
		if (store->value < last->value)
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

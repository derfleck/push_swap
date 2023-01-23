/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:12:25 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/20 16:15:04 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_value	*ft_lstnew(t_value *prev, char *str, int sort)
{
	t_value	*node;

	node = malloc(sizeof(t_value));
	if (!node)
		return (NULL);
	if (prev != NULL)
		prev->next = node;
	node->str = str;
	node->value = atoi(str);
	node->pos_sor = 0;
	node->pos_uns = sort;
	node->sorted = 0;
	node->next = NULL;
	return (node);
}

t_value	*ft_lstlast(t_value *lst)
{
	t_value	*lst2;

	if (!lst)
		return ((t_value *)lst);
	lst2 = (t_value *)lst;
	while (lst2->next)
	{
		lst2 = lst2->next;
	}
	return (lst2);
}

int	*ft_lstmax(t_value *lst)
{
	int		*arr;
	t_value	*lst2;

	arr = malloc(2 * sizeof(int));
	if (!lst || !arr)
		return (NULL);
	lst2 = (t_value *)lst;
	arr[1] = lst2->value;
	arr[0] = lst2->value;
	while (lst2)
	{
		if (lst2->value > arr[1])
			arr[1] = lst2->value;
		if (lst2->value < arr[0])
			arr[0] = lst2->value;
		lst2 = lst2->next;
	}
	return (arr);
}

void	splitlist(t_value *original, t_value **half1, t_value **half2)
{
	t_value	*fast;
	t_value	*slow;

	slow = original;
	fast = original->next;

	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*half1 = original;
	*half2 = slow->next;
	slow->next = NULL;
}

void	mergesortlist(t_value **list)
{
	t_value	*start;
	t_value	*a;
	t_value	*b;

	start = *list;
	if (start == NULL || start->next == NULL)
		return ;
	splitlist(start, &a, &b);
	mergesortlist(&a);
	mergesortlist(&b);
	*list = createmerge(a, b);
}

t_value	*createmerge(t_value *a, t_value *b)
{
	t_value	*res;

	res = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->value <= b->value)
	{
		res = a;
		res->next = createmerge(a->next, b);
	}
	else
	{
		res = b;
		res->next = createmerge(a, b->next);
	}
	return (res);
}

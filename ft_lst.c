/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:12:25 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/30 20:01:37 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//create new node of linked list
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

//gets last element of linked list
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

//helper function, just assigns values from src to dst
void	list_ass(t_value *src, t_value *dst)
{
	dst->pos_sor = src->pos_sor;
	dst->pos_uns = src->pos_uns;
	dst->sorted = src->sorted;
	dst->value = src->value;
	dst->str = src->str;
}

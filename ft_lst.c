/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:12:25 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/27 14:39:04 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//create new node of linked list (without atoi conversion)
t_value	*ft_lstnew(t_value *prev, int value, int sort)
{
	t_value	*node;

	node = malloc(sizeof(t_value));
	if (!node)
		return (NULL);
	if (prev != NULL)
		prev->next = node;
	node->value = value;
	node->pos_sor = 0;
	node->pos_uns = sort;
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

//assigns values from src to dst
void	list_ass(t_value *src, t_value *dst)
{
	dst->pos_sor = src->pos_sor;
	dst->pos_uns = src->pos_uns;
	dst->value = src->value;
}

//frees list node by node
void	free_list(t_value *head, void *ptr1, void *ptr2, void *ptr3)
{
	t_value	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(ptr1);
	free(ptr2);
	free(ptr3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:12:25 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/17 20:09:51 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_value	*ft_lstnew(char *str, int sort)
{
	t_value	*node;

	node = malloc(sizeof(t_value));
	if (!node)
		return (NULL);
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

void	ft_lstadd_back(t_value **lst, t_value *new)
{
	t_value	*end;

	if (*lst == NULL)
		*lst = new;
	else
	{
		end = ft_lstlast(*lst);
		end->next = new;
		new->next = NULL;
	}
}
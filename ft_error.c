/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:01 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/06 15:19:28 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	error_check(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (ft_isspace(args[i][j]))
			j++;
		if (args[i][j] == '-')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				error(NULL);
			j++;
		}
		if (ft_atoi(args[i]) > 2147483648 || ft_atoi(args[i]) < -2147483648)
			error(NULL);
		i++;
	}
}

void	lst_check(t_value *lst)
{
	if (is_sorted(lst) || is_duplicate(lst))
		error(lst);
}

void	error(t_value *lst)
{
	write(1, &"Error\n", 6);
	free_list(lst, NULL, NULL, NULL);
	exit(0);
}

int	is_duplicate(t_value *lst)
{
	t_value	*tmp;

	tmp = lst->next;
	while (lst != NULL)
	{
		tmp = lst->next;
		while (tmp != NULL)
		{
			if (lst->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	is_sorted(t_value *lst)
{
	t_value	*tmp;
	int		val;

	tmp = lst->next;
	val = lst->value;
	while (tmp != NULL && tmp->value > val)
	{
		if (tmp->next == NULL)
			return (1);
		val = tmp->value;
		tmp->sorted = 1;
		tmp = tmp->next;
	}
	return (0);
}

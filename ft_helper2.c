/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:48:23 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/01 13:58:42 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_sorted(t_value *lst)
{
	t_value	*tmp;
	int		val;

	tmp = lst->next;
	val = lst->value;
	while (tmp != NULL)
	{
		if (tmp->value < val)
			return (0);
		val = tmp->value;
		tmp->sorted = 1;
		tmp = tmp->next;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		pre;
	long	value;

	i = 0;
	pre = 1;
	value = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		pre = -pre;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]) && nptr[i] != '\0')
	{
		value = value * 10;
		value = value + (nptr[i] - 48);
		i++;
		if (value * pre > 2147483648)
			return (-1);
		else if (value * pre < -2147483648)
			return (0);
	}
	return ((int)value * pre);
}

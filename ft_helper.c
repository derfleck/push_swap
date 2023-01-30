/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:12:46 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/30 20:20:28 by mleitner         ###   ########.fr       */
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

//function for printing the instructions from the int array
void	print_instr(int *moves)
{
	while (*moves)
	{
		if (*moves == 1)
			write(1, &"pa\n", 3);
		else if (*moves == 2)
			write(1, &"pb\n", 3);
		else if (*moves == 3)
			write(1, &"ra\n", 3);
		moves++;
	}
}

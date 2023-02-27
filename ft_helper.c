/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:12:46 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/27 14:41:48 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//performs to the power
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

//writes original order from linked list to integer array
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
		else if (*moves == 4)
			write(1, &"rb\n", 3);
		moves++;
	}
}

//recreates calloc
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	val;

	val = nmemb * size;
	if (nmemb != 0 && val / nmemb != size)
		return (NULL);
	ptr = malloc(val);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, val);
	return ((void *)ptr);
}

//fills array with null characters
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

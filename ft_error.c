/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:01 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/26 12:29:24 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//checks if arguments contain illegal characters
void	ill_chr(char **str, int n)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < n)
	{
		while (str[i][j])
		{
			while (ft_isspace(str[i][j]))
				j++;
			if (str[i][j] == '-')
				j++;
			if (!ft_isdigit(str[i][j]))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			while (ft_isdigit(str[i][j]))
				j++;
		}
		i++;
		j = 0;
	}
}

//deletes splitted arguments
void	empty_args(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(str[i++]);
	free(str);
}

//checks if arguments are sorted
void	is_sorted(char **split, int n)
{
	int	i;
	int	sorted;

	i = 1;
	sorted = 1;
	while (i < n)
	{
		if (!(ft_atoi(split[i]) > ft_atoi(split[i - 1]) && sorted == 1))
			sorted = 0;
		i++;
	}
	if (sorted == 1)
	{
		empty_args(split, n);
		exit(1);
	}
}

//checks if arguments contain duplicates
void	is_duplicate(char **split, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while ((i + 1) < n)
	{
		tmp = ft_atoi(split[i]);
		j = i + 1;
		while (j < n)
		{
			if (ft_atoi(split[j]) == tmp)
			{
				write(1, "Error\n", 6);
				empty_args(split, n);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

//checks if argument is outside of int range
void	range_chk(char **split, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (ft_atoi(split[i]) >= 2147483648 || ft_atoi(split[i]) < -2147483648)
		{
			write(1, "Error\n", 6);
			empty_args(split, n);
			exit(1);
		}	
		i++;
	}
	is_sorted(split, n);
	is_duplicate(split, n);
}

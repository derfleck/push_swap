/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:01 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/20 17:35:36 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//checks if arguments contain illegal characters
void	ill_chr(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
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

void	empty_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	is_sorted(char **split)
{
	int	i;
	int	sorted;

	i = 1;
	sorted = 1;
	while (split[i])
	{
		if (!(ft_atoi(split[i]) > ft_atoi(split[i - 1]) && sorted == 1))
			sorted = 0;
		i++;
	}
	if (sorted == 1)
	{
		empty_args(split);
		exit(1);
	}
}

void	is_duplicate(char **split)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (split[i])
	{
		if (!(split[i + 1]))
			return ;
		tmp = ft_atoi(split[i]);
		j = i + 1;
		while (split[j])
		{
			if (ft_atoi(split[j]) == tmp)
			{
				write(1, "Error\n", 6);
				empty_args(split);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	range_chk(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (ft_atoi(split[i]) >= 2147483648 || ft_atoi(split[i]) < -2147483648)
		{
			write(1, "Error\n", 6);
			empty_args(split);
			exit(1);
		}	
		i++;
	}
	is_sorted(split);
	is_duplicate(split);
}

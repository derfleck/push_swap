/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/17 20:13:27 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int	*arr;
	int	i;

	i = 1;
	arr = malloc((argc - 1) * sizeof(int));
	while (argv[i])
	{
		arr[i - 1] = atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < (argc - 1))
		printf("%i ", arr[i++]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_value	*arr;
	int		i;

	i = 1;
	while (argv[i])
	{
		arr = ft_lstnew(argv[i], i - 1);
		i++;
	}
	i = 0;
	while (i < (argc - 1))
		printf("%i ", arr[i++]);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/19 15:43:21 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
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
*/

int	main(int argc, char **argv)
{
	t_value	**arr;
	int		i;

	i = 1;
	arr = malloc((argc - 1) * sizeof(t_value *));
	while (argv[i])
	{
		if (i == 1)
			arr[0] = ft_lstnew(NULL, argv[i], i);
		else
			arr[i - 1] = ft_lstnew(arr[i - 2], argv[i], i);
		i++;
	}
	i = 0;
	while (i < (argc - 1))
		printf("%i ", arr[i++]->value);
	//int *range = ft_lstmax(arr[0]);
	//printf("\nmax: %i min: %i", range[1], range[0]);
	mergesortlist(arr);
	i = 0;
	printf("\n");
	while (i < (argc - 1))
		printf("%i ", arr[i++]->value);
	return (0);
}

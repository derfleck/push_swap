/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/06 15:20:28 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//TODO: - Documentation
// - Error handling (no strings)
// - check out bonus
// - implement check for sorted/small ranges
// - check for memory leaks
// - replace atoi with ft_atoi

t_value	**arg_check(int argc, char **argv)
{
	int		i;
	t_value	**arr;

	if (argc < 2)
		return (NULL);
	i = 0;
	error_check(argv);
	arr = malloc((argc - 1) * sizeof(t_value *));
	if (!arr)
		return (NULL);
	while (argv[i + 1])
	{
		if (i == 0)
			arr[i] = ft_lstnew(NULL, argv[i + 1], i);
		else
			arr[i] = ft_lstnew(arr[i - 1], argv[i + 1], i);
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	t_value	**arr;
	int		i;
	int		*sort;
	int		*moves;

	i = 0;
	arr = arg_check(argc, argv);
	if (arr == NULL)
		return (0);
	lst_check(*arr);
	quicksort_list(*arr, ft_lstlast(*arr));
	relabel(*arr);
	sort = sort_array(*arr, argc - 1);
	moves = calc_moves(sort, argc - 1);
	print_instr(moves);
	free_list(*arr, moves, sort, arr);
	return (0);
}

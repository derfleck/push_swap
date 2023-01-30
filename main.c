/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/30 20:23:59 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//TODO: - Documentation
// - Error handling (no strings)
// - shorten functions in ft_rdx
// - check out bonus
// - implement check for sorted/small ranges

int	main(int argc, char **argv)
{
	t_value	**arr;
	int		i;
	int		*sort;
	int		*moves;

	i = 0;
	arr = malloc((argc - 1) * sizeof(t_value *));
	while (argv[i + 1])
	{
		if (i == 0)
			arr[i] = ft_lstnew(NULL, argv[i + 1], i);
		else
			arr[i] = ft_lstnew(arr[i - 1], argv[i + 1], i);
		i++;
	}
	quicksort_list(*arr, ft_lstlast(*arr));
	relabel(*arr);
	sort = sort_array(*arr, argc - 1);
	moves = calc_moves(sort, argc - 1);
	print_instr(moves);
	return (0);
}

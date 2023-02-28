/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/28 13:22:14 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//TODO: - Documentation
// - check for memory leaks
// - restructure (no linked list for short/medium sort)

//checks arguments, splits them and writes them to int array
int	*arg_check(int n, char **argv, int argc)
{
	int		i;
	char	**split;
	int		*arr;

	i = 0;
	ill_chr(argv, argc);
	if (n == 1)
		exit(1);
	split = ft_split(argv, 32);
	range_chk(split, n);
	arr = malloc(n * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < n)
	{
		arr[i] = ft_atoi(split[i]);
		i++;
	}
	empty_args(split, n);
	return (arr);
}

//creates linked list, performs quicksort, radix and prints instructions
void	big_sort(int *arr, int n)
{
	int		*sort;
	int		*moves;
	t_value	**llst;
	int		i;

	i = 0;
	llst = malloc(sizeof(t_value *) * n);
	while (i < n)
	{
		if (i == 0)
			llst[i] = ft_lstnew(NULL, arr[i], i);
		else
			llst[i] = ft_lstnew(llst[i - 1], arr[i], i);
		i++;
	}
	quicksort_list(*llst, ft_lstlast(*llst));
	relabel(*llst);
	sort = sort_array(*llst, n);
	moves = calc_moves(sort, n);
	print_instr(moves);
	free_list(*llst, moves, sort, llst);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		n;

	if (argc < 2)
		return (0);
	n = ft_cntwrds(argv, 32);
	arr = arg_check(n, argv, argc);
	if (arr == NULL)
		return (0);
	if (n == 2)
		write(1, &"sa\n", 3);
	else if (n >= 3 && n <= 5)
	{
		if (n == 3)
			small_sort(arr);
		else
			medium_sort(arr, n);
	}
	else
		big_sort(arr, n);
	free(arr);
	return (0);
}

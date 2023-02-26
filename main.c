/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/26 15:58:22 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//TODO: - Documentation
// - check for memory leaks
// - restructure (no linked list for short/medium sort)

int	*arg_check(int n, char **argv)
{
	int		i;
	char	**split;
	int		*arr;

	i = 0;
	ill_chr(argv, n);
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

/* 
int	*arg_check(int n, char **argv)
{
	int		i;
	char	**split;
	int		*arr;

	i = 0;
	ill_chr(argv);
	if (n < 2)
		exit(1);
	split = ft_split(argv, 32);
	range_chk(split);
	arr = malloc(n * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < n)
	{
		arr[i] = ft_atoi(split[i]);
		i++;
	}
} */

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
	free_list(*llst, moves, sort, arr);
	free(llst);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		n;
	//int		*moves;

	if (argc < 2)
		return (0);
	n = ft_cntwrds(argv, 32);
	arr = arg_check(n, argv);
	if (arr == NULL)
		return (0);
	if (n == 2)
	{
		write(1, &"sa\n", 3);
	}
	else if (n >= 3 && n <= 5)
	{
		//moves = res_arr(arr, n);
		if (n == 3)
			small_sort(arr);
		else
			medium_sort(arr, n);
		free(arr);
	}
	else
		big_sort(arr, n);
	return (0);
}

/*
for 3:
if first == max && last == min
	sa, rra
if first == max && last != min
	ra
if first != max && last == min
	rra
if first == min && last != max
	sa, ra
if first != min && last == max 
	sa

	
for 5:
always first pb, pb, then use for 3 on stack a

then:
if b != max && b (not empty)
	if a < b
		ra
	else
		pa
else if b == max && b (not empty)
	if a != min
		ra
	else
		pa, ra
else if !b && a != min
	ra
*/

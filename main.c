/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/24 12:10:32 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//TODO: - Documentation
// - check for memory leaks

t_value	**arg_check(int n, char **argv)
{
	int		i;
	char	**split;
	t_value	**arr;

	i = 0;
	ill_chr(argv);
	if (n == 1)
		exit(1);
	split = ft_split(argv, 32);
	range_chk(split);
	arr = malloc(n * sizeof(t_value *));
	if (!arr)
		return (NULL);
	while (i < n)
	{
		if (i == 0)
			arr[i] = ft_lstnew(NULL, split[i], i);
		else
			arr[i] = ft_lstnew(arr[i - 1], split[i], i);
		i++;
	}
	free(split[i]);
	return (arr);
}

void	big_sort(t_value **arr, int n)
{
	int	*sort;
	int	*moves;

	quicksort_list(*arr, ft_lstlast(*arr));
	relabel(*arr);
	sort = sort_array(*arr, n);
	moves = calc_moves(sort, n);
	print_instr(moves);
	free_list(*arr, moves, sort, arr);
}

int	main(int argc, char **argv)
{
	t_value	**arr;
	int		n;
	int		*moves;

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
		moves = res_arr(arr, n);
		if (n == 3)
			small_sort(moves);
		else
			medium_sort(moves, n);
		free(moves);
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

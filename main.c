/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/20 17:30:47 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//TODO: - Documentation
// - Error handling (no strings)
// - check out bonus
// - implement check for sorted/small ranges
// - check for memory leaks
// - replace calloc

t_value	**arg_check(int argc, char **argv)
{
	int		i;
	char	**split;
	t_value	**arr;

	if (argc < 2)
		exit(1);
	i = 0;
	ill_chr(argv);
	split = ft_split(argv, 32);
	range_chk(split);
	arr = malloc((ft_cntwrds(argv, 32)) * sizeof(t_value *));
	if (!arr)
		return (NULL);
	while (i < ft_cntwrds(argv, 32))
	{
		if (i == 0)
			arr[i] = ft_lstnew(NULL, split[i], i);
		else
			arr[i] = ft_lstnew(arr[i - 1], split[i], i);
		i++;
	}
	empty_args(split);
	return (arr);
}

/*
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
	while (i < argc - 1)
	{
		if (i == 0)
			arr[i] = ft_lstnew(NULL, argv[i + 1], i);
		else
			arr[i] = ft_lstnew(arr[i - 1], argv[i + 1], i);
		i++;
	}
	return (arr);
}
*/

void	big_sort(t_value **arr, int argc)
{
	int	*sort;
	int	*moves;

	//lst_check(arr);
	quicksort_list(*arr, ft_lstlast(*arr));
	relabel(*arr);
	sort = sort_array(*arr, argc - 1);
	moves = calc_moves(sort, argc - 1);
	print_instr(moves);
	free_list(*arr, moves, sort, arr);
}

int	main(int argc, char **argv)
{
	t_value	**arr;
	int		i;
	int		*moves;

	i = 0;
	arr = arg_check(argc, argv);
	if (arr == NULL)
		return (0);
	if (argc == 3)
	{
		write(1, &"sa\n", 3);
	}
	else if (argc > 3 && argc <= 6)
	{
		moves = res_arr(arr, argc);
		if (argc == 4)
			small_sort(moves);
		else
			medium_sort(moves, argc - 1);
		free(moves);
	}
	else
		big_sort(arr, argc);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	t_value	**arr;
	int		i;
	int		*moves;

	i = 0;
	arr = arg_check(argc, argv);
	if (arr == NULL)
		return (0);
	if (argc >= 3 && argc <= 6)
	{
		moves = res_arr(arr, argc);
		if (argc == 4)
			small_sort(moves);
		else
			medium_sort(moves, argc - 1);
		free(moves);
	}
	else
		big_sort(arr, argc);
	return (0);
}
*/

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

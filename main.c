/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:06:20 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/07 17:08:46 by mleitner         ###   ########.fr       */
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

void	big_sort(t_value **arr, int argc)
{
	int	*sort;
	int	*moves;

	lst_check(arr);
	quicksort_list(*arr, ft_lstlast(*arr));
	relabel(*arr);
	sort = sort_array(*arr, argc - 1);
	moves = calc_moves(sort, argc - 1);
	print_instr(moves);
	free_list(*arr, moves, sort, arr);
}

int	find_max(int *val, int num)
{
	int	i;
	int	max;

	i = 1;
	max = val[0];
	while (i < num)
	{
		if (val[i] > max)
			max = val[i];
		i++;
	}
	return (max);
}

int	find_min(int *val, int num)
{
	int	i;
	int	min;

	i = 1;
	min = val[0];
	while (i < num)
	{
		if (val[i] < min)
			min = val[i];
		i++;
	}
	return (min);
}

void	medium_sort(int *val, int num)
{
	int	*b;
	int	len_b;
	int	max;
	int	min;

	len_b = 0;
	b = malloc(sizeof(int) * (num - 3));
	max = find_max(val, num);
	min = find_min(val, num);
	while (len_b <= (num - 3))
	{
		push(&val[0], &b[0], num--, len_b++);
		write(1, &"pb\n", 3);
	}
	small_sort(val);
	if (b[1] > b[0] && len_b == 2)
	{
		swap(&b[0], &b[1]);
		write(1, &"sb\n", 3);
	}
	while (len_b)
	{
		if (b[0] == max)
		{
			while (val[0] != min)
			{
				rotate(val, num);
				write(1, &"ra\n", 3);
			}
			push(b, val, len_b--, num++);
			write(1, &"pa\n", 3);
		}
		else
		{
			while (val[0] < b[0])
			{
				rotate(val, num);
				write(1, &"ra\n", 3);
			}
			push(b, val, len_b--, num++);
			write(1, &"pa\n", 3);
		}
	}
	free(b);
	while (val[0] != min)
	{
		printf("val: %i", val[0]);
		rotate(val, num);
		write(1, &"ra\n", 3);
	}
}

int	main(int argc, char **argv)
{
	t_value	**arr;
	int		i;
	//int		*sort;
	int		*moves;

	i = 0;
	arr = arg_check(argc, argv);
	if (arr == NULL)
		return (0);
	if (argc >= 4 && argc <= 6)
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

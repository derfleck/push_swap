/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:30:10 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/27 16:25:48 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//initializes settings struct and stores stack values
t_set	*set_settings(int *a, int *b, int len_a, int len_b)
{
	t_set	*set;

	set = malloc(sizeof(t_set));
	set->a = a;
	set->b = b;
	set->len_a = len_a;
	set->len_b = len_b;
	set->i = 0;
	return (set);
}

//checks which move to perform
void	perform_moves(t_set	*set, int step)
{
	if (step == 1)
	{
		set->moves[set->i++] = 1;
		push(set->b, set->a, --(set->len_b), set->len_a++);
	}
	else if (step == 2)
	{
		set->moves[set->i++] = 2;
		push(set->a, set->b, --(set->len_a), set->len_b++);
	}
	else if (step == 3)
	{
		set->moves[set->i++] = 3;
		rotate(set->a, set->len_a, 0);
	}
	else if (step == 4)
	{
		set->moves[set->i++] = 4;
		rotate(set->b, set->len_b, 0);
	}
}

//checks if both stacks are sorted
int	lists_sorted(t_set *set)
{
	int	i;
	int	sorted;

	i = 1;
	sorted = 1;
	while (i < set->len_a && set->len_a > 1 && sorted)
	{
		if (set->a[i - 1] > set->a[i])
			sorted = 0;
		i++;
	}
	i = 1;
	while (i < set->len_b && set->len_b > 1 && sorted)
	{
		if (set->b[i - 1] < set->b[i])
			sorted = 0;
		i++;
	}
	return (sorted);
}

//initializes the moves array and calls sort_stack function
int	*calc_moves(int *order, int values)
{
	int		pos;
	int		i;
	t_set	*set;
	int		*moves;

	pos = 0;
	i = 0;
	while (to_power(2, pos) < values)
		pos++;
	set = set_settings(order, malloc(sizeof(int) * values), values, 0);
	set->moves = ft_calloc(pos * values * 2, sizeof(int));
	while (i < pos && !lists_sorted(set))
		sort_stack(set, i++);
	while (set->len_b)
		perform_moves(set, 1);
	set->moves[set->i] = 0;
	moves = set->moves;
	free(set->b);
	free(set);
	return (moves);
}

//perform radix sort on binary value
//stop = 0
//pa = 1
//pb = 2
//ra = 3
//rb = 4
void	sort_stack(t_set *set, int pos)
{
	int	i;

	i = set->len_a;
	while (i && !lists_sorted(set))
	{
		if ((set->a[0] >> pos) & 0x01)
			perform_moves(set, 3);
		else
			perform_moves(set, 2);
		i--;
	}
	i = set->len_b;
	while (i && !lists_sorted(set))
	{
		if ((set->b[0] >> (pos + 1)) & 0x01)
			perform_moves(set, 1);
		else
			perform_moves(set, 4);
		i--;
	}
}

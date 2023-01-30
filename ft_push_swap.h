/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:03:19 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/30 20:21:10 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_value {
	int				value;
	char			*str;
	int				pos_sor;
	int				pos_uns;
	int				sorted;
	struct s_value	*next;
}	t_value;

//list functions
t_value	*ft_lstnew(t_value *prev, char *str, int sort);
t_value	*ft_lstlast(t_value *lst);
void	list_ass(t_value *src, t_value *dst);

//quicksort
void	swap_nodes(t_value	*src, t_value *dst);
t_value	*partition(t_value *first, t_value *last);
void	quicksort_list(t_value *first, t_value *last);
void	relabel(t_value *lst);

//radix sort
int		*calc_moves(int *order, int values);
void	sort_stack(int *a, int *b, int *moves, int values, int pos);
void	swap(int *a, int *b);
void	push(int *src, int *dst, int len_src, int len_dst);
void	rotate(int *values, int len);

//helper
int		to_power(int nb, int power);
int		*sort_array(t_value *arr, int values);
void	print_instr(int *moves);

#endif
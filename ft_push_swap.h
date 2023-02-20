/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:03:19 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/20 17:11:57 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
//# include "../libft/libft.h"

typedef struct s_value {
	int				value;
	char			*str;
	int				pos_sor;
	int				pos_uns;
	int				sorted;
	struct s_value	*next;
}	t_value;

typedef struct s_set {
	int	*a;
	int	*b;
	int	*moves;
	int	len_a;
	int	len_b;
	int	pos;
}	t_set;

//list functions
t_value	*ft_lstnew(t_value *prev, char *str, int sort);
t_value	*ft_lstlast(t_value *lst);
void	list_ass(t_value *src, t_value *dst);
void	free_list(t_value *head, void *ptr1, void *ptr2, void *ptr3);

//quicksort
void	swap_nodes(t_value	*src, t_value *dst);
t_value	*partition(t_value *first, t_value *last);
void	quicksort_list(t_value *first, t_value *last);
void	relabel(t_value *lst);

//radix sort
int		*calc_moves(int *order, int values);
void	sort_stack(int *a, int *moves, int values, int pos);
void	swap(int *a, int *b);
void	push(int *src, int *dst, int len_src, int len_dst);
void	rotate(int *values, int len);

//helper
int		to_power(int nb, int power);
int		*sort_array(t_value *arr, int values);
void	print_instr(int *moves);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

//helper2
long	ft_atoi(const char *nptr);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
int		ft_isspace(int c);

/*
//error handling
void	lst_check(t_value **lst);
void	error_check(char **args);
int		is_sorted(t_value *lst);
int		is_duplicate(t_value *lst);
void	error(t_value **lst);
*/

//error handling
void	ill_chr(char **str);
void	empty_args(char **str);
void	is_sorted(char **split);
void	is_duplicate(char **split);
void	range_chk(char **split);

//argument parsing
int		ft_cntwrds(char **s, char c);
char	*ft_strcpy(char *s, char c);
char	**ft_split(char **s, char c);

//small sorting (up to 3)
void	r_rotate(int *values, int len);
void	small_sort(int *val);
int		*res_arr(t_value **arr, int argc);

//medium sorting (up to 5)
int		find_max(int *val, int num);
int		find_min(int *val, int num);
void	medium_sort(int *val, int num);

#endif
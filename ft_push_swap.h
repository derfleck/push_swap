/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:03:19 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/19 15:38:09 by mleitner         ###   ########.fr       */
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

//helper
int		find_range(int *arr, int *range);
int		values(int num);
//list functions
t_value	*ft_lstnew(t_value *prev, char *str, int sort);
int		*ft_lstmax(t_value *lst);
void	splitlist(t_value *original, t_value **half1, t_value **half2);
void	mergesortlist(t_value **list);
t_value	*createmerge(t_value *a, t_value *b);

#endif
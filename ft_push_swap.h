/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:03:19 by mleitner          #+#    #+#             */
/*   Updated: 2023/01/17 20:09:45 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_value {
	int		value;
	char	*str;
	int		pos_sor;
	int		pos_uns;
	int		sorted;
	t_value	*next;
}	t_value;

//helper
int		find_range(int *arr, int *range);
int		values(int num);
//list functions
t_value	*ft_lstnew(char *str, int sort);
t_value	*ft_lstlast(t_value *lst);
void	ft_lstadd_back(t_value **lst, t_value *new);

#endif
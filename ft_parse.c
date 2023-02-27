/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:16:52 by mleitner          #+#    #+#             */
/*   Updated: 2023/02/26 12:21:31 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//checks how many values are in string
int	ft_cntwrds(char **s, char c)
{
	int	i;
	int	j;
	int	words;

	words = 0;
	i = 1;
	j = 0;
	while (s[i])
	{
		while (s[i][j] == c)
			j++;
		if (s[i][j])
			words++;
		while (s[i][j] != c && s[i][j])
			j++;
		if (!s[i][j])
		{
			i++;
			j = 0;
		}
	}
	return (words);
}

//copies string until a certain character occurs
char	*ft_strcpy(char *s, char c)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	tab = malloc((sizeof(char) * (i + 1)));
	if (!tab)
		return (0);
	while (s[j] != c && s[j] != '\0')
	{
		*(tab + j) = *(s + j);
		j++;
	}
	*(tab + j) = '\0';
	return (tab);
}

//splits arguments into values, maybe add malloc check
char	**ft_split(char **s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		words;

	i = 1;
	j = 0;
	words = 0;
	split = malloc(sizeof(char *) * ft_cntwrds(s, c));
	while (s[i])
	{
		while (s[i][j] == c)
			j++;
		if (s[i][j] != c && s[i][j] != '\0')
			split[words++] = ft_strcpy(&s[i][j++], c);
		while (s[i][j] != c && s[i][j] != '\0')
			j++;
		if (!s[i][j])
		{
			i++;
			j = 0;
		}
	}
	return (split);
}

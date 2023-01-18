/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:49:57 by mleitner          #+#    #+#             */
/*   Updated: 2022/11/09 12:43:22 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		length;

	i = 0;
	length = 0;
	if (str == NULL)
		return (0);
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			length += ft_check(str[i + 1], ptr);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			length++;
		}
		i++;
	}
	va_end(ptr);
	return (length);
}

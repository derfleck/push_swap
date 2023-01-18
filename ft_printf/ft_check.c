/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:22:16 by mleitner          #+#    #+#             */
/*   Updated: 2022/11/09 12:27:11 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char s, va_list ptr)
{
	int	i;

	i = 0;
	if (s == 'c')
		i += ft_putchar(va_arg(ptr, int));
	else if (s == 's')
		i += ft_putstr(va_arg(ptr, char *));
	else if (s == 'p')
		i = ft_print_ptr(va_arg(ptr, void *), i);
	else if (s == 'd' || s == 'i')
		i = ft_print_dec_sign(va_arg(ptr, int), i);
	else if (s == 'u')
		i = ft_print_dec(va_arg(ptr, unsigned long), i);
	else if (s == 'x')
		i = ft_hex_conv(va_arg(ptr, unsigned int), 0, i);
	else if (s == 'X')
		i = ft_hex_conv(va_arg(ptr, unsigned int), 1, i);
	else if (s == '%')
		i += ft_putchar('%');
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:30:01 by mleitner          #+#    #+#             */
/*   Updated: 2022/11/09 12:30:12 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr, int len)
{
	unsigned long long	addr;

	addr = (unsigned long long)ptr;
	if (addr == 0)
		return (ft_putstr("(nil)"));
	write(1, &"0x", 2);
	return (ft_hex_conv(addr, 0, len + 2));
}

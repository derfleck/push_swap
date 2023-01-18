/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:31:06 by mleitner          #+#    #+#             */
/*   Updated: 2022/11/09 12:42:55 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(unsigned int calc, int len)
{
	if (calc >= 10)
	{
		len = ft_print_dec(calc / 10, len);
		len = ft_print_dec(calc % 10, len);
	}
	else if (calc < 10 && calc >= 0)
	{
		write(1, &"0123456789"[calc], 1);
		len++;
	}
	return (len);
}

int	ft_print_dec_sign(int calc, int len)
{
	if (calc < 0)
	{
		write(1, &"-"[0], 1);
		len = ft_print_dec(-calc, len) + 1;
	}
	if (calc >= 10)
	{
		len = ft_print_dec(calc / 10, len);
		len = ft_print_dec(calc % 10, len);
	}
	else if (calc < 10 && calc >= 0)
	{
		write(1, &"0123456789"[calc], 1);
		len++;
	}
	return (len);
}

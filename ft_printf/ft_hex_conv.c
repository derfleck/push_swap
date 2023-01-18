/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:30:33 by mleitner          #+#    #+#             */
/*   Updated: 2022/11/09 12:43:02 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_conv(unsigned long long calc, int up_down, int len)
{
	if (calc >= 16)
	{
		len = ft_hex_conv(calc / 16, up_down, len);
		len = ft_hex_conv(calc % 16, up_down, len);
	}
	else if (calc < 16 && up_down)
	{
		write(1, &"0123456789ABCDEF"[calc], 1);
		len++;
	}
	else if (calc < 16 && !up_down)
	{
		write(1, &"0123456789abcdef"[calc], 1);
		len++;
	}
	return (len);
}

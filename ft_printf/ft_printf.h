/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleitner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:41:54 by mleitner          #+#    #+#             */
/*   Updated: 2022/11/09 12:51:50 by mleitner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	ft_check(const char s, va_list ptr);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_hex_conv(unsigned long long calc, int up_down, int len);
int	ft_print_dec_sign(int calc, int len);
int	ft_print_dec(unsigned int calc, int len);
int	ft_print_ptr(void *ptr, int len);
#endif

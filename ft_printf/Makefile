# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleitner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 13:04:26 by mleitner          #+#    #+#              #
#    Updated: 2022/10/28 17:03:08 by mleitner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c\
		ft_check.c\
		ft_hex_conv.c\
		ft_print_dec.c\
		ft_print_ptr.c\
		ft_putchar.c\
		ft_putstr.c
OBJ = ${SRC:.c=.o}
CFLAGS += -Wall -Wextra -Werror
NAME = libftprintf.a
CC = cc

.PHONY: all clean fclean re bonus

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

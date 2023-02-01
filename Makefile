# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleitner <mleitner@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:37:13 by mleitner          #+#    #+#              #
#    Updated: 2023/02/01 13:57:43 by mleitner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = 	main.c \
			ft_helper.c \
			ft_lst.c \
			ft_qs.c \
			ft_rdx.c \
			ft_helper2.c
O_FILES = ${C_FILES:.c=.o}
CFLAGS += -Wall -Wextra -Werror
NAME = push_swap
CC = cc

.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -o $(NAME)
clean:
	rm -f $(O_FILES)
fclean: clean
	rm -f $(NAME)
.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
re: fclean all
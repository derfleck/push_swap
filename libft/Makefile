# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleitner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 13:04:26 by mleitner          #+#    #+#              #
#    Updated: 2022/10/11 12:56:17 by mleitner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = ft_isalpha.c ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c
O_FILES = ${C_FILES:.c=.o}
BONUS_C_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
				ft_lstmap_bonus.c
BONUS_O_FILES = ${BONUS_C_FILES:.c=.o}
CFLAGS += -Wall -Wextra -Werror
NAME = libft.a

.PHONY: all clean fclean re bonus

all:
	cc $(CFLAGS) -c $(C_FILES)
	ar rcs $(NAME) $(O_FILES)
$(NAME): all
clean:
	rm -f $(O_FILES) $(BONUS_O_FILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
bonus: fclean
	cc $(CFLAGS) -c $(C_FILES) $(BONUS_C_FILES)
	ar rcs $(NAME) $(O_FILES) $(BONUS_O_FILES)

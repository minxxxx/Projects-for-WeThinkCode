# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/05/01 16:01:10 by dgalide          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	main.c 			\
		load_struct.c 	\
		utils.c 		\
		search.c 		\
		get.c 			\
		func.c 			\
		handlers/unsigned_decimal_handler.c \
		handlers/decimal_handler.c \
		handlers/percent_handler.c \
		handlers/hexadecimal_handler.c \
		handlers/wchar_handler.c \
		handlers/wstring_handler.c \
		handlers/octal_handler.c \
		handlers/string_handler.c 	\
		handlers/char_handler.c \
		handlers/pointer_handler.c \
		../../erase_char.c  	\
		../../ft_itoa.c 		\
		../../ft_memdel.c 	\
		../../ft_power.c 		\
		../../ft_strcmp.c 	\
		../../ft_memcmp.c 	\
		../../ft_strstr.c 	\
		../../ft_strcat.c 	\
		../../ft_putchar.c 	\
		../../ft_putendl.c 	\
		../../ft_putnbr.c 	\
		../../ft_strdup.c 	\
		../../ft_strjoin.c 	\
		../../ft_strnew.c 	\
		../../ft_strsub.c 	\
		../../ft_memalloc.c 	\
		../../ft_atoi.c 		\
		../../ft_bzero.c 		\
		../../ft_strlen.c 	\
		../../ft_putstr.c 	\
		../../ft_putnbr_fd.c 	\
		../../ft_putchar_fd.c \
		../../ft_memcpy.c 	\
		../../ft_isdigit.c 	\
		../../ft_unsigned_itoa.c \
		../../ft_memset.c \

SRCO = $(SRC:.c=.o)

INC = includes/ft_printf.h

FLAG = -Wall -Werror -Wextra

all: $(NAME)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC)

$(NAME): $(SRCO)
	ar rc $@ $^
	ranlib $@

clean:
	rm -rf $(SRCO)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean

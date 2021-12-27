# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgalide <dgalide@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 17:42:00 by dgalide           #+#    #+#              #
#    Updated: 2018/03/20 16:18:35 by dgalide          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC += ft_atoi_base.c
SRC += ft_tab_cpy.c
SRC += ft_tab_del.c
SRC += ft_tab_join.c
SRC += get_next_line.c
SRC += ft_atoi.c
SRC += ft_itoa.c
SRC += ft_bzero.c
SRC += ft_islower.c
SRC += ft_power.c
SRC += ft_isupper.c
SRC += ft_isalnum.c
SRC += ft_isalpha.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_isprint.c
SRC += ft_memalloc.c
SRC += ft_memccpy.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memmove.c
SRC += ft_memset.c
SRC += ft_putchar.c
SRC += ft_putchar_fd.c
SRC += ft_putendl.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr.c
SRC += ft_putnbr_fd.c
SRC += ft_putstr.c
SRC += ft_putstr_fd.c
SRC += ft_strcat.c
SRC += ft_strchr.c
SRC += ft_strcmp.c
SRC += ft_strcpy.c
SRC += ft_strdup.c
SRC += ft_strequ.c
SRC += ft_strlcat.c
SRC += ft_strlen.c
SRC += ft_strncat.c
SRC += ft_strncmp.c
SRC += ft_strncpy.c
SRC += ft_strnequ.c
SRC += ft_strnstr.c
SRC += ft_strrchr.c
SRC += ft_strstr.c
SRC += ft_tolower.c
SRC += ft_toupper.c
SRC += ft_memdel.c
SRC += ft_strnew.c
SRC += ft_strdel.c
SRC += ft_strclr.c
SRC += ft_strsplit.c
SRC += ft_striter.c
SRC += ft_striteri.c
SRC += ft_strmap.c
SRC += ft_strmapi.c
SRC += ft_strsub.c
SRC += ft_strjoin.c
SRC += ft_strtrim.c
SRC += ft_lstnew.c
SRC += ft_lstdelone.c
SRC += ft_lstdel.c
SRC += ft_lstadd.c
SRC += ft_lstiter.c
SRC += ft_lstmap.c
SRC += ft_countwords.c
SRC += ft_lenwords.c
SRC += ft_maketab.c
SRC += ft_printtab.c
SRC += ft_unsigned_itoa.c
SRC +=	printf/main.c 			\
		printf/load_struct.c 	\
		printf/utils.c 		\
		printf/search.c 		\
		printf/get.c 			\
		printf/func.c 			\
		printf/handlers/unsigned_decimal_handler.c \
		printf/handlers/decimal_handler.c \
		printf/handlers/percent_handler.c \
		printf/handlers/hexadecimal_handler.c \
		printf/handlers/wchar_handler.c \
		printf/handlers/wstring_handler.c \
		printf/handlers/octal_handler.c \
		printf/handlers/string_handler.c 	\
		printf/handlers/char_handler.c \
		printf/handlers/pointer_handler.c


INC = includes/libft.h
SRCO = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: $(NAME)

re: fclean all

%.o: %.c
	@echo "\033[K$(CY)[Libft] :$(CE) $(CG)Compiling $<$(CE) \033[1A";
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(SRCO)
	@echo "\033[K$(CY)[Libft] :$(CE) $(CG)Compiling Libft(CE) \033[1A";
	@ar rc $@ $^
	@ranlib $@

clean:
	@echo "\033[K$(CY)[Libft] :$(CE) $(CG) Cleaning Libft objects $(CE)\033[1A";
	@rm -rf $(SRCO)

fclean: clean
	@echo "\033[K$(CY)[Libft] :$(CE) $(CG) Cleaning archive ...$(CE)\033[1A";
	@rm -rf $(NAME)

.PHONY: all re clean fclean

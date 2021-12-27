# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opodolia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 13:55:22 by opodolia          #+#    #+#              #
#    Updated: 2017/03/20 20:16:39 by opodolia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_BASE = libftprintf

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# ft_printf directories
P_SRC_DIR = ./src/
P_OBJ_DIR = ./obj/
P_INC_DIR = ./includes/

# libft directories
L_SRC_DIR = ./libft/src/
L_OBJ_DIR = ./libft/obj/
L_INC_DIR = ./libft/includes/

# ft_printf source files
P_FILES = ft_printf.c ft_char.c ft_convert.c ft_str.c ft_is_mb.c ft_flags.c \
		  ft_length.c ft_numb.c ft_no_qual.c ft_precision.c ft_qualifier.c \
		  ft_push.c ft_size.c ft_width.c ft_float.c ft_put.c ft_unprint.c \
		  ft_ftoa_handler.c ft_get_mantissa.c ft_quote_mark.c

P_SRC = $(addprefix $(P_SRC_DIR), $(P_FILES))
P_OBJ = $(addprefix $(P_OBJ_DIR), $(P_FILES:.c=.o))

# libft source files
L_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
		  ft_strlen.c ft_strnlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		  ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c \
		  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		  ft_strjoin_free.c ft_strtrim.c ft_strsplit.c ft_split_del.c \
		  ft_strrev.c \
		  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		  ft_lstmap.c ft_lstsize.c ft_lstcount.c ft_lstrev.c \
		  ft_atoi.c ft_itoa.c ft_uitoa_base.c ft_ftoa_base.c ft_isalpha.c \
		  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		  ft_tolower.c ft_quicksort.c ft_swap.c ft_sqrt.c ft_ld_intpower.c \
		  ft_wclen.c ft_wcslen.c ft_wctomb.c ft_wcstombs.c \
		  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  get_next_line.c ft_count_words.c

L_SRC = $(addprefix $(L_SRC_DIR), $(L_FILES))
L_OBJ = $(addprefix $(L_OBJ_DIR), $(L_FILES:.c=.o))

.SILENT:

all: $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAME_BASE) is done\033[0m\033[K"

$(P_OBJ_DIR)%.o: $(P_SRC_DIR)%.c
	printf "\r\033[38;5;11m⌛  MAKE $(NAME_BASE) please wait ...\033[0m\033[K"
	mkdir -p $(P_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(P_INC_DIR) -o $@ -c $<

$(L_OBJ_DIR)%.o: $(L_SRC_DIR)%.c
	printf "\r\033[38;5;11m⌛  MAKE $(NAME_BASE) please wait ...\033[0m\033[K"
	mkdir -p $(L_OBJ_DIR)
	$(CC) $(CFLAGC) -I $(L_INC_DIR) -o $@ -c $<

OBJECTS = $(P_OBJ) $(L_OBJ)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	echo -en "\r\033[38;5;22m☑️  MAKE $(NAME_BASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat author | sed s/^/\ \ \ \ /g`\033[0m\033[K"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAME_BASE) please wait ...\033[0m\033[K"
	rm -rf $(P_OBJ_DIR) $(L_OBJ_DIR)
	printf "\r\033[38;5;11m☑️  CLEAN  $(NAME_BASE) is done\033[0m\033[K"

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAME_BASE) please wait ...\033[0m\033[K"
	rm -f $(NAME)
	printf "\r\033[38;5;11m☑️  FCLEAN  $(NAME_BASE) is done\033[0m\033[K"

re: fclean all

.PHONY: fclean clean re

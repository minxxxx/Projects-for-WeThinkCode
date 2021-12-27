#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 08:51:56 by apakhomo          #+#    #+#              #
#    Updated: 2018/01/27 08:51:57 by apakhomo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
DIR_S = src
DIR_O = temp
HEADER = include
SOURCES = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strjoin_free.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstnew.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_swap.c\
		ft_range.c\
		ft_sqrt.c\
		ft_iterative_power.c\
		ft_recursive_power.c\
		ft_split.c\
		ft_print_hex.c\
		ft_abs.c\
		ft_atoi_base.c\
		get_next_line.c\
		pf_conversions.c\
		pf_core.c\
		pf_fordigits.c\
		pf_ft_printf.c\
		pf_manage.c\
		pf_managecharandhex.c\
		pf_managestrandperc.c\
		pf_itoa.c\
		pf_verify.c\
		ft_testintstr.c\
		ft_strtolower.c\
		ft_print_charr.c\
		ft_free_arr.c\
		ft_check_hex.c\
		ft_hex_to_ul.c\
		ft_count_to_null.c\
		ft_new_int_arr.c\
		ft_new_char_arr.c\
		ft_new_int_matrix.c


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "######## MAKELIB: DONE ##########"

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temp
	@echo "## MAKELIB: LINKING" [ $@ ] " ###"
	@gcc $(FLAGS) -I./$(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@echo "### MAKELIB: REMOVE OBJ FILES ###"

fclean: clean
	@rm -f $(NAME)
	@echo "### MAKELIB: REMOVE BIN FILES ###"

re: fclean all

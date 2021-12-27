# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 18:34:40 by fkoehler          #+#    #+#              #
#    Updated: 2016/09/02 15:54:42 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c ./src ./ft_printf

SRC = ft_atoi.c \
	  ft_atol.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_countwords.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isspace.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_isquote.c \
	  ft_itoa.c \
	  ft_ltoa_base.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_multi_strlen.c \
	  ft_multi_strjoin.c \
	  ft_print_array.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putnchar.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putnstr.c \
	  ft_putnstr_fd.c \
	  ft_putstr_fd.c \
	  ft_replace_char.c \
	  ft_replace_str.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strchr_index.c \
	  ft_strrchr_index.c \
	  ft_strchr_count.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_str_isempty.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strstr_index.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  free_tab.c \
	  get_next_line.c \
ft_printf.c check_flags.c check_modifiers.c conv_wchar.c count_bytes.c \
count_char_decimal.c ft_put_llong.c ft_put_long.c print.c print_address.c \
print_char.c print_decimal.c print_decimal1.c print_decimal2.c \
print_decimal3.c print_hexa.c print_hexa_upper.c print_octal.c print_percent.c \
print_string.c print_udecimal.c print_wchar_string.c \


NAME = libft.a

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0;32mLibft compilation done !\033[0;m"

%.o: %.c
	@gcc $(FLAGS) -I ./includes -c $<

clean:
	@rm -f $(OBJ)
	@echo "\033[0;32mObject files deleted !\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32m$(NAME) deleted !\033[0;m"

re: fclean all

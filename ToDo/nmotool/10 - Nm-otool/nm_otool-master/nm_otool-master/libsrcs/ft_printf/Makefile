# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:49:18 by jcamhi            #+#    #+#              #
#    Updated: 2017/07/20 18:07:29 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_printf.c \
		is_x.c \
		ft_handle_conv.c \
		find.c \
		ft_handle_conv_2.c \
		ft_handle_conv_3.c \
		handle_flag.c \
		handle_prec.c \
		handle_width.c \
		find_2.c \
		ft_alloc_str.c \
		ft_alloc_str_with_char.c \
		ft_atoi.c \
		ft_itoa_base_ll.c \
		ft_itoa_base_ull.c \
		ft_itoa_ptr.c \
		ft_isdigit.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strchr.c \
		ft_strequ.c \
		ft_strdup.c \
		ft_strjoinaf12.c \
		ft_strjoinaf2.c \
		ft_strjoinaf1.c \
		ft_strlen.c \
		ft_strsub.c \
		ft_strtoupper.c \
		ft_strcpy.c \
		ft_toupper.c

INC_PATH = ./includes

OBJ_PATH = ./obj/

NAME = ../../lib/libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

SRC_PATH = ./srcss/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME) : $(OBJ)
	ar r $(NAME) $(OBJ)
#	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

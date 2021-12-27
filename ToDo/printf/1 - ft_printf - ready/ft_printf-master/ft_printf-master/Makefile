# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:49:18 by jcamhi            #+#    #+#              #
#    Updated: 2016/02/01 09:50:16 by jcamhi           ###   ########.fr        #
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

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

SRC_PATH = ./srcss/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(INC) $(SRC)
	ar r $(NAME) $(OBJ_NAME)
	ranlib $(NAME)

clean:
	rm -fv $(OBJ_NAME)
	
fclean: clean
	rm -fv $(NAME)

re: fclean all

.PHONY : all clean fclean re

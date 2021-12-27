# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juspende <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 13:06:32 by juspende          #+#    #+#              #
#    Updated: 2017/12/06 10:30:38 by juspende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

RM	= rm -f

NAME	= libftprintf.a

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -O3

INCLUDE	= /include/ft_printf.h

%.o: %.c
		gcc $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

SRCS	=	srcs/ft_printf.c				\
			srcs/basic/ft_putint.c			\
			srcs/basic/free_all.c			\
			srcs/basic/ft_atoi.c			\
			srcs/basic/ft_strcat.c			\
			srcs/basic/ft_strncat.c			\
			srcs/basic/ft_putstr.c			\
			srcs/basic/ft_printtab.c		\
			srcs/basic/ft_putchar.c			\
			srcs/basic/lenght_modif.c		\
			srcs/basic/int_len.c			\
			srcs/basic/ft_strdup.c			\
			srcs/basic/ft_putuint.c			\
			srcs/basic/ft_strlen.c			\
			srcs/basic/ft_strrev.c			\
			srcs/basic/ft_strchr.c			\
			srcs/basic/ft_getnbr_base.c		\
			srcs/basic/ft_getnbr_base_ui.c	\
			srcs/basic/ft_putlong.c			\
			srcs/basic/ft_putdouble.c		\
			srcs/basic/ft_itoa.c			\
			srcs/basic/larg_flag.c			\
			srcs/basic/ft_itoa_double.c		\
			srcs/basic/ft_strnew.c			\
			srcs/basic/ft_putshort.c		\
			srcs/basic/ft_putnbr_base.c		\
			srcs/basic/ft_print_memory.c	\
			srcs/basic/ft_print_bits.c		\
			srcs/letters/a.c				\
			srcs/letters/b.c				\
			srcs/letters/c.c				\
			srcs/letters/d.c				\
			srcs/letters/e.c				\
			srcs/letters/f.c				\
			srcs/letters/g.c				\
			srcs/letters/h.c				\
			srcs/letters/i.c				\
			srcs/letters/j.c				\
			srcs/letters/k.c				\
			srcs/letters/l.c				\
			srcs/letters/m.c				\
			srcs/letters/n.c				\
			srcs/letters/o.c				\
			srcs/letters/p.c				\
			srcs/letters/q.c				\
			srcs/letters/r.c				\
			srcs/letters/s.c				\
			srcs/letters/t.c				\
			srcs/letters/u.c				\
			srcs/letters/v.c				\
			srcs/letters/w.c				\
			srcs/letters/x.c				\
			srcs/letters/y.c				\
			srcs/letters/z.c

all:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

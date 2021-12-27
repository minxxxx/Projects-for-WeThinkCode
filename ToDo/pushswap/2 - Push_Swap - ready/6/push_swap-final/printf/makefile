# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfavero <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:32:33 by cfavero           #+#    #+#              #
#    Updated: 2018/03/18 19:08:00 by cfavero          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = ft_printf.h

LIB = libft.a

RED = \x1b[31m

GREEN = \x1b[32m

WHITE = \x1b[0m

SOURCES-PRF =	flag_c.c\
				flag_d.c\
				flag_o.c\
				flag_s.c\
				flag_u.c\
				flag_x.c\
				ft_fillstruct.c\
				ft_printf.c\
				ft_precision_d.c\
				ft_unicode.c\
				ft_size_d.c\
				ft_itoa_base.c\
				ft_precision_x.c\
				ft_size_u.c\
				ft_uitoa_base.c\
				get_list.c\

OBJECTS-PRF = $(SOURCES-PRF:.c=.o)

all: $(LIB) $(NAME) info

$(LIB) :
	@make -C ./libft

$(NAME): $(INC) $(OBJECTS-PRF)
	@libtool -static -o $@ libft/libft.a $(OBJECTS-PRF)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(INC)

info:
	 @echo "libftprintf.a${GREEN}		DONE${WHITE}"

clean:
	@make clean -C ./libft
	@/bin/rm -f $(OBJECTS-PRF)

fclean: clean
	@/bin/rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY : all clean fclean re

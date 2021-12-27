# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 11:14:06 by jbadenho          #+#    #+#              #
#    Updated: 2017/11/24 01:57:42 by jbadenho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror -g3
SRC = *.c
OBJ = *.o

all: obj
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

obj:
		@gcc -c $(SRC) libft.h $(FLAG)

clean:
		@rm -f $(OBJ)
		
fclean: clean
		@rm -f $(NAME)

re: fclean all

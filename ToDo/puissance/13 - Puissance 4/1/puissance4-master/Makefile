# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telain <telain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 20:22:58 by telain            #+#    #+#              #
#    Updated: 2016/02/26 23:33:28 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	  create_grid.c\
	  display_grid.c\
	  read_input.c\

all:
	gcc -Wall -Werror -Wextra -o puissance4 $(SRC) -L./libft -lft

go: all
	clear
	./puissance4 7 6

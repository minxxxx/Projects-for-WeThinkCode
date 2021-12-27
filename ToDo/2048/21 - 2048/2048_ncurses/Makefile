# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/31 13:21:43 by glarivie          #+#    #+#              #
#    Updated: 2016/01/31 13:28:33 by glarivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	game_2048
CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
LIB		=	-lncurses libft/libft.a
INC		=	-I includes/ -I libft/
SRCS	=	srcs/main.c				\

all		:	$(NAME)

$(NAME)	:
	@Make -C libft/
	@$(CC) $(FLAGS) $(LIB) $(INC) -o $(NAME) $(SRCS)
	@echo "Compiling\t\tOK"

clean	:
	@Make -C libft/ clean
	@rm -rf */*.o
	@echo "Cleaning\t\tOK"

fclean	:	clean
	@Make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Cleaning\t\tOK"

re		:	fclean all

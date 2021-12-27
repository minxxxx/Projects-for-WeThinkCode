# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 21:29:05 by pmartine          #+#    #+#              #
#    Updated: 2016/02/26 21:39:56 by pmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME =		puissance4
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LDLIBS =	-lft
RM =		/bin/rm -rf
SRC =		main.c
OBJ =		$(SRC:.c=.o)
EXT =		$(NAME:.a=.h)
EXT	+=		Makefile

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) $(CFLAGS) -c $(SRC) -I ./includes
	@echo "Objects created" 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "Program created"

clean:
	@echo "Objects are being removed ..." 
	@$(RM) $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "$(NAME) is being removed ..."
	@$(RM) $(OBJ) $(NAME)
	@make -C libft/ fclean

re: fclean all

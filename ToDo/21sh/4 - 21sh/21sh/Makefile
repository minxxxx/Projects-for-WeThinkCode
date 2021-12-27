# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/26 11:56:18 by sasiedu           #+#    #+#              #
#    Updated: 2016/07/31 13:50:23 by sasiedu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC = $(shell ls | grep '.c')

BIN = $(SRC:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(FLAGS) -I libft/ -c $(SRC)
	@$(CC) -o $(NAME) $(BIN) -I libft/ -L libft/ -lft -ltermcap
	@echo "21sh compiled. 21sh created."

clean:
	@make -C libft/ clean
	@rm -rf $(BIN)
	@echo "21sh clean done."

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "21sh fclean done."

re: fclean all
	@echo "21sh re done."

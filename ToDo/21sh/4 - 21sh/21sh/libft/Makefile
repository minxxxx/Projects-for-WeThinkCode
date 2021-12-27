# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/22 22:05:05 by sasiedu           #+#    #+#              #
#    Updated: 2016/07/23 14:20:19 by sasiedu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(shell ls | grep '.c')

BIN = $(SRC:.c=.o)

HEAD = libft

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@ $(CC) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(BIN)
	@ranlib $(NAME)
	@echo "librabry compiled. libft created"

clean:
	@rm -rf $(BIN)
	@echo "libft cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "libft fcleaned"

re: fclean all

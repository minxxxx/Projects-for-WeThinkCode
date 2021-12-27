# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/18 19:23:30 by jaguillo          #+#    #+#              #
#    Updated: 2015/06/19 19:28:35 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := avl

SRCS := avl.ml

LIBS := graphics.cmxa

all: $(NAME)

$(NAME): $(SRCS)
	@ocamlopt $(LIBS) $(SRCS) -o "$@"

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

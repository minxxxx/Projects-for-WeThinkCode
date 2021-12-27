# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/18 14:29:08 by jaguillo          #+#    #+#              #
#    Updated: 2015/06/18 16:46:26 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gardening

SRCS = gardening.ml

LIBS = graphics.cmxa

all: $(NAME)

$(NAME): $(SRCS)
	@ocamlopt $(LIBS) $(SRCS) -o "$@"

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

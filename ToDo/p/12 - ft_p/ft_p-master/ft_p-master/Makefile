# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/06 15:15:02 by jcamhi            #+#    #+#              #
#    Updated: 2017/08/03 17:05:58 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CL = client
NAME_SE = server

LIB_DIR = ./lib

all : $(NAME_CL) $(NAME_SE)

$(NAME_CL): TEST
	@mkdir -p $(LIB_DIR)
	@make -C libsrcs/libft 2> /dev/null
	@make -C libsrcs/ft_printf 2> /dev/null
	@make -C src/client

$(NAME_SE): TEST
	@mkdir -p $(LIB_DIR)
	@make -C libsrcs/libft 2> /dev/null
	@make -C libsrcs/ft_printf 2> /dev/null
	@make -C src/server

TEST:

clean:
	@make -C libsrcs/libft clean
	@make -C libsrcs/ft_printf clean
	@make -C src/client clean
	@make -C src/server clean

fclean: clean
	@make -C libsrcs/libft fclean
	@make -C libsrcs/ft_printf fclean
	@make -C src/client fclean
	@make -C src/server fclean
	@rm -rf $(LIB_DIR) || true

re: fclean all

.PHONY : all clean fclean re

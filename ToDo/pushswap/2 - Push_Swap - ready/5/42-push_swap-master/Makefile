# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/24 07:37:48 by pbondoer          #+#    #+#              #
#    Updated: 2016/12/24 08:04:22 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN		= ./bin/

all:
	mkdir -p $(BIN)
	make -C checker
	cp ./checker/checker $(BIN)
	make -C push_swap
	cp ./push_swap/push_swap $(BIN)

clean:
	rm -rf $(BIN)
	make -C checker clean
	make -C push_swap clean

fclean:
	rm -rf $(BIN)
	make -C checker fclean
	make -C push_swap fclean

re: fclean all

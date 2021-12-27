#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 15:56:35 by nfruneau          #+#    #+#              #
#    Updated: 2018/07/17 08:54:37 by mafernan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

COM = clang++

FLAGS = -std=c++11 -Wall -Werror -Wextra

NAME = avm

SRC = Main.cpp Parse.cpp Error.cpp Commands.cpp Factory.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(FLAGS) -o $(NAME) $(OBJ)
	@rm *.o

%.o: %.cpp
	$(COM) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

list:
	@grep '^[^#[:space:]].*:' Makefile

test: all
	@echo "\n-----------------------------------------------------------------\n"
	./avm tests/pdf_test.avm
	@echo "\n-----------------------------------------------------------------\n"
	./avm tests/pdf_test1.avm
	@echo "\n-----------------------------------------------------------------\n"
	./avm tests/pdf_test2.avm
	@echo "\n-----------------------------------------------------------------\n"
	./avm tests/pdf_test3.avm
	@echo "\n-----------------------------------------------------------------\n"
	./avm tests/pdf_test4.avm
	@echo "\n-----------------------------------------------------------------\n"
	./avm tests/flows.avm
	@echo "\n-----------------------------------------------------------------\n"

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfavero <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:32:33 by cfavero           #+#    #+#              #
#    Updated: 2018/05/07 13:39:20 by cfavero          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CHECK = checker

PUSH = push_swap

INC = includes/

CFLAGS = -Wall -Wextra -Werror

LIB = libftprintf.a

OBJ_PATH = objs/

RED = \x1b[31m

GREEN = \x1b[32m

WHITE = \x1b[0m

include files/make.dep
include moves/make.dep
include push/make.dep
include checks/make.dep

COBJS = $(CSRC:%.c=%.o)

POBJS = $(PSRC:%.c=%.o)

CHOBJS = $(addprefix $(OBJ_PATH), $(COBJS))

PUOBJS = $(addprefix $(OBJ_PATH), $(POBJS))

all: $(LIB) objs $(NAME)

$(NAME): $(INC) $(CHECK) $(PUSH)
	@echo "Status${GREEN}		----OVER--${WHITE}"

$(LIB) :
	@make -C ./printf

$(OBJ_PATH)%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(INC)

$(CHECK):  $(CHOBJS)
	@gcc -I $(INC) -o $(CHECK) $(CHOBJS) ./printf/libftprintf.a $(CFLAGS)
	@echo "checker${GREEN}			DONE${WHITE}"

$(PUSH) : $(PUOBJS)
	@gcc -I $(INC) -o $(PUSH) $(PUOBJS) ./printf/libftprintf.a $(CFLAGS)
	@echo "push_swap${GREEN}		DONE${WHITE}"

objs:
	@mkdir -p objs
	@mkdir -p objs/files
	@mkdir -p objs/checks
	@mkdir -p objs/moves
	@mkdir -p objs/push

clean:
	@make clean -C ./printf
	@rm -rf objs

fclean: clean
	@make fclean -C ./printf
	@/bin/rm -f $(CHECK) $(PUSH) ./printf/libftprintf.a

re: fclean all

.PHONY : all clean fclean re

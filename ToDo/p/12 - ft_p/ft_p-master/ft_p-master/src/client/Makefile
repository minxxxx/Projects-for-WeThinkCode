# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:49:18 by jcamhi            #+#    #+#              #
#    Updated: 2017/08/30 16:29:03 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = 	main.c \
							main_2.c \
							special_split.c \
							parse_cmd.c \
							utils.c \
							get_answer.c \
							set_passive_mode.c \
							data_connection.c \
							singleton.c \
							error_connection.c \
							signal.c \
							ret.c \
							func_login.c \
							func_cd.c \
							func_type.c \
							func_pwd.c \
							func_ls.c \
							func_get.c \
							func_put.c \
							func_quit.c \
							func_size.c

INC_PATH = ./includes

OBJ_PATH = ./obj/

NAME = ../../client

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC_PATH = ./

LIB_DIR = ../../lib

LFLAGS = -lft -lftprintf

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -L $(LIB_DIR) $(LFLAGS) $(INC) $^ -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

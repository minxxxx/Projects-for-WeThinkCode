#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 20:34:52 by apakhomo          #+#    #+#              #
#    Updated: 2017/11/07 20:34:54 by apakhomo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ssl
FLAGS = -Wall -Wextra -Werror

SRC_NAME =	main.c\
			reader_file.c\
			supportfunc.c\
			manageflags.c\
			managetypes.c\
			base64_core.c\
			base64_func.c\
			desecb_core.c\
			desecb_func.c\
			desecb_algo.c\
			desecb_keys.c\
			descbc_core.c\
			descbc_func.c\
			ecbcbc3core.c\
			desecb3algo.c\
			descbc3algo.c\
			managemdtps.c\
			supportmdcd.c\
			md5algocore.c\
			md5transfrm.c\
			md5spprtfnc.c\
			sha.c\
			whirlpool.c 


OBJ_NAME = $(SRC_NAME:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC = -I$(INC_DIR)

INC_DIR = include/
LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = obj/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(NAME)  $(OBJ) -L $(LIB_DIR) -lft
	@echo "### PROJECT: COMPILING FINISHED ####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "### PROJECT: LINKING" [ $@ ] " ###"
	@gcc $(FLAGS) -o $@ -c  $< $(INC)

clean:
	@make -C $(LIB_DIR) clean --silent
	@rm -f $(OBJ)
	@echo "### PROJECT: REMOVE OBJECT FILES ###"

fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	@rm -f $(NAME)
	@echo "### PROJECT: REMOVE BINARY FILES ###"

re: fclean all

.PHONY: clean fclean all re
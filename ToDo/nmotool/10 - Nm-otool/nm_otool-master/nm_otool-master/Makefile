# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/06 15:15:02 by jcamhi            #+#    #+#              #
#    Updated: 2017/07/25 19:00:38 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME_NM = nm.c \
								find_boundaries_64.c \
								list.c \
								create_elem.c \
								sort.c \
								find_boundaries_32.c \
								fat.c \
								handle.c \
								create_list.c \
								static_lib.c \
								opt.c \
								utils.c \
								fat_handle.c \
								static_lib_2.c

SRC_NAME_OT = otool.c \
								handle.c \
								print.c \
								fat.c \
								static_lib.c \
								utils.c \
								fat_fln.c \
								static_lib_2.c

OBJ_PATH_NM = ./objnm/
OBJ_PATH_OT = ./objot/

INC_PATH = ./includes ./libsrcs/libbinary/includes

SRC_PATH_NM = ./srcs/nm/
SRC_PATH_OT = ./srcs/otool/

NAME_NM = ft_nm
NAME_OT = ft_otool


CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

LFLAGS = -lft -lftprintf -lbinary

LIB_DIR=./lib

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_NM = $(addprefix $(SRC_PATH_NM),$(SRC_NAME_NM))
OBJ_NM = $(addprefix $(OBJ_PATH_NM),$(OBJ_NAME_NM))
OBJ_NAME_NM = $(SRC_NAME_NM:.c=.o)

SRC_OT = $(addprefix $(SRC_PATH_OT),$(SRC_NAME_OT))
OBJ_OT = $(addprefix $(OBJ_PATH_OT),$(OBJ_NAME_OT))
OBJ_NAME_OT = $(SRC_NAME_OT:.c=.o)

INC = $(addprefix -I,$(INC_PATH))


all : $(NAME_NM) $(NAME_OT) $(SYM_NAME)

$(NAME_NM) : $(OBJ_NM)
	@mkdir -p $(LIB_DIR)
	@make -C libsrcs/libft
	@make -C libsrcs/ft_printf
	@make -C libsrcs/libbinary
	$(CC) $(CFLAGS) $^ -L $(LIB_DIR) $(LFLAGS) -o $@

$(NAME_OT) : $(OBJ_OT)
	@mkdir -p $(LIB_DIR)
	@make -C libsrcs/libft 2>&1 > /dev/null
	@make -C libsrcs/ft_printf 2>&1 > /dev/null
	@make -C libsrcs/libbinary 2>&1 > /dev/null
	$(CC) $(CFLAGS) $^ -L $(LIB_DIR) $(LFLAGS) -o $@

$(OBJ_PATH_NM)%.o: $(SRC_PATH_NM)%.c
	@mkdir -p $(OBJ_PATH_NM)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH_OT)%.o: $(SRC_PATH_OT)%.c
	@mkdir -p $(OBJ_PATH_OT)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ_NM)
	rm -fv $(OBJ_OT)
	rmdir -p $(OBJ_PATH_NM) 2> /dev/null || true
	rmdir -p $(OBJ_PATH_OT) 2> /dev/null || true
	make -C libsrcs/libft clean
	make -C libsrcs/ft_printf clean
	make -C libsrcs/libbinary clean

fclean: clean
	rm -fv $(NAME_NM)
	rm -fv $(NAME_OT)
	make -C libsrcs/libft fclean
	make -C libsrcs/ft_printf fclean
	make -C libsrcs/libbinary	 fclean
	@rmdir lib 2> /dev/null || true

re: fclean all

.PHONY : all clean fclean re

SRC_NAME = main.c \
		ttys.c \
		signals.c \
		singelton.c \
		parent.c \
		parent_multiplex.c \
		child.c \
		parsing_helpers.c \
		parsing.c \
		env.c \
		writes.c

OBJ_PATH = ./obj/

INC_PATH = ./includes ./libsrcs/libft/includes/

SRC_PATH = ./srcs/

NAME = ft_script

CC = gcc
CFLAGS =  -Wextra -Wall -Werror -g
LFLAGS = -lft
LIB_DIR=./lib/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)

INC = $(addprefix -I,$(INC_PATH))

all : $(LIB_DIR) $(NAME)

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

$(NAME) : $(OBJ)
	make -C libsrcs/libft
	$(CC) $(CFLAGS) $(OBJ) -L $(LIB_DIR) $(LFLAGS) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -p $(OBJ_PATH) 2> /dev/null || true
	@make -C libsrcs/libft clean

fclean: clean
	@rm -fv $(NAME)
	@make -C libsrcs/libft fclean
	@rmdir lib 2> /dev/null || true

re: fclean all

.PHONY : all clean fclean re

SRC_NAME = main.c \
		md5_main.c \
		sha256_main.c \
		sha256_main_2.c \
		md5_parsing.c \
		md5_parsing_2.c \
		md5_stages.c \
		md5_fghi.c \
		md5_init.c \
		general_operations.c \
		sha256_functions.c \
		sha256_functions_2.c \
		sha256_compute_buffer.c \
		parsing.c \
		bitwise_operations.c

OBJ_PATH = ./obj/

INC_PATH = ./includes ./libsrcs/libft/includes/

SRC_PATH = ./srcs/

NAME = ft_ssl

CC = gcc
CFLAGS =  -Wextra -Wall -g
# CFLAGS =  -Wextra -Wall -Werror -g
LFLAGS = -lft
LIB_DIR=./lib/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)

INC = $(addprefix -I,$(INC_PATH))

all : LIB_RULE $(NAME)

LIB_RULE:
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

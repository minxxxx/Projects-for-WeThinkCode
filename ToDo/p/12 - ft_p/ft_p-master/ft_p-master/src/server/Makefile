SRC_NAME = 	main.c \
							utils.c \
							handle_connection.c \
							parse_pass_file.c \
							parse_cmd.c \
							data_process.c \
							signal.c \
							open_wrapper.c \
							opendir_wrapper.c \
							func_user.c \
							func_pass.c \
							func_syst.c \
							func_feat.c \
							func_cwd.c \
							func_pwd.c \
							func_cdup.c \
							func_pasv.c \
							func_list.c \
							func_list_2.c \
							func_type.c \
							func_size.c \
							func_mdtm.c \
							func_retr.c \
							func_stor.c \
							func_quit.c

INC_PATH = ./includes

OBJ_PATH = ./obj/

NAME = ../../server

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

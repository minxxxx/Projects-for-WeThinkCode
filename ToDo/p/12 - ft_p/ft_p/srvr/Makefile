NAME = serveur

H_DIR = ../libft/includes

C_DIR = ./

C_FILES = main.c init_env.c create_server.c manage_client.c exec_pwd_ls_cd.c\
exec_getput.c exec_pwd_ls_cd2.c exec_getput2.c exec_mkdir_rmdir_unlink.c

O_FILES = $(C_FILES:.c=.o)

LIBFT = ../libft/

all: $(NAME)

$(NAME): $(O_FILES)
	@clang -Wall -Werror -Wextra -O2 -o ../$(NAME) $^ -I$(H_DIR) -L$(LIBFT) -lft

%.o: $(C_DIR)%.c
	@clang -Wall -Wextra -Werror -I$(H_DIR) -o $@ -c $<

clean:
	@rm -f $(O_FILES) 

fclean: clean
	@rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

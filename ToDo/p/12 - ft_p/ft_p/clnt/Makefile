NAME = client

H_DIR = ../libft/includes

C_DIR = ./

C_FILES = main.c init_env.c client_shell.c client_shell2.c

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

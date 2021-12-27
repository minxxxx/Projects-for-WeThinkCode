NAME = ft_script

INC_DIR = inc/

SRC_DIR = ./src/

SRC_FILES = main.c analyse_av_ac.c analyse_av_ac2.c debug.c\
 op_on_file.c new_shell.c init_env.c master_slave.c flush.c\
 ft_termios.c

O_FILES = $(SRC_FILES:.c=.o)

CC = clang

CC_FLAGS = -Wall -Werror -Wextra

I_LIBFT = -Ilibft/includes

LIBFT = -Llibft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@$(CC) $(CC_FLAGS) -O2 -o $(NAME) $^ -I$(INC_DIR) $(LIBFT)
	@echo "$(NAME) is ready :)"

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)
	@echo ".\c"

clean:
	@make clean -C libft
	@rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

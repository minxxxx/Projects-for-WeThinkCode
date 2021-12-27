NAME = 42sh

FILES = main.c \
		init_term.c \
		utils.c \
		signals.c \
		env_variables.c \
		builtins.c \
		commands.c \
		prompt.c \
		line.c \
		get_key.c \
		press_arrow.c \
		print_letter.c \
		press_delete.c \
		press_enter.c \
		window_size.c \
		history.c \
		ft_build_tree.c \
		ft_exec.c \
		ft_handle_cmdline.c \
		ft_redirections.c \
		ft_and_or.c \
		ft_parentheses.c \
		ft_handle_quote.c \
		ft_complete_cmd.c \
		ft_handle_fd_redirection.c \
		ft_find_operator.c \
		special_keys.c special_keys_2.c special_keys_3.c \
		autocomplete.c

SRC = $(addprefix srcs/, $(FILES))
OBJ = $(SRC:.c=.o)

FT_PRINTF = ./ft_printf

INC = -I$(FT_PRINTF)/includes -I.

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INC)

LIBS = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) -ltermcap
	@echo "\033[1;32m$@ COMPILED ✓\033[0m"

 %.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Building: \033[34m$@\033[0m"

clean:
	@rm -f $(OBJ)
	@make -C $(FT_PRINTF) clean
	@echo "\033[1;31mCLEANED ✓\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF) fclean

re: fclean all

NAME = ft_p

H_DIR = libft/includes

LIBFT = ./libft/

all: $(NAME)

$(NAME):
	@make -C libft
	@make -C srvr
	@make -C clnt
	@echo "\033[32mft_p is ready :)\033[0m"

clean:
	@make clean -C libft
	@make clean -C srvr
	@make clean -C clnt

fclean: clean
	@make fclean -C libft
	@make fclean -C srvr
	@make fclean -C clnt

re: fclean all

serveur:
	@make -C libft
	@make -C srvr
	@echo "\033[32m'serveur' is ready :)\033[0m"

client:
	@make -C libft
	@make -C clnt
	@echo "\033[32m'client' is ready :)\033[0m"

.PHONY: all clean fclean re serveur client

NAME = avm

INC_DIR = inc/

SRC_DIR = ./src/

SRC_FILES = OperandFactory.cxx AvmException.cxx Avm.cxx main.cxx Operations.cxx

O_FILES = $(SRC_FILES:.cxx=.o)

CC = clang++ -std=c++11

FLAGS = -Wall -Werror -Wextra -O2

all: $(NAME)

$(NAME): $(O_FILES)
	@$(CC) $(FLAGS) -o $(NAME) $^ -I$(INC_DIR)
	@echo "$(NAME) is ready :)"

%.o: $(SRC_DIR)%.cxx
	@$(CC) $(FLAGS) -I$(INC_DIR) -o $@ -c $<

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

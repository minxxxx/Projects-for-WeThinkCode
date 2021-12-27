SRC_NAME =	Int8.cpp \
			Int16.cpp \
			Int32.cpp \
			Float.cpp \
			Double.cpp \
			main.cpp \
			lexer.cpp \
			lexer_get.cpp \
			Token.cpp \
			LexicalException.cpp \
			SyntaxicException.cpp \
			RuntimeException.cpp \
			Parser.cpp \
			Instruction.cpp \
			ParserStates.cpp \
			OperandFactory.cpp \
			AVM.cpp \
			to_string.cpp

INC_PATH = ./includes/
OBJ_PATH = ./obj/

NAME = ./avm

CC = /usr/bin/clang++

#CFLAGS = -Wall -Werror -Wextra -g
CFLAGS = -Wall -Wextra -g -std=c++11

SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

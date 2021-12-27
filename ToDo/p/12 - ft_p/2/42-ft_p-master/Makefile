SRC_S = srcs/serveur.c
SRC_S += srcs/serveur2.c
SRC_S += srcs/serveur3.c
SRC_S += srcs/exec_lib.c
SRC_S += srcs/common.c
SRC_S += srcs/common2.c
SRC_S += srcs/cd.c
SRC_C = srcs/client.c
SRC_C += srcs/client2.c
SRC_C += srcs/client3.c
SRC_C += srcs/common.c
SRC_C += srcs/common2.c
SRC_C += srcs/cd.c

NAME_S = serveur
NAME_C = client

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

LIB = libft/libft.a
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m
INC = -I ./includes/

all: start lib $(NAME_C) $(NAME_S)


lib:
	-@make -C libft nohd

$(NAME_C): $(OBJ_C)
	@gcc -o $(NAME_C) $(SRC_C) $(FLAG) $(INC) $(LIB);
	@echo "\033[K$(CY)[FT_P] :$(CE) $(CG)Compiling client$(CE)";

$(NAME_S): $(OBJ_S)
	@gcc -o $(NAME_S) $(SRC_S) $(FLAG) $(INC) $(LIB);
	@echo "\033[K$(CY)[FT_P] :$(CE) $(CG)Compiling serveur$(CE)";

start:
	@echo "\n";
	@echo "			$(CG)      :::::::::: :::::::::::           ::::::::: $(CE)";
	@echo "			$(CG)     :+:            :+:               :+:    :+: $(CE)";
	@echo "			$(CG)    +:+            +:+               +:+    +:+  $(CE)";
	@echo "			$(CG)   :#::+::#       +#+               +#++:++#+    $(CE)";
	@echo "			$(CG)  +#+            +#+               +#+           $(CE)";
	@echo "			$(CG) #+#            #+#               #+#            $(CE)";
	@echo "			$(CG)###            ###    ########## ###             $(CE)";
	@echo "\n";

%.o: %.c
	@echo "\033[K$(CY)[FT_P] :$(CE) $(CG)Compiling $<$(CE)";
	@gcc $(FLAG) -c $< -o $@ $(INC)

clean: start
	@echo "$(CY)[FT_P] :$(CE) $(CG)Cleaning ft_p objects$(CE)";
	-@make -C libft nohdclean;
	@/bin/rm -rf $(OBJ_C) $(OBJ_S);

fclean: start clean
	@echo "\033[K$(CY)[FT_P] :$(CE) $(CG)Cleaning binairies ...$(CE)";
	-@make -C libft nohdfclean;
	@/bin/rm -f $(NAME_S) $(NAME_C);

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrancho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 11:43:12 by jfrancho          #+#    #+#              #
#    Updated: 2016/02/02 13:31:44 by jtranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048
LIB = libft/libft.a 
SRC =	src/game_2048.c \
		src/print_map.c \
		src/algo.c \
		src/left.c \
		src/right.c \
		src/down.c \
		src/up.c\
		src/test_errors.c \
		src/save.c \
		src/diff_save.c \
		src/init_map.c \
		src/check.c \

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: start $(NAME)

$(NAME): $(OBJ)
	@echo "$(CY)[2048] :$(CE) $(CG)Creating Library$(CE)";
	-@make -C libft nohd
	@echo "$(CY)[2048] :$(CE) $(CG)Compiling 2048 ...$(CE)";
	@gcc -o $(NAME) $(FLAG) $(SRC) $(LIB) -lncurses

%.o: %.c
	@echo "$(CY)[2048] :$(CE) $(CG)Compiling $<$(CE)";
	@gcc $(FLAG) -c $< -o $@

clean: start
	@echo "$(CY)[2048] :$(CE) $(CG)Cleaning Library ...$(CE)";
	-@make -C libft nohdclean
	@echo "$(CY)[2048] :$(CE) $(CG)Cleaning 2048 objects$(CE)";
	@/bin/rm -rf $(OBJ)

fclean: start clean
	@echo "$(CY)[2048] :$(CE) $(CG)FCleaning Library ...$(CE)";
	-@make -C libft nohdfclean
	@echo "$(CY)[2048] :$(CE) $(CG)Cleaning 2048 ...$(CE)";
	@/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)

start:
	@echo "\n\n"
	@echo "						$(CG)		           ¶¶¶¶¶¶¶¶¶¶¶              $(CE)";
	@echo "						$(CG)		         ¶¶           ¶¶            $(CE)";
	@echo "						$(CG)		       ¶¶               ¶¶          $(CE)";
	@echo "						$(CG)		     ¶¶      $(CY)¶¶$(CE)    $(CY)¶¶$(CE)     $(CG)¶¶        $(CE)";
	@echo "						$(CG)		   ¶¶       $(CY)¶¶$(CE)    $(CY)¶¶$(CE)        $(CG)¶¶      $(CE)";
	@echo "						$(CG)		 ¶¶          $(CY)¶¶$(CE)    $(CY)¶¶$(CE)         $(CG)¶¶    $(CE)";
	@echo "						$(CG)		¶¶                             ¶¶   $(CE)";
	@echo "						$(CG)		¶¶                             ¶¶ $(CE)";
	@echo "						$(CG)		¶¶     $(CY)¶¶$(CE)              $(CY)¶¶$(CE)      $(CG)¶¶ $(CE)";
	@echo "						$(CG)		¶¶      $(CY)¶¶$(CE)            $(CY)¶¶$(CE)       $(CG)¶¶ $(CE)";
	@echo "						$(CG)		¶¶       $(CY)¶¶$(CE)         $(CY)¶¶$(CE)         $(CG)¶¶   $(CE)";
	@echo "						$(CG)		 ¶¶         $(CY)¶¶¶¶¶¶¶$(CE)           $(CG)¶¶    $(CE)";
	@echo "						$(CG)		   ¶¶                        ¶¶     $(CE)";
	@echo "						$(CG)		     ¶¶                    ¶¶       $(CE)";
	@echo "						$(CG)		       ¶¶                ¶¶         $(CE)";
	@echo "						$(CG)		         ¶¶            ¶¶           $(CE)";
	@echo "						$(CG)		           ¶¶¶¶¶¶¶¶¶¶¶¶             $(CE)";
	@echo "\n\n"
	@echo "							$(CY) - - - - - - - - - - - - - - - - - - -$(CE)";
	@echo "							$(CY)|$(CE)$(CG)    ___     ___    _  _      ___  	$(CE)$(CY)|$(CE)";
	@echo "							$(CY)|$(CE)$(CG)    |__ \   / _ \  | || |    / _ \ 	$(CE)$(CY)|$(CE)";
	@echo "							$(CY)|$(CE)$(CG)       ) | | | | | | || |_  | (_) |	$(CE)$(CY)|$(CE)";
	@echo "							$(CY)|$(CE)$(CG)      / /  | | | | |__   _|  > _ < 	$(CE)$(CY)|$(CE)";
	@echo "							$(CY)|$(CE)$(CG)     / /_  | |_| |    | |   | (_) |	$(CE)$(CY)|$(CE)";
	@echo "							$(CY)|$(CE)$(CG)    |____|  \___/     |_|    \___/ 	$(CE)$(CY)|$(CE)";
	@echo "							$(CY) - - - - - - - - - - - - - - - - - - -$(CE)";

.PHONY: all clean fclean re

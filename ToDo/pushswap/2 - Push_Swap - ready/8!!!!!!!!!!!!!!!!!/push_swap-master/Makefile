# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 16:34:42 by ljoly             #+#    #+#              #
#    Updated: 2017/07/06 17:27:02 by ljoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_C = checker

SRC_PS = get_specs.c get_min_med_max.c push_swap.c op.c simple_sort.c \
	  next_target.c quick_sort.c split.c is_sorted.c store_op.c rm_doubles.c \
	  end.c display.c

SRC_C = checker.c checker_op.c is_sorted.c end.c

SRC_PS_PATH = ./srcs/push_swap/
SRC_C_PATH = ./srcs/checker/
OBJ_PS_PATH = ./obj/
OBJ_C_PATH = ./obj/

OBJ_PS = $(addprefix $(OBJ_PS_PATH), $(SRC_PS:.c=.o))
OBJ_C = $(addprefix $(OBJ_C_PATH), $(SRC_C:.c=.o))

FLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/
HEADER_LIB = ./libft/includes/
HEADER = ./includes

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME) $(NAME_C)

$(NAME): obj $(OBJ_PS)
	@gcc $(FLAGS) -o $(NAME) -I $(HEADER_LIB) -I $(HEADER) $(OBJ_PS) -L $(LIBFT) -lft
	@printf "\n$(GREEN)[✓]$(NC)\x1B[32mExecutable $(NAME) ready !\x1B[37m\n"

$(NAME_C): obj_c $(OBJ_C)
	@gcc $(FLAGS) -o $(NAME_C) -I $(HEADER_LIB) -I $(HEADER) $(OBJ_C) -L $(LIBFT) -lft
	@printf "\n$(GREEN)[✓]$(NC)\x1B[32mExecutable $(NAME_C) ready !\x1B[37m\n"

obj:
	@make -C $(LIBFT)
	@printf "\n\x1B[38;5;208mCompiling $(NAME)...\n\x1b[37m"
	@mkdir -p $(OBJ_PS_PATH)

obj_c:
	@printf "\n\x1B[38;5;208mCompiling $(NAME_C)...\n\x1b[37m"

$(OBJ_PS_PATH)%.o: $(SRC_PS_PATH)%.c
	@gcc $(FLAGS) -I $(LIBFT) -I $(HEADER_LIB) -I $(HEADER) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

$(OBJ_C_PATH)%.o: $(SRC_C_PATH)%.c
	@gcc $(FLAGS) -I $(LIBFT) -I $(HEADER_LIB) -I $(HEADER) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_PS_PATH)
	@printf "$(RED)[-]$(NC)Obj files deleted\n"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@printf "$(RED)[-]$(NC)Executable $(NAME) deleted\n"
	@rm -f $(NAME_C)
	@printf "$(RED)[-]$(NC)Executable $(NAME_C) deleted\n"

re: fclean all

.PHONY: all clean fclean re

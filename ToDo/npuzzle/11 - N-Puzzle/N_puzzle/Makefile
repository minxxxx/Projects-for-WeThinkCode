# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 11:16:22 by ggroener          #+#    #+#              #
#    Updated: 2016/10/05 14:21:45 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = npuzzle

CFLAGS = -Wall -Wextra -Werror -g -Ofast -flto -march=native -g

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c 					\
			get_next_line.c 		\
			read_file.c 			\
			valid_int.c 			\
			dump_state.c 			\
			push_list_state.c 		\
			remove_list_state.c 	\
			astar.c 				\
			new_state.c 			\
			build_end.c 			\
			new_size_state.c 		\
			equals_state.c 			\
			list_contents_state.c 	\
			free_list_state.c 		\
			free_state.c 			\
			expend_state.c 			\
			copy_state.c 			\
			manhattan.c 			\
			generate_random.c 		\
			is_solvable.c 			\
			timing.c 				\
			print_solution.c 		\
			size_list_state.c 		\
			misplaced.c 			\
			row_column.c 			\
			cal_score_state.c 		\
			cost_state.c 			\
			get_list_state.c 		\
			push_tree_state.c 		\
			get_tree_state.c 		\
			set_tree_state.c 		\
			free_tree_state.c 		\
			get_score.c 			\
			euclidean.c 			\

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

#uncomment these to work on Mac and comment to work on Linux.
LIBRARY = -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

INCLUDES = -I includes/ -I libft/includes

#uncomment these to work on Linux and comment to work on Mac.
#LIBRARY = -L /usr/X11/lib -lmlx -lX11 -lm -lXext -L libft/ -lft
 
#INCLUDES = -I includes/ -I libft/includes -I /usr/X11/include

HEADER = 	$(INCLUDES_PATH)npuzzle.h 		\
			$(INCLUDES_PATH)define.h		\
			$(INCLUDES_PATH)includes.h		\
			$(INCLUDES_PATH)env.h			\
			$(INCLUDES_PATH)prototypes.h	\
			$(INCLUDES_PATH)state.h			\

all: qme odir $(NAME)

define colourecho
	@tput setaf 14
	@echo $1
	@tput sgr0
endef

define colourecho2
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

$(NAME): $(OBJS)
	@Make -C libft
	@$(call colourecho, " - Making $(NAME)")
	@clear
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)
	@$(call colourecho, "Compiling Done!")

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@Make clean -C libft
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@$(call colourecho, "clean done!")

fclean: clean
	@Make fclean -C libft
	@$(call colourecho, "Clearing executable files")
	@rm -f $(NAME)
	@$(call colourecho, "fclean done")

re: fclean all
	@$(call colourecho, "re Done!")

format: norme me

norme: norm

norm:
	@clear
	@$(call colourecho2, "Norminette:")
	@norminette $(SRCS)
	@$(call colourecho2, "SRCS Files Done")
	@norminette $(HEADER)
	@$(call colourecho2, "Header Files Done!")

qme:
	@if [ ! -f author ]; then \
		echo ggroener > author; \
		echo khansman >> author; \
	fi
	
me: qme
	cat -e author

.PHONY: clean fclean re odir

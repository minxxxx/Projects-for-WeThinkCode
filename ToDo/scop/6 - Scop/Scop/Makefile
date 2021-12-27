# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 11:16:22 by ggroener          #+#    #+#              #
#    Updated: 2016/10/08 10:32:05 by khansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

CFLAGS =	-Wno-deprecated-declarations -Wall -Wextra -Werror -g -Ofast

CFLAGS2 =	-framework OpenGL -framework GLUT -Wno-deprecated-declarations \
			-g -Ofast -ltermcap

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = centerpoint.c				\
			change_size.c 				\
			count_elements.c			\
			error_quit.c				\
			exit_prog.c					\
			free_lst.c					\
			ft_atof.c					\
			ft_print_memory.c			\
			matrix_add.c				\
			matrix_create.c				\
			matrix_destroy.c			\
			matrix_identity.c			\
			matrix_multiply.c			\
			matrix_sub.c				\
			matrix_transpose.c			\
			normalise.c					\
			print_list.c				\
			process_normal_keys.c 		\
			process_special_keys.c 		\
			read_obj.c					\
			render_scene.c 				\
			set_arrays.c				\
			set_colour.c				\
			scop.c 						\
			store_face.c				\
			store_obj.c					\
			term.c						\
			trim.c						\
			vertex_create.c				\
			mousehook.c					\

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

#uncomment these to work on Mac and comment to work on Linux.
LIBRARY = -lmlx -L libft/ -lft -L minilibx_macos/ -lft -framework OpenGL -framework AppKit

INCLUDES = -I includes/ -I libft/includes

#uncomment these to work on Linux and comment to work on Mac.
#LIBRARY = -L /usr/X11/lib -lmlx -lX11 -lm -lXext -L libft/ -lft
 
#INCLUDES = -I includes/ -I libft/includes -I /usr/X11/include

HEADER = 	$(INCLUDES_PATH)scop.h		\

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
	@Make -C minilibx_macos
	@$(call colourecho, " - Making $(NAME)")
	@clear
	@$(CC) $(CFLAGS2) -o $(NAME) $^ $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
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
	@Make -C minilibx_macos
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
	@norminette $(HEADER)

fnorm: fnorme

fnorme:
	@clear
	@$(call colourecho2, "Norminette:")
	@find ./srcs -name "*.c" -maxdepth 1 -type f -exec norminette  {} \;
	@find ./includes -name "*.h" -maxdepth 1 -type f -exec norminette  {} \;

qme:
	@if [ ! -f author ]; then \
		whoami > author; \
	fi
	
me: qme
	cat -e author

.PHONY: clean fclean re odir

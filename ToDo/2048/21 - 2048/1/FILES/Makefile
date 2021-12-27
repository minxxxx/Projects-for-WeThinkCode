# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 11:01:28 by dtedgui           #+#    #+#              #
#    Updated: 2016/01/31 15:55:46 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= game_2048

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(HEADERS)

FILES		= main.c \
			  direction/wk_test_left.c direction/wk_move_left.c \
			  direction/wk_test_right.c direction/wk_move_right.c \
			  direction/wk_test_down.c direction/wk_move_down.c \
			  direction/wk_test_up.c direction/wk_move_up.c \
			  print_grid.c \
			  clear_screen.c free_struct.c \
			  random.c \
			  game_stats.c \
			  create_window.c \
			  victory.c

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)

LIBFT		= ./libft
HEADERS		= .

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT) -lft -lncurses

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

NAME		= push_swap

FILES		= main.c \
			  push.c \
			  swap.c \
			  rotate.c \
			  reverse_rotate.c \
			  algo.c \
			  print_piles.c \
			  utils.c

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

FT_PRINTF	= ./ft_printf

INCLUDES	= -I$(FT_PRINTF)/includes -I.

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) -L$(FT_PRINTF) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	make -C $(FT_PRINTF) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(FT_PRINTF) fclean
	rm -f $(NAME)

re: fclean all

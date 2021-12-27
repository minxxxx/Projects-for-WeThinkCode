NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
src = $(wildcard ft_*.c)
obj = $(src:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(obj)
	ar rcs $(NAME) $(obj)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.
clean:
	rm -f $(obj)
fclean: clean
	rm -f $(NAME)
re: fclean all

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
src = $(wildcard ft_*.c)
ft_src = $(wildcard libft/ft_*.c)
obj = $(src:.c=.o)
ft_obj = $(ft_src:.c=.o)
CC = gcc

all: $(NAME)

$(NAME):$(ft_obj) $(obj)
	ar rcs $(NAME) $(ft_src:.c=.o) $(obj)
libft/libft.a:
	make -C libft/
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.
clean:
	make -C libft/ clean
	rm -f $(obj)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
re: fclean all
tclean: clean
	rm -f test test.o
test: $(NAME) test.c
	$(CC) -c -g -o test.o test.c -I.
	$(CC) -g -o test test.o -L ./ -lftprintf

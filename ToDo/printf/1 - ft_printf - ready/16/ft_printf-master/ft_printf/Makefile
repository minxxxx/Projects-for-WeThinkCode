NAME = libftprintf.a

SRCS = ft_swap_char.c ft_width.c ft_itoa_long.c ft_acc_diu.c flags.c modif.c \
casted.c diu.c mod_conv.c procent.c ft_printf.c ft_strjoin.c ft_strnew.c ft_strlen.c ft_strchr.c \
ft_putstr.c ft_strdup.c conv_o.c conv_x.c str_diuox.c str_s.c str_c.c str_null.c ft_strcmp.c ft_itoa_size_t.c \
unicode.c width_unicode.c str_p.c maska.c c_unicod.c ft_strdel.c flag.c str_ls_lc.c
GCC = gcc -Wall -Wextra -Werror -c $(SRCS) -Ilibftprintf.h
ARC = ar rc libftprintf.a *.o

all: $(NAME)

$(NAME): $(SRCS) libftprintf.h
	$(GCC)
	$(ARC)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f libftprintf.a

re: fclean all

NAME = libft.a

H_DIR = includes/
C_DIR = ./

C_FILES = ft_atoi.c ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c\
 ft_strncpy.c ft_tolower.c ft_bzero.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c\
 ft_striteri.c ft_strnequ.c ft_toupper.c ft_isalnum.c ft_memchr.c ft_putendl.c\
 ft_strclr.c ft_strjoin.c ft_strjoin_free.c ft_strnew.c ft_isalpha.c ft_memcmp.c\
 ft_putendl_fd.c ft_strcmp.c ft_strlen.c ft_strnstr.c ft_isascii.c ft_memcpy.c\
 ft_putnbr.c ft_strcpy.c ft_strmap.c ft_strrchr.c ft_isdigit.c ft_memdel.c\
 ft_putnbr_fd.c ft_strdel.c ft_strmapi.c ft_strstr.c ft_isprint.c ft_memmove.c\
 ft_putstr.c ft_strdup.c ft_strncat.c ft_strsub.c ft_strsub_free.c ft_itoa.c\
 ft_memset.c ft_putstr_fd.c ft_strequ.c ft_strncmp.c ft_strtrim.c ft_strsplit.c\
 ft_strlcat.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
 ft_lstmap.c get_next_line.c v_malloc.c v_strdup.c v_strjoin.c v_strnew.c\
 v_strsub.c ft_itoa_ui.c ft_itoa_ul.c ft_itoa_ull.c ft_itoa_l.c ft_itoa_ll.c\
 convert_ui_to_other.c convert_ul_to_other.c convert_ull_to_other.c\
 ft_strjoin_free_s2.c ft_itoa_st.c convert_st_to_other.c swap_two_int.c\
 ft_exit.c ft_str_isdigit.c add_str_strtab.c del_str_strtab.c ft_strlen_strtab.c\
 ft_malloc.c swap_two_str.c ft_free.c v_free.c ft_putstrtab.c ft_strtabnew.c\
 ft_strtolower.c ft_abs.c ft_square.c ft_str_isint.c ft_putchar_col.c v_strtabnew.c\
 ft_putstr_col.c ft_putendl_col.c ft_putnbr_col.c v_strjoin_free.c ft_putnchar_fd.c\
 ft_putstr_col_fd.c ft_min.c ft_max.c ft_str_isint2.c v_strsplit.c ft_count_word.c\
 v_itoa.c ft_errno.c ft_multifree.c v_replace_free.c ft_strcutbeg.c ft_strchrstr.c\
 v_strndup.c add_int_inttab.c v_inttabnew.c ft_putstr_ret.c ft_putstr_fd_ret.c\
 ft_putendl_ret.c ft_putendl_fd_ret.c

O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rc $@ $^
	@ranlib $@
	@echo "\nlibft is ready :)"

%.o: $(C_DIR)%.c
	@clang -Wall -Wextra -Werror -I$(H_DIR) -o $@ -c $<
	@echo ".\c"

clean:
	@rm -f $(O_FILES) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

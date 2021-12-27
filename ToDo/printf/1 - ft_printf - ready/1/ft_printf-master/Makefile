NAME = libftprintf.a

C_FILES = ft_strcpy.c \
ft_strchr.c \
ft_putchar.c \
ft_putnbr.c \
ft_memset.c \
ft_putstr.c \
ft_strlen.c \
ft_isdigit.c \
ft_atoi.c \
ft_bzero.c \
ft_strncpy.c \
ft_strstr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strcat.c \
ft_strncat.c \
ft_tolower.c \
ft_toupper.c \
ft_isprint.c \
ft_isascii.c \
ft_isalpha.c \
ft_isalnum.c \
ft_strnstr.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_strdup.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlcat.c \
ft_strrchr.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strsplit.c \
ft_itoa.c \
ft_putendl.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_any.c \
ft_isspace.c \
ft_count_if.c \
ft_foreach.c \
ft_map.c \
ft_recursive_factorial.c \
ft_recursive_power.c \
ft_sqrt.c \
ft_strrev.c \
ft_swap.c \
ft_itoa_base.c \
ft_strchlen.c \
ft_strdiv.c \
ft_numlen.c \
ft_stroneleft.c \
ft_strnfill.c \
ft_putwstr.c \
ft_wstrlen.c \
ft_wstrdup.c \
ft_wstrcpy.c \
ft_wstrnew.c \
ft_wstrnfill.c \
ft_wstrjoin.c \
ft_longlongtoa.c \
ft_uitoa_base.c \
ft_putwchar.c \
ft_addtoa.c \
ft_ftoa.c \
ft_round.c

PRINTF_C_FILES = ft_printf.c \
./ft_printf_src/ft_pf_store.c \
./ft_printf_src/ft_pf_store_b.c \
./ft_printf_src/ft_pf_handle.c \
./ft_printf_src/ft_pf_struct_init.c \
./ft_printf_src/ft_pf_precision.c \
./ft_printf_src/ft_pf_width.c \
./ft_printf_src/ft_pf_handle_strings.c \
./ft_printf_src/ft_pf_sign.c \
./ft_printf_src/ft_pf_num_mod.c \
./ft_printf_src/ft_pf_handle_chars.c \
./ft_printf_src/ft_pf_alter.c \
./ft_printf_src/ft_pf_handle_f_mod.c \
./ft_printf_src/ft_pf_handle_print.c

O_FILES = ft_strcpy.o \
ft_strchr.o \
ft_putchar.o \
ft_putnbr.o \
ft_memset.o \
ft_putstr.o \
ft_strlen.o \
ft_isdigit.o \
ft_atoi.o \
ft_bzero.o \
ft_strncpy.o \
ft_strstr.o \
ft_strcmp.o \
ft_strncmp.o \
ft_strcat.o \
ft_strncat.o \
ft_tolower.o \
ft_toupper.o \
ft_isprint.o \
ft_isascii.o \
ft_isalpha.o \
ft_isalnum.o \
ft_strnstr.o \
ft_memcpy.o \
ft_memccpy.o \
ft_memmove.o \
ft_strdup.o \
ft_memchr.o \
ft_memcmp.o \
ft_strlcat.o \
ft_strrchr.o \
ft_memalloc.o \
ft_memdel.o \
ft_strnew.o \
ft_strdel.o \
ft_strclr.o \
ft_striter.o \
ft_striteri.o \
ft_strmap.o \
ft_strmapi.o \
ft_strequ.o \
ft_strnequ.o \
ft_strsub.o \
ft_strjoin.o \
ft_strtrim.o \
ft_strsplit.o \
ft_itoa.o \
ft_putendl.o \
ft_putchar_fd.o \
ft_putstr_fd.o \
ft_putendl_fd.o \
ft_putnbr_fd.o \
ft_lstnew.o \
ft_lstdelone.o \
ft_lstdel.o \
ft_lstadd.o \
ft_lstiter.o \
ft_lstmap.o \
ft_any.o \
ft_isspace.o \
ft_count_if.o \
ft_foreach.o \
ft_map.o \
ft_recursive_factorial.o \
ft_recursive_power.o \
ft_sqrt.o \
ft_strrev.o \
ft_swap.o \
ft_itoa_base.o \
ft_strchlen.o \
ft_strdiv.o \
ft_numlen.o \
ft_stroneleft.o \
ft_strnfill.o \
ft_putwstr.o \
ft_wstrlen.o \
ft_wstrdup.o \
ft_wstrcpy.o \
ft_wstrnew.o \
ft_wstrnfill.o \
ft_wstrjoin.o \
ft_longlongtoa.o \
ft_uitoa_base.o \
ft_putwchar.o \
ft_addtoa.o \
ft_ftoa.o \
ft_round.o

PRINTF_O_FILES = ft_printf.o \
ft_pf_store.o \
ft_pf_store_b.o \
ft_pf_handle.o \
ft_pf_struct_init.o \
ft_pf_precision.o \
ft_pf_width.o \
ft_pf_handle_strings.o \
ft_pf_sign.o \
ft_pf_num_mod.o \
ft_pf_handle_chars.o \
ft_pf_alter.o \
ft_pf_handle_f_mod.o \
ft_pf_handle_print.o

all: $(NAME)

$(NAME): $(O_FILES) $(PRINTF_O_FILES)
	ar -rc $(NAME) $(O_FILES) $(PRINTF_O_FILES)

$(PRINTF_O_FILES): $(PRINTF_C_FILES)
	gcc -Wall -Werror -Wextra -c $(PRINTF_C_FILES)

$(O_FILES): $(C_FILES)
	gcc -Wall -Werror -Wextra -c $(C_FILES)

clean:
	/bin/rm -f $(O_FILES) $(PRINTF_O_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
NAME = libft.a

SRC		=	printing/ft_putchar.c printing/ft_putchar_fd.c printing/ft_putwchar.c \
			printing/ft_putstr.c printing/ft_putwstr.c printing/ft_putnstr.c printing/ft_putstr_fd.c \
			printing/ft_putendl.c printing/ft_putendl_fd.c \
			printing/ft_putcolor.c printing/ft_putrainbow.c \
			printing/ft_putstr_array.c \
			printing/ft_putnbr.c printing/ft_putnbr_fd.c printing/ft_putnbr_base.c \
			numbers/ft_atoi.c numbers/ft_atoi_base.c numbers/ft_itoa.c numbers/ft_itoa_base.c \
			numbers/ft_atol.c numbers/ft_atoll.c numbers/ft_ltoa.c \
			numbers/ft_power.c numbers/ft_sqrt.c numbers/ft_sort_integer_table.c \
			numbers/ft_power_long.c numbers/ft_nbrlen.c \
			ft_tolower.c ft_toupper.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			memory/ft_memalloc.c memory/ft_memcpy.c memory/ft_memccpy.c \
			memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memdel.c \
			memory/ft_memmove.c memory/ft_memset.c \
			strings/ft_strlen.c strings/ft_strlen_char.c strings/ft_bzero.c \
			strings/ft_strnew.c strings/ft_strclr.c \
			strings/ft_strdel.c strings/ft_strdel_array.c \
			strings/ft_strcat.c strings/ft_strncat.c strings/ft_strlcat.c \
			strings/ft_strcpy.c strings/ft_strncpy.c strings/ft_strdup.c strings/ft_strndup.c \
			strings/ft_strchr.c strings/ft_strrchr.c strings/ft_strstr.c strings/ft_strnstr.c \
			strings/ft_strcmp.c strings/ft_strncmp.c strings/ft_strequ.c strings/ft_strnequ.c \
			strings/ft_striter.c strings/ft_striteri.c strings/ft_strmap.c strings/ft_strmapi.c \
			strings/ft_strsub.c strings/ft_strsplit.c strings/ft_strrev.c \
			strings/ft_strjoin.c strings/ft_strjoin_nolimit.c strings/ft_strjoin_array.c \
			strings/ft_strtrim.c strings/ft_strtrim_nolimit.c \
			strings/ft_strcount.c strings/ft_str_realloc.c \
			strings/ft_str_replace.c \
			get_next_line.c \
			lists/ft_lstnew.c lists/ft_lstdel.c lists/ft_lstdelone.c \
			lists/ft_lstadd_beginning.c lists/ft_lstadd_end.c \
			lists/ft_lstinsert_before.c lists/ft_lstinsert_after.c \
			lists/ft_lstiter.c lists/ft_lstmap.c lists/ft_lstconcat.c \
			printf/ft_max.c printf/ft_strnlen.c printf/ft_strwlen.c printf/ft_strnwlen.c \
			printf/ft_putnbr_max.c printf/ft_putnbr_fd_max.c printf/ft_putnbr_base_max.c \
			printf/ft_putnwstr.c

OBJ		= $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.
AR		= ar
ARFLAGS	= rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "\033[32mLIBFT COMPILED ✓\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Building: $@"

clean:
	@rm -f $(OBJ)
	@echo "\033[31mlibft objects deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mlibft.a deleted\033[0m"

re: fclean all

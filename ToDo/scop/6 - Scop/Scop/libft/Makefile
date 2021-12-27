# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/15 07:50:12 by ggroener          #+#    #+#              #
#    Updated: 2016/07/23 12:36:20 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Ofast

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME1 = ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_strsub_free.c \
			ft_strtrim_free.c \
			ft_exit.c \
			ft_free_2d_array.c \

SRCS_NAME2 = ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \

SRCS_NAME3 = ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_intlen.c \
			ft_printf_diff.c \
			ft_printf_hex.c \
			ft_printf_long.c \
			ft_printf_nbr_ld.c \
			ft_printf.c \

SRCS_NAME4 = ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strjoin_free1.c \
			ft_strjoin_free2.c \
			ft_strjoin_free3.c \
			ft_atod.c \
			ft_strcount.c \
			ft_strisdigit.c \
			ft_ltoa.c \
			ft_ultoa.c \
			ft_ltoa_base.c \
			ft_ultoa_base.c \
			ft_putwchar.c \
			ft_putwchar_fd.c \
			ft_putwstr.c \
			ft_putwstr_fd.c \
			ft_wstrlen.c \
			ft_wstrsub.c \
			ft_atol.c \
			ft_putul.c \
			ft_putul_fd.c \
			get_next_line.c 

SRCS4 = $(addprefix $(SRCS_PATH), $(SRCS_NAME4))

SRCS3 = $(addprefix $(SRCS_PATH), $(SRCS_NAME3))

SRCS2 = $(addprefix $(SRCS_PATH), $(SRCS_NAME2))

SRCS1 = $(addprefix $(SRCS_PATH), $(SRCS_NAME1))

SRCS = $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4)

HEADER = 	$(INCLUDES_PATH)libft.h \

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME1:.c=.o) $(SRCS_NAME2:.c=.o) $(SRCS_NAME3:.c=.o) $(SRCS_NAME4:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

all: odir $(NAME)

$(NAME): $(OBJS)
	@echo " - Making $(NAME)"
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@clear
	@echo "Make Done!"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@echo " - Cleaning objs"
	@rm -f $(OBJS)
	@clear
	@echo "clean Done!"

fclean: clean
	@echo " - Cleaning executable"
	@rm -f $(NAME)
	@clear
	@echo "fclean Done!"

re: fclean all
	@echo "re Done!"

format: norm

norm:
	@clear
	@echo "Norminette:"
	@norminette $(HEADER)
	@echo "Header Done:"
	@norminette $(SRCS1)
	@echo "SRCS1 Done:"
	@norminette $(SRCS2)
	@echo "SRCS2 Done:"
	@norminette $(SRCS3)
	@echo "SRCS3 Done:"
	@norminette	$(SRCS4)
	@echo "SRCS4 Done:"
	
.PHONY: clean fclean re odir

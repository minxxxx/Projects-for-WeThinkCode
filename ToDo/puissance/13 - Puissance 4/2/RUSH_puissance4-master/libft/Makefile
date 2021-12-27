# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 17:40:06 by thou              #+#    #+#              #
#    Updated: 2017/05/10 16:23:31 by thou             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK					=	\033[30;1m
RED						=	\033[31;1m
GREEN					=	\033[32;1m
YELLOW					=	\033[33;1m
BLUE					=	\033[34;1m
PURPLE					=	\033[35;1m
CYAN					=	\033[36;1m
WHITE					=	\033[37;1m
RESET					=	\033[0m
CLEAR					=	\033[H\e[J

NAME					=	libft.a
FLAG					=	-Wall -Wextra -Werror -Iincludes
SRC_DIR					=	src/
OBJ_DIR					=	obj/
LIBC_DIR				=	libc/
SUPPLEMENTAIRE_DIR		=	supplementaire/
BONUS_DIR				=	bonus/
AUTRES_DIR				=	autres/
GET_NEXT_LINE_DIR		=	get_next_line/
FT_PRINTF_DIR			=	ft_printf/
LIBC					=	ft_atoi.c\
							ft_isdigit.c\
							ft_memcpy.c\
							ft_strcmp.c\
							ft_strncat.c\
							ft_strstr.c\
							ft_bzero.c\
							ft_isprint.c\
							ft_memmove.c\
							ft_strcpy.c\
							ft_strncmp.c\
							ft_tolower.c\
							ft_isalnum.c\
							ft_memccpy.c\
							ft_memset.c\
							ft_strdup.c\
							ft_strncpy.c\
							ft_toupper.c\
							ft_isalpha.c\
							ft_memchr.c\
							ft_strcat.c\
							ft_strlcat.c\
							ft_strnstr.c\
							ft_isascii.c\
							ft_memcmp.c\
							ft_strchr.c\
							ft_strlen.c\
							ft_strrchr.c
SUPPLEMENTAIRE			=	ft_itoa.c ft_putendl.c ft_putstr_fd.c ft_striteri.c ft_strnew.c ft_memalloc.c ft_putendl_fd.c ft_strclr.c ft_strjoin.c ft_strsplit.c ft_memdel.c ft_putnbr.c ft_strdel.c ft_strmap.c ft_strsub.c ft_putchar.c ft_putnbr_fd.c ft_strequ.c ft_strmapi.c ft_strtrim.c ft_putchar_fd.c ft_putstr.c ft_striter.c ft_strnequ.c
BONUS					=	ft_lstadd.c\
							ft_lstdel.c\
							ft_lstdelone.c\
							ft_lstiter.c\
							ft_lstmap.c\
							ft_lstnew.c
AUTRES					=	ft_atoi_base.c ft_clamp.c ft_isupper.c ft_strjoinchar.c ft_strsubc.c ft_islower.c
AUTRES					+=	ft_itoa_base.c ft_strjoinfree.c ft_wordnb.c ft_uintmaxtoa_base.c ft_strjoinfree2.c
AUTRES					+=	ft_intmaxtoa_base.c ft_stricmp.c ft_charnb.c ft_iswhitespace.c
GET_NEXT_LINE			=	get_next_line.c
FT_PRINTF				=	ft_printf.c ft_vfprintf.c ft_printf0.c ft_printf1.c ft_printf2.c ft_printnesp.c ft_printfhl.c ft_printfh.c
SRC_BASE				=	$(addprefix $(LIBC_DIR), $(LIBC))\
							$(addprefix $(SUPPLEMENTAIRE_DIR), $(SUPPLEMENTAIRE))\
							$(addprefix $(BONUS_DIR), $(BONUS))\
							$(addprefix $(AUTRES_DIR), $(AUTRES))\
							$(addprefix $(GET_NEXT_LINE_DIR), $(GET_NEXT_LINE))\
							$(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF))
SRCS					=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS					=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB						=	$(words $(SRC_BASE))
INDEX					=	1

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[65D✅ \033[40C\033[K\c"
	@echo "\n\033[K\033[48;5;15;38;5;25;1mMAKE $(NAME) DONE$(RESET)"
	@echo "\033[?25h\c"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$((89-$(PERCENT)/16))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@echo "\033[?25l\033[65D\033[1A"
	@printf "\r\033[38;5;11m⌛ MAKE	$(NAME): \033[48;5;$(COLOR)m%*s\033[45;1m%*s$(RESET)$(YELLOW) %3d%% $(RESET) \033[38;5;11m %20s$(RESET)" $(DONE) "" $(TO_DO) "" $(PERCENT) "$(notdir $@)"
	@mkdir -p $(dir $@)
	@/usr/bin/gcc $(FLAG) -c $< -o $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

f: fclean

clean:
	@echo "$(YELLOW)Clean	objs⌛\c$(RESET)"
	@/bin/rm -rf $(OBJ_DIR)
	@echo "\033[D\033[K$(GREEN)			[ OK ]$(RESET)"

fclean:	clean
	@echo "$(YELLOW)Clean	$(NAME)⌛\c$(RESET)"
	@/bin/rm -rf $(NAME)
	@echo "\033[D\033[K$(GREEN)			[ OK ]$(RESET)"

re: fclean all

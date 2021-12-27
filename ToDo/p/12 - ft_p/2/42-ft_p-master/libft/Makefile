# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/28 18:42:36 by jtranchi          #+#    #+#              #
#    Updated: 2017/08/09 16:59:44 by jtranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror

SRC= ft_memset.c\
	 ft_bzero.c\
	 ft_memcpy.c\
	 ft_memccpy.c\
	 ft_memmove.c\
	 ft_memchr.c\
	 ft_memcmp.c\
	 ft_strlen.c\
	 ft_strdup.c\
	 ft_strcpy.c\
	 ft_strncpy.c\
	 ft_strcat.c\
	 ft_strncat.c\
	 ft_strlcat.c\
	 ft_strchr.c\
	 ft_strrchr.c\
	 ft_strstr.c\
	 ft_strnstr.c\
	 ft_strcmp.c\
	 ft_strncmp.c\
	 ft_atoi.c\
	 ft_isalpha.c\
	 ft_isdigit.c\
	 ft_isalnum.c\
	 ft_isascii.c\
	 ft_isprint.c\
	 ft_toupper.c\
	 ft_tolower.c\
	 ft_memalloc.c\
	 ft_memdel.c\
	 ft_strnew.c\
	 ft_strdel.c\
	 ft_strclr.c\
	 ft_putchar.c\
	 ft_putstr.c\
	 ft_putendl.c\
	 ft_putnbr.c\
	 ft_striter.c\
	 ft_striteri.c\
	 ft_strmap.c\
	 ft_strmapi.c\
	 ft_strequ.c\
	 ft_strnequ.c\
	 ft_strsub.c\
	 ft_strjoin.c\
	 ft_strtrim.c\
	 ft_spacesplit.c\
	 ft_strsplit.c\
	 ft_quotes.c\
	 ft_itoa.c\
	 ft_putchar_fd.c\
	 ft_putstr_fd.c\
	 ft_putendl_fd.c\
	 ft_putnbr_fd.c\
	 ft_lstnew.c\
	 ft_lstdelone.c\
	 ft_lstdel.c\
	 ft_lstadd.c\
	 ft_lstiter.c\
	 ft_strjoin_nf.c\
	 ft_len_nospace.c\
	 ft_isspace.c\
	 ft_freestrtab.c\
	 get_next_line.c

LIB = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
OBJ = $(SRC:.c=.o)
RM = rm -rf
RANLIB = ranlib
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: $(LIB)

$(LIB): start $(OBJ)
	@echo "\033[K$(CY)[LIBFT] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	@$(AR) $(LIB) $(OBJ)
	@$(RANLIB) $(LIB)

nohd: $(OBJ)
	@echo "\033[K$(CY)[LIBFT] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	@$(AR) $(LIB) $(OBJ)
	@$(RANLIB) $(LIB)

nohdclean:
	@echo "\033[K$(CY)[LIBFT] :$(CE) $(CG)Cleaning object files...$(CE)\033[1A";
	@$(RM) $(OBJ)

nohdfclean: nohdclean
	@echo "\033[K$(CY)[LIBFT] :$(CE) $(CG)Cleaning Library...$(CE)\033[1A";
	@$(RM) $(LIB)


start:
	@echo "\n\n"
	@echo "	$(CG)                          00000000000000000000$(CE)";
	@echo "	$(CG)                       00000000000000000000000000$(CE)";
	@echo "	$(CG)                    000000000000000000000000000000000         00   0000$(CE)";
	@echo "	$(CG)    000000        00000000000000000000000000000000000000       000000000$(CE)";
	@echo "	$(CG) 00 000000      0000000000    0000000000000    0000000000       0000000$(CE)";
	@echo "	$(CG) 000000000     0000000000      00000000000      00000000000    0000000$(CE)";
	@echo "	$(CG)   0000000    00000000000      00000000000      0000000000000000000000$(CE)";
	@echo "	$(CG)   00000000000000000000000    0000000000000    00000000000000  00000$(CE)";
	@echo "	$(CG)    000000000000000000000000000000000000000000000000000000000     000$(CE)";
	@echo "	$(CG)     000   000000000000000000000000000000000000000000000000000     0000$(CE)";
	@echo "	$(CG)    0000   000000000000000000000000000000000000000000000000000       000$(CE)";
	@echo "	$(CG)    000    0000000000000000000000000000000000000000000000 0000000000000000$(CE)";
	@echo "	$(CG)   0000000000000  0000000000000000000000000000000000000   00000000000000000$(CE)";
	@echo "	$(CG)   0000000000000   0000000000000000000000000000000000     00000000000$(CE)";
	@echo "	$(CG)  0000       0000    000000000000000000000000000000      000$(CE)";
	@echo "	$(CG)             00000     0000000000000000000000000         00$(CE)";
	@echo "	$(CG)               0000          000000000000000           000$(CE)";
	@echo "	$(CG)                00000                                0000$(CE)";
	@echo "	$(CG)                 000000      00000000000000        0000$(CE)";
	@echo "	$(CG)                   00000000     0000000000000   000000$(CE)";
	@echo "	$(CG)                      00000000000  0000000000000000$(CE)";
	@echo "	$(CG)                         000000000000000000000$(CE)";
	@echo "	$(CG)                                 00000000000000$(CE)";
	@echo "	$(CG)                                     00000000000$(CE)";
	@echo "	$(CG)                                      0000000000$(CE)";
	@echo "	$(CG)                                       0000000$(CE)";
	@echo "\n\n"
	@echo "		$(CG)      :::       :::::::::::::::::::: ::::::::::::::::::::: $(CE)";
	@echo "		$(CG)     :+:           :+:    :+:    :+::+:           :+:      $(CE)";
	@echo "		$(CG)    +:+           +:+    +:+    +:++:+           +:+       $(CE)";
	@echo "		$(CG)   +#+           +#+    +#++:++#+ :#::+::#      +#+        $(CE)";
	@echo "		$(CG)  +#+           +#+    +#+    +#++#+           +#+         $(CE)";
	@echo "		$(CG) #+#           #+#    #+#    #+##+#           #+#          $(CE)";
	@echo "		$(CG)############################## ###           ###           $(CE)";
%.o: %.c
	@echo "\033[K$(CY)[LIBFT] :$(CE) $(CG)Compiling $<$(CE)\033[1A";
	@$(CC) $(CFLAGS) -c $< -o $@

clean: start
	@echo "\033[K$(CY)[LIBFT] :$(CE) $(CG)Cleaning object files...$(CE)\033[1A";
	@$(RM) $(OBJ)

fclean: start clean
	@echo "\033[K$(CY)[LIBFT] :$(CE) $(CG)Cleaning Library...$(CE)\033[1A";
	@$(RM) $(LIB)

re: fclean all

.PHONY: all clean fclean re

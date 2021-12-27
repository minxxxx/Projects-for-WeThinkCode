# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/22 14:56:46 by sasiedu           #+#    #+#              #
#    Updated: 2017/06/27 02:20:57 by sasiedu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

NAME2 = ft_otool

CC = /usr/bin/gcc

CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -rf

SRCS = tools.c nm.c file.c mach.c mach2.c mach3.c process_nm.c args.c tools2.c \
		swap.c args2.c mach_otool.c print_otool.c process_tool.c \
		otool_headers.c

OBJS = $(SRCS:.c=.o)

all: ${NAME}

$(NAME): $(OBJS)
	@echo "compiling ft_nm"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L. -lft
	@echo "ft_nm built"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME2) -L. -lft
	@echo "ft_otool built"

%.o : %.c
	$(CC) -c $(CFLAGS) -I . $<

clean:
	-${RM} ${OBJS}

fclean: clean
	-${RM} ${NAME}
	-${RM} ${NAME2}

re: fclean all

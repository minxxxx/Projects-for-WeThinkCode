# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 08:57:02 by jbadenho          #+#    #+#              #
#    Updated: 2017/11/30 11:01:27 by jbadenho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

HDR = libft/libft.h\
	  includes/*.h

SRC1 = srcs/Main/*.c

SRC2 = srcs/Builtin/*.c

SRC3 = srcs/Heredoc/*.c

SRC4 = srcs/Bonus/*.c

SRC5 = srcs/Pipe_Redirects/*.c

SRC6 = srcs/Globbing/*.c

SRC7 = srcs/History/*.c

SRC8 = srcs/Termcap/*.c

SRC = $(SRC1) $(SRC2) $(SRC3) $(SRC4) $(SRC5) $(SRC6) $(SRC7) $(SRC8)

FLAGS = -iquotelibft -iquoteincludes -Wall -Werror -Wextra -g3 -g -pedantic

LIBFT = -L libft/ -lft

OPT = objs/*.o

define p1
tput cuu 1
echo "                                                                         "
tput cuu 1
tput setaf 1
echo $1
tput sgr0
endef

define p2
tput cuu 1
echo "                                                                         "
tput cuu 1
tput setaf 3
echo $1
tput sgr0
endef

define p3
tput cuu 1
echo "                                                                         "
tput cuu 1
tput setaf 2
echo $1
tput sgr0
endef

define colourecho
tput blink
tput setaf 6
@echo $1
tput sgr0
endef

define colourecho1
tput setaf 6
@echo $1
tput sgr0
endef

define colourecho2
tput setaf 87
@echo $1
tput sgr0
endef

define green
tput setaf 2
@echo $1
tput sgr0
endef

define bar
echo $1
tput sgr0
endef

all: compiling
	@$(MAKE) bar -s
	@$(call colourecho2, "Done Compiling!\n")
	
compiling: norme
	@$(call colourecho2, "Compiling $(NAME):\n")
	@export CLICOLOR='1'
	@export TERM='xterm-256color'
	@rm -rf *.dSYM
	@make -s -C libft/ fclean && make -s -C libft/
	@gcc -c $(HDR) $(SRC) $(FLAGS)
	@mv *.o objs/
	@gcc -o $(NAME) $(OPT) $(LIBFT) $(FLAGS) -ltermcap
	
norme: title
	@$(call colourecho2, "Norminette Started:")
	@$(call green, "Main:")
	@norminette $(SRC1) 2>- | cut -d'/' -f4
	@$(call green, "Builtin:")
	@norminette $(SRC2) 2>- | cut -d'/' -f4
	@$(call green, "Heredoc:")
	@norminette $(SRC3) 2>- | cut -d'/' -f4
	@$(call green, "Bonus:")
	@norminette $(SRC4) 2>- | cut -d'/' -f4
	@$(call green, "Pipe and redirects:")
	@norminette $(SRC5) 2>- | cut -d'/' -f4
	@$(call green, "Globbing:")
	@norminette $(SRC6) 2>- | cut -d'/' -f4
	@$(call green, "History:")
	@norminette $(SRC7) 2>- | cut -d'/' -f4
	@$(call green, "Header:")
	@norminette includes/ft_shell.h 2>- | cut -d'/' -f3
	@$(call green, "Termcaps:")
	@norminette $(SRC8) 2>- | cut -d'/' -f4
	@$(call colourecho2, "Norminette Completed!\n")

title: file
	@rm -rf objs
	@mkdir objs
	@$(call colourecho, "\n---------------------------")
	@$(call colourecho, "-----RUNNING MAKEFILE!-----")
	@$(call colourecho, "---------------------------\n")
	@sleep 1
	@clear
	@$(call colourecho1, "\n---------------------------")
	@$(call colourecho1, "-----RUNNING MAKEFILE!-----")
	@$(call colourecho1, "---------------------------\n")
	@$(call colourecho2, "Creating Author file:")
	@cat -e author
	@$(call colourecho2, "Author File Created!\n")

file:
	@clear
	@if [ ! -f author ]; then \
		echo "amkhuma" >> author; \
		echo "ftait" >> author; \
		echo "mnaidoo" >> author; \
		echo "rde-beer" >> author; \
		echo "jbadenho" >> author; \
	fi

bar:
	@$(call p1, "\r[#                       ]")
	@sleep 0.1
	@$(call p1, "\r[##                      ]")
	@sleep 0.1
	@$(call p1, "\r[###                     ]")
	@sleep 0.1
	@$(call p1, "\r[####                    ]")
	@sleep 0.1
	@$(call p1, "\r[#####                   ]")
	@sleep 0.1
	@$(call p1, "\r[######                  ]")
	@sleep 0.1
	@$(call p1, "\r[#######                 ]")
	@sleep 0.1
	@$(call p1, "\r[########                ]")
	@sleep 0.1
	@$(call p1, "\r[#########               ]")
	@sleep 0.1
	@$(call p1, "\r[##########              ]")
	@sleep 0.1
	@$(call p2, "\r[###########             ]")
	@sleep 0.1
	@$(call p2, "\r[############            ]")
	@sleep 0.1
	@$(call p2, "\r[#############           ]")
	@sleep 0.1
	@$(call p2, "\r[##############          ]")
	@sleep 0.1
	@$(call p2, "\r[###############         ]")
	@sleep 0.1
	@$(call p2, "\r[################        ]")
	@sleep 0.1
	@$(call p2, "\r[#################       ]")
	@sleep 0.1
	@$(call p2, "\r[##################      ]")
	@sleep 0.1
	@$(call p2, "\r[###################     ]")
	@sleep 0.1
	@$(call p3, "\r[####################    ]")
	@sleep 0.1
	@$(call p3, "\r[#####################   ]")
	@sleep 0.1
	@$(call p3, "\r[######################  ]")
	@sleep 0.1
	@$(call p3, "\r[####################### ]")
	@sleep 0.1
	@$(call p3, "\r[########################]")

clean:
	@/bin/rm -f $(OPT)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf *.gch
	@/bin/rm -rf objs

re: fclean all

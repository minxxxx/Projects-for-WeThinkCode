# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adomingu <adomingu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/01 17:36:17 by adomingu          #+#    #+#              #
#    Updated: 2016/11/22 19:17:22 by vsteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 	SRC_NAME = main.c \
	   env.c \
	   list.c \
	   utils.c \
	   builtins.c \
		 builtin_print.c \
	   list2.c \
	   exec.c \
	   singelton.c \
	   term.c \
	   boucle.c \
		 ft_string.c \
		 line.c \
		 ft_is_x_1.c \
		 ft_is_x_2.c \
		 list_parse.c \
		 parse.c \
		 parse_add_command.c \
		 parse_nb_arg.c \
		 parse_function.c \
		 parse_error.c \
		 parse_error_verif.c \
		 parse_split_cmd.c \
		 fd_function_1.c \
		 handle_aggr.c \
		 handle_redir.c \
		 handle_redir_check_redir.c \
		 handle_redir_error.c \
		 is_parse.c \
		 quote.c \
		 list_heredoc.c \
		 exit_builtin.c \
		 handle_pipe.c \
		 handle_pipe_spawn_proc.c \
		 echo.c \
		 history_1.c\
		 history_2.c\
		 history_builtin_1.c \
		 history_builtin_2.c \
		 history_flag_none_1.c \
		 history_flag_none_2.c \
		 history_flag_c.c \
		 history_flag_d.c \
		 history_flag_a.c \
		 history_flag_n.c \
		 history_flag_r.c \
		 history_flag_w.c \
		 history_flag_p.c \
		 history_flag_s.c \
		 parsing_advanced.c \
		 parsing_advanced_subs_1.c \
		 parsing_advanced_subs_2.c \
		 parsing_advanced_var_1.c \
		 parsing_advanced_var_2.c \
		 parsing_advanced_tilde.c \
		 parsing_advanced_function.c \
		 vid_inv.c \
		 builtin_env.c \
		 builtin_env_function.c \
		 setvar.c \
		 history_exit.c \
		 autocomplete.c \
		 autocomplete_function_1.c \
		 autocomplete_function_2.c \
		 autocomplete_find_list_auto.c \
		 unset.c \
		 export.c \
		 signals.c \
		 exit.c \
		 cd_main.c \
		 sigwinch.c \
		 sigwinch_2.c \
		 sigint.c \
		 move.c\
		 move_simple.c\
		 get_things.c\
		 words.c\
		 delete_list_1.c \
		 delete_list_2.c \
		 exit.c \
		 cd_main.c \
		 cd_function_1.c \
		 cd_function_2.c \
		 cd_function_3.c \
		 cd_function_4.c \
		 cd_path_1.c \
		 cd_path_2.c \
		 cd_is_x_1.c \
		 cd_is_x_2.c \
		 cd_print.c \
		 sigwinch.c \
		 sigwinch_2.c \
		 sigint.c \
		 quote_is.c \
		 page_down.c \
		 page_up.c \
		 exec_cmd.c \
		 exec_file.c \
		 print_errors.c \
		 cmd_not_found.c \
		 move_up_history.c \
		 move_down_history.c \
		 create_history.c \
		 boucle_add_or_del_char.c \
		 boucle_move.c \
		 boucle_move_2.c \
		 boucle_home_end.c \
		 boucle_mode_copy.c \
		 boucle_mode_copy_init_or_end.c \
		 boucle_move_history.c \
		 boucle_ctrl_d_and_l.c

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes

NAME = 42sh
NAMELIB = lib$(NAME).a

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

LFLAGS = -ltermcap

LIB_DIR=./lib
STATIC_LIBS= $(LIB_DIR)/libft.a

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	@mkdir -p $(LIB_DIR)
	make -C libsrcs/libft
	@ar -cr $(NAMELIB) $^
	@ranlib $(NAMELIB)
	$(CC) $(CFLAGS) $(NAMELIB) $(STATIC_LIBS) $(LFLAGS) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rmdir -p $(OBJ_PATH) 2> /dev/null || true
	make -C libsrcs/libft clean

fclean: clean
	rm -fv $(NAME) $(NAMELIB)
	make -C libsrcs/libft fclean
	@rmdir lib 2> /dev/null || true

re: fclean all

leaks: all
	 valgrind --leak-check=full ./42sh

check: $(NAME)
	@echo "####################################"
	@echo "##   Test Driven Development      ##"
	@echo "##                                ##"
	@echo "##   . is OK                      ##"
	@echo "##   F is ERROR                   ##"
	@echo "##   E is CRITICAL                ##"
	@echo "##                                ##"
	@echo "##   valgrind in PATH ?           ##"
	@echo "##   tests made from stdin        ##"
	@echo "##   NO termcaps tests            ##"
	@echo "####################################"
	@echo "VALGRIND=TRUE for valgrind: VALGRIND=\"$(VALGRIND)\""
	@python -m unittest discover tests/
	@echo "ALL TESTS SUCCEED ASK FOR MORE TESTS"

.PHONY : all clean fclean re check

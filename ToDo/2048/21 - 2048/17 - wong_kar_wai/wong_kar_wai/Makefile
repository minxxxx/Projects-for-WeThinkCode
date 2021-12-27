# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 20:27:52 by jaguillo          #+#    #+#              #
#    Updated: 2015/03/01 16:02:49 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# Config
#
# Accepted exernal vars:
#  DEBUG_MODE	(0)		Enable debug mode
#

NAME = game_2048

H_DIR = h
C_DIR = srcs
O_DIR = o

# GCC flags
LINKS = -I$(H_DIR) -Ilibft/ -Llibft/ -lft -lncurses

FLAGS = -Wall -Wextra -Werror -O2
DEBUG_FLAGS = -Wall -Wextra -g -D DEBUG_MODE

# Dirs containing a Makefile to execute (all, clean and fclean)
MAKES = libft/

# Libft config
export FT_CONFIG = -D EMAL_ALL

#
# Internal
#

ifeq ($(DEBUG_MODE),)
	export DEBUG_MODE = 0
endif

ifeq ($(DEBUG_MODE),1)
	FLAGS = $(DEBUG_FLAGS)
endif

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.c")
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

# Default rule
# Build sub-makefiles and the project
all:
	@$(foreach lib,$(MAKES),make -C $(lib);)
	@make -j4 $(NAME)

# Build the project
$(NAME): $(O_FILES)
	@gcc $(FLAGS) -o $@ $^ $(LINKS) && printf "\033[0;32m" || printf "\033[0;31m"
	@printf "%-34s \033[1;30m<<--\033[0;0m\n" "$@"

# Compile a source file
$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(LINKS) -o $@ -c $< \
	&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;31m$@\033[0;0m\n" "$<" \
		&& exit 1)

# Enable debug mode and build all
debug: _debug all

# Clean all objects files and sub-makefiles
clean: _clean
	@$(foreach lib,$(MAKES),make -C $(lib) clean;)

# Clean all compiled files and sub-makefiles
fclean: _fclean
	@$(foreach lib,$(MAKES),make -C $(lib) fclean;)

# Clean all and rebuild
re: fclean all

# Clean all, enable debug mode and rebuild
rebug: fclean debug

# Clean objects files
_clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null

# Clean compiled files
_fclean: _clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

# Clean compiled files rebuild
_re: _fclean all

# Clean compiled files, enable debug mode and rebuild
_rebug: _fclean debug

# Enable debug mode
_debug:
	$(eval FLAGS = $(DEBUG_FLAGS))
	$(eval DEBUG_MODE = 1)

.PHONY: all debug clean fclean re rebug _clean _fclean _re _rebug _debug

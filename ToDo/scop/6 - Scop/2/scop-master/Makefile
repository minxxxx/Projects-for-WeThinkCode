#

# Executable name
NAME := scop

# Project directories
DIRS := srcs include

# Git submodule to init
MODULES := libft
# Makefiles to call
LIBS := libft

# Compilation and linking flags
FLAGS := -Wall -Wextra -O2
# Compilation flags
HEADS := $(addprefix -I,$(DIRS)) -I libft/includes
# Linking flags
LINKS :=
ifeq ($(shell uname),Darwin)
    FLAGS += -D MAC_OS_MODE=1 -I ~/.brew/include
    LINKS := -Llibft -lft -L ~/.brew/lib -lglfw3 -lm -framework OpenGL
else
    LINKS := -Llibft -lft -lglfw -lGL -lGLEW -lm
endif

# Objects directory
O_DIR := o

# Depend file name
DEPEND := depend.mk

# tmp
MODULE_RULES := $(addsuffix /.git,$(MODULES))

# thread:
	# make -j4 all

# Default rule (need to be before any include)
all: $(MODULE_RULES) cog libs $(NAME)

cog:
	cog.py -I conf -rU include/configuration/cog_enums.h
	cog.py -I conf -rU include/configuration/cog_meshfill.h
	cog.py -I conf -rU srcs/configuration/cog_loadconf1.c
	cog.py -I conf -rU srcs/configuration/cog_loadconf2.c
	cog.py -I conf -rU srcs/configuration/cog_meshfill1.c
	cog.py -I conf -rU srcs/configuration/cog_meshfill2.c

# Include $(O_FILES) and dependencies
-include $(DEPEND)

# Linking
$(NAME): $(LIBS_DEPEND) $(O_FILES)
	clang $(FLAGS) -o $@ $(O_FILES) $(LINKS) && printf '\033[32m$@\033[0m\n'

# Compiling
$(O_DIR)/%.o:
	clang $(FLAGS) $(HEADS) -c $< -o $@ && printf '\033[32m$<\033[0m\n'

# Init submodules
$(MODULE_RULES):
	git submodule init $(@:.git=)
	git submodule update $(@:.git=)

# Create obj directories
$(O_DIR)/%/:
	mkdir -p $@

# Set debug mode and make
debug: _debug all

# Clean, set debug mode and make
rebug: fclean debug

# Clean obj files
clean:
	rm -f $(O_FILES)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Clean and make
re: fclean all

# Update $(DEPEND) file
$(DEPEND): Makefile
	makemake || printf "\033[31mCannot remake $(DEPEND)\033[0m\n"

# Set debug flags
_debug:
	$(eval FLAGS := $(DEBUG_FLAGS))

.SILENT:
.PHONY: all $(LIBS) clean fclean re debug rebug _debug cog

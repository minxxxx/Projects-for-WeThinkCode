# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2018/02/20 12:04:56 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECTA ?= checker
PROJECTB ?= push_swap
PROJECTC ?= visu
WFLAGS = -Werror -Wextra -Wall
RCFLAGS = $(WFLAGS) -O2
CC ?= gcc

INC_PATH = include
SRC_PATH = src
OBJ_DIR ?= obj
OBJ_PATH ?= $(OBJ_DIR)/rel
3TH_PATH = vendor

LIBS = ft
LIB_NAME = ft
3TH_NAME = libft
SRC_NAME = op.c ps.c stack.c opti.c quicksort.c selectsort.c sort.c
SRCA_NAME = $(SRC_NAME) checker.c
SRCB_NAME = $(SRC_NAME) push_swap.c
SRCC_NAME = $(SRC_NAME) draw.c visu.c

3TH = $(addprefix $(3TH_PATH)/, $(3TH_NAME))
OBJA = $(addprefix $(OBJ_PATH)/, $(SRCA_NAME:.c=.o))
OBJB = $(addprefix $(OBJ_PATH)/, $(SRCB_NAME:.c=.o))
OBJC = $(addprefix $(OBJ_PATH)/, $(SRCC_NAME:.c=.o))
LNK = $(addprefix -L, $(3TH))
INC = $(addprefix -I, $(INC_PATH) $(addsuffix /include, $(3TH)))
LIB = $(addprefix -l, $(LIB_NAME))
DEP = $(OBJ:%.o=%.d)

PRINTF=test $(VERBOSE)$(TRAVIS) || printf
3DE = $(shell echo "$(3TH_NAME)" | sed -E "s|([\.a-zA-Z]+)|$(3TH_PATH)/\1/\1.a|g")

all:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) &&) true
endif
	@$(PRINTF) "%-20s" "$(PROJECTA): exe"
	+$(MAKE) -j4 $(PROJECTA) "CFLAGS = $(RCFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"
	@$(PRINTF) "%-20s" "$(PROJECTB): exe"
	+$(MAKE) -j4 $(PROJECTB) "CFLAGS = $(RCFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"
	@$(PRINTF) "%-20s" "$(PROJECTC): exe"
	+$(MAKE) -j4 $(PROJECTC) "CFLAGS = $(RCFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

$(PROJECTA): $(3DE) $(OBJA)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	$(CC) $(CFLAGS) $(INC) $(LNK) $(OBJA) $(LIB) -o $(PROJECTA)

$(PROJECTB): $(3DE) $(OBJB)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	$(CC) $(CFLAGS) $(INC) $(LNK) $(OBJB) $(LIB) -o $(PROJECTB)

$(PROJECTC): $(3DE) $(OBJC)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	$(CC) $(CFLAGS) $(INC) $(LNK) $(OBJC) $(LIB) -lncurses -o $(PROJECTC)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$<"
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(dir $(OBJA) $(OBJB))

clean:
	rm -rf $(OBJ_DIR)
	@$(PRINTF) "%-20s\033[32m✔\033[0m\n" "$(PROJECTB): $@"

fclean: clean
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) fclean &&) true
endif
	rm -f $(PROJECTA){,.san,.dev}
	rm -f $(PROJECTB){,.san,.dev}
	rm -f $(PROJECTC){,.san,.dev}
	@$(PRINTF) "%-20s\033[32m✔\033[0m\n" "$(PROJECTB): $@"

re: clean all

norme: all
	norminette include src vendor/lib*/{include,src}

test: all
	./test.sh

bench:
	./bench.sh 3
	./bench.sh 5
	./bench.sh 100
	./bench.sh 500

-include $(DEP)

ifndef VERBOSE
 ifndef TRAVIS
.SILENT:
 endif
endif

.PHONY: all, $(PROJECTA), $(PROJECTB), $(PROJECTC), clean, fclean, re, norme, test, bench

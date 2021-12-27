SRC = main.c
SRC += syscall.c
SRC += errno.c
SRC += signal.c
SRC += strace_lib.c
SRC += strace_lib2.c

NAME = ft_strace
SRCDIR = srcs/
OBJDIR = objs/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))


LIB = libft/libft.a
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m
INC = -I ./includes/

all: start lib $(NAME)

lib:
	-@make -C libft nohd
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(FLAG) $(INC) $(LIB);
	@echo "\033[K$(CY)[FT_STRACE] :$(CE) $(CG)Compiling ft_strace$(CE)";


start:
	@echo "\n";
	@echo "			$(CG)      :::::::::: :::::::::::           :::::::: ::::::::::: :::::::::      :::      ::::::::  ::::::::::   $(CE)";
	@echo "			$(CG)     :+:            :+:              :+:    :+:    :+:     :+:    :+:   :+: :+:   :+:    :+: :+:           $(CE)";
	@echo "			$(CG)    +:+            +:+              +:+           +:+     +:+    +:+  +:+   +:+  +:+        +:+            $(CE)";
	@echo "			$(CG)   :#::+::#       +#+              +#++:++#++    +#+     +#++:++#:  +#++:++#++: +#+        +#++:++#        $(CE)";
	@echo "			$(CG)  +#+            +#+                     +#+    +#+     +#+    +#+ +#+     +#+ +#+        +#+              $(CE)";
	@echo "			$(CG) #+#            #+#              #+#    #+#    #+#     #+#    #+# #+#     #+# #+#    #+# #+#               $(CE)";
	@echo "			$(CG)###            ###    ########## ########     ###     ###    ### ###     ###  ########  ##########         $(CE)";
	@echo "\n";

$(OBJ): $(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "\033[K$(CY)[FT_STRACE] :$(CE) $(CG)Compiling $<$(CE)\033[1A";
	@gcc $(FLAG) -c $< -o $@ $(INC)

clean: start
	@echo "$(CY)[FT_STRACE] :$(CE) $(CG)Cleaning ft_strace objects$(CE)";
	-@make -C libft nohdclean;
	@/bin/rm -rf $(OBJ);

fclean: start clean
	@echo "\033[K$(CY)[FT_STRACE] :$(CE) $(CG)Cleaning binairies ...$(CE)";
	-@make -C libft nohdfclean;
	@/bin/rm -f $(NAME);

re: fclean all

.PHONY: all clean fclean re

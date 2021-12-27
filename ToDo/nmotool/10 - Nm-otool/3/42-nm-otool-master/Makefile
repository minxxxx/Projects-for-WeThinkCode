
NM_SRC = srcs/nm.c
NM_SRC += srcs/nm_fat.c
NM_SRC += srcs/nm_list.c
NM_SRC += srcs/nm_util.c
NM_SRC += srcs/nm_print_and_tab.c

OT_SRC = srcs/otool.c
OT_SRC += srcs/otool_fat.c
OT_SRC += srcs/otool_print.c
OT_SRC += srcs/otool_util.c

NM_OBJ = $(NM_SRC:.c=.o)
OT_OBJ = $(OT_SRC:.c=.o)

LIB = libft/libft.a
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m
INC = -I ./includes/

all: start
	-@make -C libft nohd
	@gcc -o ft_otool $(OT_SRC) $(FLAG) $(INC) $(LIB);
	@echo "$(CY)[OTOOL] :$(CE) $(CG)Compiling otool ...$(CE)";
	@gcc -o ft_nm $(NM_SRC) $(FLAG) $(INC)  $(LIB);
	@echo "\033[K$(CY)[NM] :$(CE) $(CG)Compiling nm ...$(CE)";


start:
	@echo "\n";
	@echo "			$(CG)      ::::    :::   :::   :::    :::::::: ::::::::::: ::::::::   ::::::::  :::  $(CE)";
	@echo "			$(CG)     :+:+:   :+:  :+:+: :+:+:  :+:    :+:    :+:    :+:    :+: :+:    :+: :+:   $(CE)";
	@echo "			$(CG)    :+:+:+  +:+ +:+ +:+:+ +:+ +:+    +:+    +:+    +:+    +:+ +:+    +:+ +:+    $(CE)";
	@echo "			$(CG)   +#+ +:+ +#+ +#+  +:+  +#+ +#+    +:+    +#+    +#+    +:+ +#+    +:+ +#+     $(CE)";
	@echo "			$(CG)  +#+  +#+#+# +#+       +#+ +#+    +#+    +#+    +#+    +#+ +#+    +#+ +#+      $(CE)";
	@echo "			$(CG) #+#   #+#+# #+#       #+# #+#    #+#    #+#    #+#    #+# #+#    #+# #+#       $(CE)";
	@echo "			$(CG)###    #### ###       ###  ########     ###     ########   ########  ########## $(CE)";
	@echo "\n";

%.o: %.c
	@echo "\033[K$(CY)[MALLOC] :$(CE) $(CG)Compiling $<$(CE) \033[1A";
	@gcc $(FLAG) -c $< -o $@ $(INC)

clean: start
	@echo "\033[K$(CY)[MALLOC] :$(CE) $(CG)Cleaning Malloc objects$(CE)\033[1A";
	-@make -C libft nohdclean;
	@/bin/rm -rf $(OBJ);

fclean: start clean
	@echo "\033[K$(CY)[MALLOC] :$(CE) $(CG)Cleaning 42sh ...$(CE)\033[1A";
	-@make -C libft nohdfclean;
	@/bin/rm -f ft_nm ft_otool;

re: fclean all

.PHONY: all clean fclean re
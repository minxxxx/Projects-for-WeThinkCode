
#include "../include/VirtualMachine.hpp"

int     main(int ac, char **av){
	Flags   flag;

	get_flags(flag, ac, av);
	flag.is_file = check_file_exist(ac, av);
	read_asm(ac, av, flag);
	return 0;
}
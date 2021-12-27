#include "../include/VirtualMachine.hpp"

bool    check_file_exist(int ac, char **av){
	bool  file = false;

	int i = 0;
	while (++i < ac){
		if (av[i][0] != '-')
			file = true;
		if (file)
			break;
	}
	return file;
}

void    read_stream(std::ifstream & stream, Flags & flags){
	std::string     line;
	std::vector<Instruction> cmds;

	while (std::getline(stream, line)){
		//std::cout << "line in file : " << line << std::endl;
		my_lexer(line, flags, cmds);
	}
	std::cout << "num of instructions : " << cmds.size() << std::endl;
    try {
        execute_cmds(cmds);
    }catch (myexception & e){
        exit(EXIT_FAILURE);
    }

}

void    read_stdin(Flags & flags){
	std::string     line;
	std::vector<Instruction> cmds;

	while (std::getline(std::cin, line)){
		if (!std::strcmp(line.c_str(), ";;"))
			break;
		//std::cout << "line in cin : " << line << std::endl;
		my_lexer(line, flags, cmds);
	}
	std::cout << "end of cin" << std::endl;
}

void    read_asm(int ac, char **av, Flags & flag){
	if (!flag.is_file){
		read_stdin(flag);
		return;
	}
	for (int i = 1; i < ac; i++){
		if (av[i][0] == '-')
			continue;
		std::ifstream file(av[i]);
		read_stream(file, flag);
	}
}

void    get_flags(Flags & flag, int ac, char **av){
	int     i;

	flag.gui = false;
	flag.autoplay = true;
	flag.diagnose = false;
	flag.error = false;
	i = 0;
	while (++i < ac){
		if (!std::strcmp("--diagnose", av[i]))
			flag.diagnose = true;
		if (!std::strcmp("--gui", av[i]))
			flag.gui = true;
		else if (!std::strcmp("--autoplay", av[i]))
			flag.autoplay = false;
	}
}
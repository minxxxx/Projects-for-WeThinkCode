
#include "../include/VirtualMachine.hpp"

void    my_parser_error(Flags & flag, std::string & oldline){
	flag.error = true;
	throw myexception((std::string("Error on line : ") + oldline).c_str());
}

Instructions    get_instruction(std::string & str){
	if (!std::strcmp(str.c_str(), "push"))
		return Instructions::PUSH;
	if (!std::strcmp(str.c_str(), "pop"))
		return Instructions::POP;
	if (!std::strcmp(str.c_str(), "dump"))
		return Instructions::DUMP;
	if (!std::strcmp(str.c_str(), "assert"))
		return Instructions::ASSERT;
	if (!std::strcmp(str.c_str(), "add"))
		return Instructions::ADD;
	if (!std::strcmp(str.c_str(), "sub"))
		return Instructions::SUB;
	if (!std::strcmp(str.c_str(), "mul"))
		return Instructions::MUL;
	if (!std::strcmp(str.c_str(), "div"))
		return Instructions::DIV;
	if (!std::strcmp(str.c_str(), "mod"))
		return Instructions::MOD;
	if (!std::strcmp(str.c_str(), "print"))
		return Instructions::PRINT;
	if (!std::strcmp(str.c_str(), "exit"))
		return Instructions::EXIT;
	return Instructions::NONE;
}

void    my_parser(std::vector<std::string> & tab, Flags & flag, std::vector<Instruction> & cmds,
                  std::string & oldline){
	eOperandType d_type;
	std::string num;

	if (tab.size() < 1)
		return;
	if (tab.size() > 2)
		return my_parser_error(flag, oldline);
	if (!std::strcmp(tab[0].c_str(), "push") || !std::strcmp(tab[0].c_str(), "assert")) {
		if (tab.size() != 2)
			return my_parser_error(flag, oldline);
	}
	else if (tab.size() != 1)
		return my_parser_error(flag, oldline);
	Instructions type = get_instruction(tab[0]);
	if (type == Instructions::NONE)
		return throw myexception((std::string("Unknown Instruction on line : ") + oldline).c_str());
	if (type != Instructions::PUSH && type != Instructions::ASSERT){
		cmds.push_back(Instruction(type, "0", eOperandType::ZERO, oldline));
		return;
	}
	try
	{
		process_push_assert_cmd(tab[1], d_type, num);
		cmds.push_back(Instruction(type, num, d_type, oldline));
	}catch (myexception & e){
		throw e;
	}
}

void    my_lexer(std::string & line, Flags & flag, std::vector<Instruction> & cmds){
	std::string oldline = line;
	std::size_t found = line.find_first_of(';');
	if (found != std::string::npos){
		//std::cout << "this is a comment line" << std::endl;
		line = line.substr(0, found);
	}
	//std::cout << "new line : " << line << std::endl;
	std::vector<std::string> tab = line_split(line, ' ');
	//std::cout << "line : " << line << " split : " << tab.size() << std::endl;
	try {
		my_parser(tab, flag, cmds, oldline);
	}catch (myexception & e){
		if (!flag.diagnose)
			exit(EXIT_FAILURE);
	}

}
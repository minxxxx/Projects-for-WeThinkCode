#include <iostream>
#include <stack>
#include <eOperandType.hpp>
#include <IOperand.hpp>
#include <lexer.hpp>
#include <Token.hpp>
#include <fstream>
#include <LexicalException.hpp>
#include <RuntimeException.hpp>
#include <Parser.hpp>
#include <Int8.hpp>
#include <AVM.hpp>
#include <sstream>

std::string	get_instructions_from_stdin()
{
	std::string ret("");
	bool first = true;

	std::cin.exceptions(std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit);
	while (1)
	{
		std::string line;
		try {
			std::getline(std::cin, line);
		}
		catch (std::ios_base::failure const e) {
			if (std::cin.eof())
				std::cout << "Error : Please terminate your program with the `;;' instruction."	<< std::endl;
			else
				std::cout << "An error occured while trying to read from the standard input."	<< std::endl;
			exit(1);
		}
		if (line == ";;")
		{
			return ret + '\n';
		}
		if (!first)
			ret += '\n' + line;
		else
		{
			ret = line;
			first = false;
		}
	}
}

std::string	get_instructions_from_file(char *filename)
{
	std::ifstream file(filename);

	if (!file.is_open() || file.bad() || file.fail() || !file.good())
		throw RuntimeException("Could not open file " + std::string(filename));
	std::stringstream buffer;
	buffer << file.rdbuf();
	if (buffer.str() == "")
		throw RuntimeException("Invalid or empty file " + std::string(filename));
	return buffer.str();
}

int main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout << "Usage: " << av[0] << " [file]" << std::endl;
		return -1;
	}
	std::string	file;
	std::vector<Token> tokens;
	std::vector<Instruction> instructions;
	Parser parser;

	try {
		if (ac == 1)
			file = get_instructions_from_stdin();
		else
			file = get_instructions_from_file(av[1]);
	} catch (const RuntimeException & e) {
		std::cout << "Input error :" << std::endl;
		std::cout << '\t' << e.what() << std::endl;
		return 1;
	}

	bool	errorOccured = false;
	tokens = lexer(file, errorOccured);

	try {
		parser.setToken(tokens);
		instructions = parser.getInstructions(errorOccured);
	} catch (const SyntaxicException & e) {
		return 3;
	}

	if (errorOccured)
		return 6;

	try {
		AVM vm(instructions);
		vm.execute();
	} catch (const RuntimeException & e) {
		std::cout << "Runtime error :" << std::endl;
		std::cout << '\t' << e.what() << std::endl;
		return 5;
	}
	return 0;
}

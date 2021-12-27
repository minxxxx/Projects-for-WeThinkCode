/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:28:43 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/13 09:35:18 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Commands.hpp"
#include <string>
#include <fstream>

// return true if exit cmd found for file
bool	find_exit(std::string file)
{
	std::string		line;
	std::ifstream	input;
	bool			exit = false;

	try
	{
		input.open(file);
		while (std::getline(input, line))
			if (remove_comment(line) == 0)
				exit = true;
		input.close();
		if (exit == true)
			return (true);
		else
			throw Error::InstructionError();
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
}

// loop thru each line in the file 
void	parse_file(std::string file)
{
	std::ifstream	input;
	std::string		line;
	int				linecount = 0;
	bool			exit = false;
	std::vector<IOperand const *>	stack;

	input.open(file);
	if (find_exit(file) == false)
	{
		std::cout << "No exit command found in "+file << std::endl;
		return ;
	}
	while (std::getline( input, line ) && exit != true)
	{
		std::string	cmds[4];
		try {
			std::string		cmds[4];
			linecount++;
			validate(linecount, line, cmds);
			if (cmds[3] == "end") {
				for (int i = stack.size() - 1; i >= 0; i--)
					delete stack[i];
				exit = true;
			}
			if (cmds[3] == "reg_cmd")
				run_reg_cmds(cmds, stack, linecount);
			if (cmds[3] == "push/assert") {
				if (cmds[0] == "push")
					push(linecount, cmds, stack, line);
				else if (cmds[0] == "assert")
					assert(linecount, cmds, stack, line);
			}
			if (cmds[3] == "end")
				std::cout << line << std::endl;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	input.close();
}

// check if given files is a valid .avm file
void	read_files(char **files, int total) {
	for (int index = 1; index < total; index++) {
		std::string	file = files[index];
		std::size_t found = file.find(".avm");
		if (found!=std::string::npos)
			parse_file(files[index]);
		else
			std::cout << "invalid file : " << files[index] << std::endl;
	}
}

// loop for all possible inputs
void	loop(void)  {
	bool							exit = false;
	std::vector<IOperand const *>	stack;
	std::vector<std::string>		commands;
	int								exitF = 0;

	while (!exit) {
		std::string in;
		std::getline (std::cin, in);
		remove_comment(in);
		if (in == "exit")
			exitF = 1;
		if (in == ";;") {
			if (exitF != 1) {
				std::cout << "No exit command found!" << std::endl;
				std::exit (EXIT_FAILURE);
			}
			else
				exit = true;
		}
		if (in == "")
			std::cout << "Invalid syntax" << std::endl;
		else if (in != ";;")
			commands.push_back(in);
	}
	for (unsigned long line = 0; line < commands.size() - 1; line++) {
		std::string		input = commands[line];
		try {
			std::string		cmds[4];
			validate(line, input, cmds);
			if (cmds[3] == "reg_cmd")
				run_reg_cmds(cmds, stack, line);
			else if (cmds[3] == "push/assert") {
				if (cmds[0] == "push")
					push(line, cmds, stack, input);
				else if (cmds[0] == "assert")
					assert(line, cmds, stack, input);
			}
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	for (int i = stack.size() - 1; i >= 0; i--)
		delete stack[i];
}

// create a temp.avm file
void	loop_f_flag(void)  {
	bool							exit = false;
	std::vector<IOperand const *>	stack;
	std::vector<std::string>		commands;
	int								exitF = 0;

	while (!exit) {
		std::string in;
		std::getline (std::cin, in);
		remove_comment(in);
		if (in == "exit")
			exitF = 1;
		if (in == ";;") {
			if (exitF != 1) {
				std::cout << "No exit command found!" << std::endl;
				std::exit (EXIT_FAILURE);
			}
			else
				exit = true;
		}
		if (in == "")
			std::cout << "Invalid syntax" << std::endl;
		else if (in != ";;")
			commands.push_back(in);
	}
	if (exit == true)
		create_file(commands);
	else
		std::cout << "Could not create file type" << std::endl;
}

// run with interactive mode, this is a bonus
void	loop_i_flag(void)  {
	bool					exit = false;
	std::string				input;
	std::vector<IOperand const *>	stack;
	int						line = 0;

	while (!exit) {
		std::getline (std::cin, input);
		remove_comment(input);
		try {
			std::string		cmds[4];
			line++;
			validate(line, input, cmds);
			if (cmds[3] == "end") {
				for (int i = stack.size() - 1; i >= 0; i--)
					delete stack[i];
				exit = true;
			}
			if (cmds[3] == "reg_cmd")
				run_reg_cmds(cmds, stack, line);
			if (cmds[3] == "push/assert") {
				if (cmds[0] == "push")
					push(line, cmds, stack, input);
				else if (cmds[0] == "assert")
					assert(line, cmds, stack, input);
			}
			if (cmds[3] == "end")
				std::cout << input << std::endl;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
}

// start vm and look for input file or wait for input
int		main(int ac, char **av) {
	if (ac > 1) {
		std::string temp = av[1];
		if (temp.compare("-i") == 0)
			loop_i_flag();
		else if (temp.compare("-f") == 0)
			loop_f_flag();
		else
			read_files(av, ac);
	}
	else
		loop();
	return (0);
}

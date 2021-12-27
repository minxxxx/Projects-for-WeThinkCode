/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:50:39 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/16 07:44:20 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"
#include <fstream>
#include <iostream>

// on success of a valid input it creates the file
void	create_file(std::vector<std::string> & lines) {
	std::ofstream file;
	file.open("temp.avm");
	for (unsigned long index = 0; index < lines.size() - 1; index++) {
		file << lines[index] << "\n";
	}
	file << "exit" << std::endl;
	file.close();
}

// return a vector of words to loop thru
std::vector<std::string>	splitspace(std::string input) {
	std::string					buff;	
	std::stringstream			ss(input);
	std::vector<std::string>	words;

	while (ss >> buff)
		words.push_back(buff);
	return (words);
}

// remove comments if any is found and return 0 if exit command/colon is found
int		remove_comment(std::string & input) {
	size_t exitCol = input.find(";;");						// find exit colon
	size_t exitCmd = input.find("exit");					// find exit cmd
	size_t semiC = input.find(";");							// find comments

	input.erase(0, input.find_first_not_of(' '));			//prefixing spaces
	input.erase(input.find_last_not_of(' ')+1);				//surfixing spaces
	input.erase(0, input.find_first_not_of('\t'));			//prefixing tabs
	input.erase(input.find_last_not_of('\t')+1);			//surfixing tabs
	if (exitCmd != std::string::npos && input.size() == 4)	// check if exit cmd if found
		return (0);
	if (semiC != std::string::npos) {
		if (exitCol != std::string::npos && input.size() == 2)	// check if exit colon is found
			return (1);
		input = input.substr(0, semiC);							// remove any comments
		input.erase(0, input.find_first_not_of(' '));			//prefixing spaces
		input.erase(input.find_last_not_of(' ')+1);				//surfixing spaces
		input.erase(0, input.find_first_not_of('\t'));			//prefixing tabs
		input.erase(input.find_last_not_of('\t')+1);			//surfixing tabs
		if (exitCmd != std::string::npos && input.size() == 4)	// check if exit cmd if found
			return (0);
	}
	return (2);
}

// check if input options are true
void	validate(int line, std::string & input, std::string cmds[4])  {
	std::regex		reg("(push|assert) (int8|int16|int32|float|double)\\s?\\(-?[[:digit:]]+(.?[[:digit:]]+)?\\)\\B");
	std::regex		reg_cmds("add\\b|sub\\b|mod\\b|dump\\b|div\\b|mul\\b|pop\\b|print\\b");
	std::regex		digits("\\(-?\\d+(.?\\d+)?\\)");
	std::smatch		base_match;
	std::smatch		value_match;
	std::string		val;

	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (remove_comment(input) == 0 || remove_comment(input) == 1)
		cmds[3] = "end";
	else if (std::regex_match(input, reg_cmds) == true) {
		cmds[0] = input;
		cmds[3] = "reg_cmd";
	}
	else if (std::regex_match(input, base_match, reg) == true) {
		if (std::regex_search(input, value_match, digits) == true)
			val = (value_match[0].str()).substr(1, (value_match[0].str()).size() - 2);
		else
			throw Error::SyntaxError(std::to_string(line), input);
		cmds[0] = base_match[1].str();
		cmds[1] = base_match[2].str();
		cmds[2] = val;
		cmds[3] = "push/assert";
		return;
	}
	else if (input.size() == 0)
		return ;
	else
		throw Error::SyntaxError(std::to_string(line), input);
	return;
}

// check if function has overflow or underflow
void	CheckOUFlow(int line, std::string cmds[4], std::string input) {
	std::string			num = cmds[2];
	std::string			func = cmds[1];
	long double size = std::stold(num);

	if (func == "int8") {
		if (size > INT8_MAX) {
			throw Error::OverflowError(std::to_string(line), input);
		}
		if (size < INT8_MIN)
			throw Error::UnderflowError(std::to_string(line), input);
	}
	else if (func == "int16") {
		if (size > INT16_MAX)
			throw Error::OverflowError(std::to_string(line), input);
		if (size < INT16_MIN)
			throw Error::UnderflowError(std::to_string(line), input);
	}
	else if (func == "int32") {
		if (size > INT32_MAX)
			throw Error::OverflowError(std::to_string(line), input);
		if (size < INT32_MIN)
			throw Error::UnderflowError(std::to_string(line), input);
	}
	else if (func == "float") {
		if (size > FLT_MAX)
			throw Error::OverflowError(std::to_string(line), input);
		if (std::fabsl(size) < FLT_MIN && std::fabsl(size) > 0)
			throw Error::UnderflowError(std::to_string(line), input);
	}
	else if (func == "double") {
		if (size > DBL_MAX)
			throw Error::OverflowError(std::to_string(line), input);
		if (std::fabsl(size) < DBL_MIN && std::fabsl(size) > 0)
			throw Error::UnderflowError(std::to_string(line), input);
	}
}

// does the same as the top function but using different values passed to it.
void	CheckOverUnderFlow(eOperandType _type, long double size) {
	int		type = _type;

	if (type == 0) {
		if (size > INT8_MAX) {
			throw Error::OverflowError("Unknown", std::to_string(size));
		}
		if (size < INT8_MIN)
			throw Error::UnderflowError("Unknown", std::to_string(size));
	}
	else if (type == 1) {
		if (size > INT16_MAX)
			throw Error::OverflowError("Unknown", std::to_string(size));
		if (size < INT16_MIN)
			throw Error::UnderflowError("Unknown", std::to_string(size));
	}
	else if (type == 2) {
		if (size > INT32_MAX)
			throw Error::OverflowError("Unknown", std::to_string(size));
		if (size < INT32_MIN)
			throw Error::UnderflowError("Unknown", std::to_string(size));
	}
	else if (type == 3) {
		if (size > FLT_MAX)
			throw Error::OverflowError("Unknown", std::to_string(size));
		if (std::fabsl(size) < FLT_MIN && std::fabsl(size) > 0)
			throw Error::UnderflowError("Unknown", std::to_string(size));
	}
	else if (type == 4) {
		if (size > DBL_MAX)
			throw Error::OverflowError("Unknown", std::to_string(size));
		if (std::fabsl(size) < DBL_MIN && std::fabsl(size) > 0)
			throw Error::UnderflowError("Unknown", std::to_string(size));
	}
}


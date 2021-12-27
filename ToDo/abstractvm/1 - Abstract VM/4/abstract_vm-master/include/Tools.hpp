
#ifndef ABSTRACT_VM_NEW_TOOLS_HPP
#define ABSTRACT_VM_NEW_TOOLS_HPP

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <exception>

enum eOperandType{
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE,
	ZERO
};

struct myexception : public  std::exception{
	const char *msg;
	myexception(const char *msg);
	virtual const char* what() const throw();
};

std::vector<std::string>    line_split(const std::string &s, char delim);

#endif //ABSTRACT_VM_NEW_TOOLS_HPP

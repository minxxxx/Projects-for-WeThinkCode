/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 07:34:07 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/17 09:24:20 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Error.hpp"

// syntax error
Error::SyntaxError::SyntaxError(const std::string& line, const std::string& input) {
	e_msg = std::string("Syntax ERROR on line ["+line+"] "+input);
}

const char*	Error::SyntaxError::what() const throw() {
	return e_msg.c_str();
}

// overflow error
Error::OverflowError::OverflowError(const std::string& line, const std::string& input) {
	e_msg = std::string("Overflow ERROR on line ["+line+"] "+input);
}

const char* Error::OverflowError::what() const throw() {
	return e_msg.c_str();
}


// underflow error
Error::UnderflowError::UnderflowError(const std::string& line, const std::string& input) {
	e_msg = std::string("Underflow ERROR on line ["+line+"] "+input);
}

const char* Error::UnderflowError::what() const throw() {
	return e_msg.c_str();
}

// instruction error
const char* Error::InstructionError::what() const throw() {
	return "Unknown Instruction given.";
}

// empty error
const char* Error::EmptyError::what() const throw() {
	return "Stack size ERROR: Attempted command on empty stack.";
}

// Zero error
const char* Error::ZeroError::what() const throw() {
	return "Operator ERROR: Can't mod/div by zero!";
}

// Exit Error
const char* Error::ExitError::what() const throw() {
	return "File Format ERROR: No exit command found!";
}

// assert error
const char* Error::AssertError::what() const throw() {
	return "Assert instruction returned false.";
}

// stack size error
const char* Error::StackSizeError::what() const throw() {
	return "Stack size less than two to use command!";
}

// Not and int8 type 
Error::NotInt8::NotInt8(const std::string& line, const std::string& input) {
	e_msg = std::string("ASCII Convertion ERROR on line ["+line+"] "+input);
}

const char* Error::NotInt8::what() const throw() {
	return e_msg.c_str();
}

// error what
const char* Error::what() const throw() { 
	return "Unknown Error!"; 
}

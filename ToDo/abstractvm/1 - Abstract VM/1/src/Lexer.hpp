/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:30:48 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/23 16:53:29 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include  "Program.class.hpp"
#include  "IOperand.class.hpp"
#include "Stack.class.hpp"

//typedef Operand<char, PERCISION_INT8> 		Int8;
//typedef Operand<short int, PERCISION_INT16> Int16;
/*
class Int8 : Operand<char, PERCISION_INT8> {
public: 
	int getTruc(void);
};
class Int16 : Operand<short int, PERCISION_INT16> { };
class Int32 : Operand<long int, PERCISION_INT32> { };
class Float : Operand<float, PERCISION_FLOAT> { };
class Double : Operand<double, PERCISION_DOUBLE> { };
*/
class Lexer
{
private:
	static Lexer				_instance;
	std::vector<std::string>    _Error;

	Lexer();
	Lexer(bool verbose);
	Lexer(Lexer const&);
	Lexer &operator=(Lexer const &);

public:
	static const std::string  TYPENAME[];// = { "Int8", "Int16", "Int32", "Float", "Double" };

	static Lexer &get(void);

	bool	analyse(std::istream &ifstream, bool verbose, bool terminal, Program	&program);

	~Lexer();

	static bool		_isVerbose;	
};

#endif


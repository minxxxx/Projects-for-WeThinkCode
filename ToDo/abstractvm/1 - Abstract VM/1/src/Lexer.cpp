/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:34:50 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/24 19:18:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <boost/spirit/include/classic_push_back_actor.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_core.hpp>
#include <boost/variant.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Lexer.hpp"
#include "AVM.hpp"
#include "OperandFactory.class.hpp"

#define _verbose Lexer::_isVerbose

Lexer::Lexer() {}
Lexer::Lexer(Lexer const&) {}
Lexer &Lexer::operator=(Lexer const &){ return *this;}
Lexer::~Lexer(){}


Lexer Lexer::_instance;
Lexer &Lexer::get(void)
{
	return _instance;
}

bool Lexer::_isVerbose = false;

void makeop(std::string operation)
{
	t_command	com;
	Program& program = AVM::prg();
	
	com.commande = operation;
	program.push(com);
if(AVM::verbose()) {	std::cout << "Operation : "<< operation << std::endl; }
}
void opint8(int operation, int value)
{
	t_command	com;
	Program& program = AVM::prg();

	if (operation == 1)
	{
		com.commande = "push";
if(AVM::verbose()) { std::cout << "push int8("<< value << ")" << std::endl ;}
	}
	else
	{
		com.commande = "assert";
if(AVM::verbose()) { std::cout << "assert int8("<< value << ")"<< std::endl ;}
	}
	com.operand = value;
	com.precision = PRECISION_INT8;
	std::ostringstream strs;
	strs	 << value;
	com.strvalue = strs.str();
	program.push(com);
}

void opint16(int operation, int value)
{
	t_command	com;
	Program& program = AVM::prg();

	if (operation == 1)
	{
		com.commande = "push";
if(AVM::verbose()) { std::cout << "push int16("<< value << ")"<< std::endl ;}
	}
	else
	{
		com.commande = "assert";
if(AVM::verbose()) { std::cout << "assert int16("<< value << ")"<< std::endl ;}
	}
	com.operand = value;
	com.precision = PRECISION_INT16;
	std::ostringstream strs;
	strs	 << value;
	com.strvalue = strs.str();
	program.push(com);
}

void opint32(int operation, int value)
{
	t_command	com;
	Program& program = AVM::prg();

	if (operation == 1)
	{
		com.commande = "push";
if(AVM::verbose()) { std::cout << "push int32("<< value << ")"<< std::endl ;}
	}
	else
	{
		com.commande = "assert";
if(AVM::verbose()) { std::cout << "assert int32("<< value << ")"<< std::endl ;}
	}
	com.operand = value;
	com.precision = PRECISION_INT32;
	std::ostringstream strs;
	strs	 << value;
	com.strvalue = strs.str();
	program.push(com);
}

void opfloat(int operation, double value)
{
	t_command	com;
	Program& program = AVM::prg();

	if (operation == 1)
	{
		com.commande = "push";
if(AVM::verbose()) { std::cout << "push float("<< value << ")"<< std::endl ;}
	}
	else
	{
		com.commande = "assert";
if(AVM::verbose()) {	std::cout << "assert float("<< value << ")"<< std::endl; ;}
	}
	std::ostringstream strs;
	strs	 << value;

	com.operand = value;
	com.precision = PRECISION_FLOAT;
	com.strvalue = strs.str();

	program.push(com);
}

void opdouble(int operation, double value)
{
	t_command	com;
	Program& program = AVM::prg();

	if (operation == 1)
	{
		com.commande = "push";
if(AVM::verbose()) {	std::cout << "push double("<< value << ")"<< std::endl;}
	}
	else
	{
		com.commande = "assert";
if(AVM::verbose()) {	std::cout << "assert double("<< value << ")"<< std::endl;}
	}
	com.operand = value;


std::ostringstream strs;
strs << value;
com.strvalue = strs.str();

	com.precision = PRECISION_DOUBLE;
	program.push(com);
}

BOOST_PHOENIX_ADAPT_FUNCTION(void, makeop_, makeop, 1)
BOOST_PHOENIX_ADAPT_FUNCTION(void, opint8_, opint8, 2)
BOOST_PHOENIX_ADAPT_FUNCTION(void, opint16_, opint16, 2)
BOOST_PHOENIX_ADAPT_FUNCTION(void, opint32_, opint32, 2)
BOOST_PHOENIX_ADAPT_FUNCTION(void, opfloat_, opfloat, 2)
BOOST_PHOENIX_ADAPT_FUNCTION(void, opdouble_, opdouble, 2)

template <typename Iterator, typename Skipper>
struct my_grammar : boost::spirit::qi::grammar<Iterator, Skipper>
{
	my_grammar() : my_grammar::base_type{value}
	{
		auto & int_ = boost::spirit::int_;
		auto & double_ = boost::spirit::double_;
		auto & _1 = boost::spirit::_1;
		value = (op | push | comment | assert);
		push1 = boost::spirit::lit("push ") | boost::spirit::lit("push\t");
		push = push1   
			>> *(space)
			>> *(sign)
			>> (
					boost::spirit::lit("int8(")
					>> int_[opint8_(1, _1)] 
					>> boost::spirit::lit(")")
					| boost::spirit::lit("int16(")
					>> int_[opint16_(1, _1)]
					>> boost::spirit::lit(")")
					| boost::spirit::lit("int32(")
					>> int_[opint32_(1, _1)]
					>> boost::spirit::lit(")")
					| boost::spirit::lit("float(")
					>> double_[opfloat_(1, _1)]
					>> boost::spirit::lit(")")
					| boost::spirit::lit("double(")
					>> double_[opdouble_(1, _1)]
					>> boost::spirit::lit(")")
			   ) 
			>> *(comment) ;
		comment = boost::spirit::lit(";");
		space = boost::spirit::lit(" ") | boost::spirit::lit("\t");
		sign = boost::spirit::lit("+") | boost::spirit::lit("-");
		assert1 = boost::spirit::lit("assert ") | boost::spirit::lit("assert\t"); 
		assert = assert1
			>> *(space)
			>> *(sign)
			>> (
					boost::spirit::lit("int8(")
					>> int_[opint8_(2, _1)]
					>> boost::spirit::lit(")")
					| boost::spirit::lit("int16(")
					>> int_[opint16_(2, _1)]
					>> boost::spirit::lit(")")
					| boost::spirit::lit("int32(")
					>> int_[opint32_(2, _1)]
					>> boost::spirit::lit(")")
					| boost::spirit::lit("float(")
					>> double_[opfloat_(2, _1)]
					>> boost::spirit::lit(")")
					| boost::spirit::lit("double(")
					>> double_[opdouble_(2, _1)]
					>> boost::spirit::lit(")")
			   ) 
			>> *(comment) ;
		op = ((boost::spirit::lit("add")) [makeop_(std::string("add"))] 
				| boost::spirit::lit("sub") [makeop_(std::string("sub"))] 
				| boost::spirit::lit("mul") [makeop_(std::string("mul"))] 
				| boost::spirit::lit("div") [makeop_(std::string("div"))]
				| boost::spirit::lit("mod") [makeop_(std::string("mod"))] 
				| boost::spirit::lit("print") [makeop_(std::string("print"))] 
				| boost::spirit::lit("pop") [makeop_(std::string("pop"))] 
				| boost::spirit::lit("dump") [makeop_(std::string("dump"))] 
				| boost::spirit::lit("max")[makeop_(std::string("max"))]
				| boost::spirit::lit("min")[makeop_(std::string("min"))]
				| boost::spirit::lit("exit")[makeop_(std::string("exit"))] 
			 ) 
			>> *(comment);
	}

	boost::spirit::qi::rule<Iterator, Skipper> 
		value, op , assert, assert1, push1;
	boost::spirit::qi::rule<Iterator, Skipper> 
		push, comment, space , sign, tab;
};

bool	Lexer::analyse(std::istream &ifs, bool verbose, bool terminal, Program	&program)
{
	std::string s;
	std::string	error;
	bool		finished = false;
	bool		noerror = true;	

	_verbose = verbose;
	//program.setVerbose(verbose);
if(AVM::verbose()) {	std::cout << "Début parse : " << std::endl;}
	
	while (ifs.good() && !finished)	{
		bool repeat = true;
		while (repeat)
		{
			repeat = false;
			getline(ifs, s);
			if(!s.empty()) {

				if ((s.compare(";;")==0) && (terminal))
				{
					s = "exit";
					finished = true;
				}

				auto iter = s.begin();
				auto end = s.end();

				my_grammar<std::string::iterator, 
					boost::spirit::ascii::space_type> g;

				bool r = boost::spirit::qi::phrase_parse(
					iter, end, g, boost::spirit::ascii::space);
				if (!r)
				{
					std::string rest(iter, s.end());
					error = "-------------------------\n" ; 
					error = error +	"Parsing failed\n";
					error = error +	"stopped at: \": " + rest + "\"\n";
					error = error +	"-------------------------\n";
					if (terminal)
					{
						std::cout << error;
						repeat = true;
						std::cout << "\nEnter again \n";
					}
					else
					{
						_Error.push_back(error);
						noerror = false;
					}
				}
			}
		}	
	}
	/*	if ((s.compare(";;")!=0) && (s.compare("exit")!=0))
		{
		std::cout << "-------------------------\n";
		std::cout << "Parsing failed No Termination statement\n";
		std::cout << "-------------------------\n";
		}*/
if(AVM::verbose()) {	std::cout << "Taille stack commande : " 
		<< program.getSize()
		<< std::endl;}
if(AVM::verbose()) {	std::cout << "Top stack commande : "
		<< program.last().commande
		<< std::endl;}
	//program.setVerbose(verbose);
	if (noerror)
		return program.verify();
	else
	{	
		std::vector<std::string>::iterator it;
		for (it=_Error.begin(); it<_Error.end(); it++)
    		std::cout << *it;
		return noerror;
	}
}


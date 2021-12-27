/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:34:50 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/24 19:18:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "AVM.hpp"
#include "OperandFactory.class.hpp"
#include "Lexer.hpp"
#include "Operand.template.hpp"

AVM::AVM() :_verbose(false) {}
AVM::AVM(AVM const&) {}
AVM &AVM::operator=(AVM const &){ return *this;}
AVM::~AVM(){}

AVM AVM::_instance;
AVM &AVM::get(void)
{
	return _instance;
}

Program	&AVM::prg(void){
	return get()._program;
}

bool	AVM::verbose(void){
	return get()._verbose;
}

bool	AVM::analyse(std::istream &ifs, bool verbose, bool terminal)
{
	Lexer &lexer = Lexer::get();
	return lexer.analyse(ifs, verbose, terminal, _program);
}

bool	AVM::run(bool verbose)
{
	_verbose = verbose;
	return _program.run(verbose, _stack);
}	



AVM::AssertFailureException::AssertFailureException( const std::string& stackstring, int stacktype, const std::string& assertstring, int comtype)  
{
	std::stringstream ss;
	ss << "AssertFailure: Value Top of the stack : " 
	<< TYPENAME[stacktype] 
	<< "(" << stackstring << ")" << "  is different from " 
	<< TYPENAME[comtype] << "("<< assertstring << ")";
	
	_msg = ss.str();
}

AVM::AssertFailureException::AssertFailureException(AssertFailureException const &e) : AVMException(e) 
{ *this = e; }

AVM::AssertFailureException &AVM::AssertFailureException::operator=(AssertFailureException const &)  
{ return (*this); }

AVM::AssertFailureException::~AssertFailureException(void) throw () 
{}
const char * AVM::AssertFailureException::what(void) const throw () { return _msg.c_str(); }

AVM::PrintFailureException::PrintFailureException( const std::string& stackstring, int stacktype)  
{
	_msg = "PrintFailure: Value Top of the stack : " + TYPENAME[stacktype] +"(" + stackstring + ")" + "  is is not of type INT8 " ;
}

AVM::PrintFailureException::PrintFailureException(PrintFailureException const &e) : AVMException(e) 
{ *this = e; }

AVM::PrintFailureException &AVM::PrintFailureException::operator=(PrintFailureException const &) { return (*this); }

AVM::PrintFailureException::~PrintFailureException(void) throw () {}
const char * AVM::PrintFailureException::what(void) const throw () { return _msg.c_str(); }


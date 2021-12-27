/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:44:36 by jblancha          #+#    #+#             */
/*   Updated: 2017/02/24 19:17:03 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.class.hpp"
#include "OperandFactory.class.hpp"
#include "Operand.template.hpp"
#include <sstream>

Program::Program(void) :_verbose(false) {}

Program::~Program(void) {}

Program::Program(Program const &program) {	*this=program; }

Program &Program::operator=(Program const &) {	return(*this); }

void Program::push(t_command iop) {	_tab.push_back(iop);}

t_command &Program::last(void)
{
	if (this->isEmpty())
		throw(Program::SizeEmptyException());
	return(_tab.at(_tab.size() - 1));
}

t_command &Program::at(size_t i)
{
	if(i >= _tab.size())
		throw(Program::SizeEmptyException());
	return _tab.at(i);
}

bool Program::verify(void) const
{
if(_verbose) {	std::cout << " Début Program Verify" << std::endl;}

	int nboperand = 0;

	for (unsigned int i=0;i<_tab.size();i++)
	{
		t_command program = _tab.at(i);
if(_verbose) { 	std::cout << "command " << program.commande << " / stack with "<< nboperand << " operand(s) " << std::endl;} 
		
		if (program.commande == "push"){
			nboperand++;
if(_verbose) { std::cout << "		==> stack : "<< nboperand << " operand(s) " << std::endl;} 

		}
		if ( (nboperand < 2)
		&&   ( program.commande == "add"
		     || program.commande == "sub" || program.commande == "mul" 
		     || program.commande == "div" || program.commande == "mod"
		     || program.commande == "max" || program.commande == "min" )
		)
		{
if(_verbose) { std::cout << "		==> stack : " << nboperand << " operand(s) ... (nboperand < 2) => throw(Program::SizeEmptyException())" << std::endl;} 
			throw(Program::SizeEmptyException());
			return(false);
		}
		if ( (nboperand < 1) 
		&& ( program.commande == "print" 
			|| program.commande == "assert" 
			|| program.commande == "pop" )
		)
		{
if(_verbose) { std::cout << "		==> stack : " << nboperand << " operand(s) ... (nboperand < 1) => throw(Program::SizeEmptyException())" << std::endl;} 
			throw(Program::SizeEmptyException());
			return(false);
		}
		if (  program.commande == "pop" || program.commande == "add" 
		   || program.commande == "sub" || program.commande == "mul" 
		   || program.commande == "div" || program.commande == "mod"
		   || program.commande == "max" || program.commande == "min"){
			nboperand--;
if(_verbose) { std::cout << "		==> stack : "<< nboperand << " operand(s) " << std::endl;} 

		}
		if (nboperand < 0)
		{
if(_verbose) { std::cout << "		==> stack : " << nboperand << " operand(s)  .... (nboperand < 0) => throw(Program::SizeEmptyException())" << std::endl;}
			throw(Program::SizeEmptyException());
			return(false);
		}
		
	}
	if (_tab.at(_tab.size() - 1).commande != "exit")
	{
if(_verbose) { std::cout << "		==> stack : " << nboperand << " operand(s) ... last commande != \"exit\" => throw(Program::NoExitException())" << std::endl;}
		throw(Program::NoExitException());
		return(false);
	}
	
if(_verbose) {std::cout << " Verify Successfull\n\n";}
	return(true);
}

bool Program::isEmpty(void) const { return(_tab.empty()); }

size_t Program::getSize(void) const { return(_tab.size()); }


bool	Program::run(bool verbose, Stack &_stack)
{
	OperandFactory 		&factory = OperandFactory::get();
	_verbose = verbose;

if(_verbose) {	std::cout << " Debut Run\n";}
	if (isEmpty())
		throw(Program::SizeEmptyException());
	int nboperand = 0;
	try{
		for (size_t i = 0; i < getSize(); i++)
		{
			t_command com = at(i);

			try{
				if ((com.commande == "print" || com.commande == "assert"
							|| com.commande == "pop") && (nboperand < 1))
				{
if(_verbose) { std::cout << "**** " <<  com.commande << " but stack is empty ...  => Program::SizeEmptyException() ****" << std::endl ;}
					throw(Program::SizeEmptyException());
					return(false);
				}

				if (com.commande == "push")
				{

if(_verbose) {	std::cout << "[ PUSH " <<  TYPENAME[com.precision] << "(" <<com.strvalue << ") ] " << std::endl ;}
					IOperand const * iop = factory.createOperand(
							com.precision, com.strvalue );
					//std::cout << "( factory -> " <<  iop->toString() << " )" << std::endl;
					_stack.push(iop);
					nboperand++;
				}
				if (com.commande == "add")
				{
					if(nboperand < 2)
						throw(Program::SizeEmptyException());
if(_verbose) {	std::cout << "[ ADD ";}
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
if(_verbose) {	std::cout << a  << " " 		<< b  << " : ";}
					IOperand const *c = (*a) + (*b);
if(_verbose) {	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl;}
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "sub") {
					if(nboperand < 2)
						throw(Program::SizeEmptyException());
if(_verbose) {	std::cout << "[ SUB ";}
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
if(_verbose) {	std::cout << a << " " 		<< b  << " : ";}
					IOperand const *c = (*a) - (*b);
if(_verbose) {	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl;}
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "mul") {
					if(nboperand < 2)
						throw(Program::SizeEmptyException());
if(_verbose) {	std::cout << "[ MUL ";}
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
if(_verbose) {	std::cout << a << " " 		<< b  << " : ";}
					IOperand const *c = (*a) * (*b);
if(_verbose) {	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl;}
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "div") {
if(_verbose) {	std::cout << "[ DIV ";}
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
if(_verbose) {	std::cout << a << " " 		<< b  << " : ";}
					IOperand const *c = (*a) / (*b);
if(_verbose) {	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl;}
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "mod") {
if(_verbose) {	std::cout << "[ MOD ";}
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
if(_verbose) {	std::cout << a ;}
if(_verbose) {	std::cout << " " 		<< b  << " : ";}
					IOperand const *c = (*a) % (*b);
if(_verbose) {	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl;}
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "max") {
if(_verbose) {	std::cout << "[ MAX ";}
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
if(_verbose) {	std::cout << a << " " 		<< b  << " : ";}
					IOperand const *c;
					if ((*a) > (*b))
						c = factory.createOperand(a->getType(), a->toString());
					else
						c = factory.createOperand(b->getType(), b->toString());
if(_verbose) {	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl;}
					 _stack.push(c);
					 delete a;
					 delete b;
					nboperand--;
		 		} else if (com.commande == "min") {
if(_verbose) {	std::cout << "[ MAX ";}
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
if(_verbose) {	std::cout << a << " " 		<< b  << " : ";}
					IOperand const *c;
					if ((*a) > (*b))
						c = factory.createOperand(b->getType(), b->toString());
					else
						c = factory.createOperand(a->getType(), a->toString());
if(_verbose) {	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl;}
					 _stack.push(c);
					 delete a;
					 delete b;
					nboperand--;
		 		} else if (com.commande == "pop") {
					if(nboperand < 1)
						throw(Program::SizeEmptyException());
					IOperand const *a = _stack.pop(); 
if(_verbose) {	std::cout << "[ POP " <<  a << " ]" << std::endl ;}
					(void) a;
					nboperand--;
		 		} else if (com.commande == "dump") {

if(_verbose) {	std::cout << "[ DUMP ]" << std::endl ;}
					size_t n = _stack.getSize();
					for (size_t i = 0; i < static_cast<size_t>(n); ++i)
					{
						//Operand const * op = reinterpret_cast<Operand const*>(_stack.at(i));
						IOperand const * iop = _stack.at(i);
						std::cout << "[ operand " << i << " : " << iop << "\t]" << std::endl;
		 			}
if(_verbose) { std::cout << "[ DUMP ok ]" << std::endl	;}
		 		} else if (com.commande == "assert") {
					IOperand const *iop = _stack.getTop();
if(_verbose) { std::cout << "[ ASSERT (cmd) " << iop 
	<< " == " << TYPENAME[com.precision] << "(" << com.strvalue << ") (tos)    ...    " ;}
					OperandFactory const &factory = OperandFactory::get();
					IOperand const *iop2 =	factory.createOperand(com.precision, com.strvalue);
					if (*iop != *iop2)
					{
if(_verbose) {
		std::cout << " ASSERT KO => AVM::AssertFailureException(" 
			<< iop->toString() << ", " << iop->getType()
			<<", "<<com.strvalue << ", " << com.precision<<") ]"
			<< std::endl ;
}
						delete iop2;			
						throw(AVM::AssertFailureException(iop->toString(), iop->getType(), com.strvalue, com.precision));
					}else {
						delete iop2;			
if(_verbose) { std::cout << " ASSERT OK ] " << std::endl; ;}
					}
		 		}
		
		 		else if (com.commande == "print") {
					IOperand const *stktop = _stack.getTop();
if(_verbose) {	std::cout << "[ PRINT " <<  stktop->toString() << "/p:" << stktop->getType() << " ]" << std::endl ;}
					//Int8 const * int8 = reinterpret_cast<Int8 const *>(stktop);
					if (//int8 == NULL || 
						stktop->getType() != PRECISION_INT8)
					{
							throw(AVM::PrintFailureException(stktop->toString(), stktop->getType()));
					}
					else 
					{	
						//char c = int8->toBaseType(); 
						std::string  s = stktop->toString(); 
						double d = std::atof(s.c_str());
						//if (isprint(static_cast<char>(d)))
							std::cout << static_cast<char>(d);
					}
		 		}

				if (nboperand < 0)
					throw(Program::SizeEmptyException());
			
			}catch(AVMException const & e){
				std::cout << "AVMException " 
					<< e.what() << std::endl;
			}catch(std::exception const & e){
				std::cout << "Unknown exception : " 
					<< e.what() << std::endl;
				return false;
			}
		}
		if (at(getSize() - 1).commande != "exit")
			throw(Program::NoExitException());

if(_verbose) {	std::cout << "Run Successfull\n\n";}

	}catch(AVMException const & e){
		std::cout << "AVMException " 
			<< e.what() << std::endl;
		return false;
	}catch(std::exception const & e){
		std::cout << "Unknown exception : " 
			<< e.what() << std::endl;
		return false;
	}

	return true;
}



Program::NotInt8Exception::NotInt8Exception( std::string const & stackstring, int stacktype)
{
	std::ostringstream ss;
	
	ss << "Program::NotInt8Exception : "
		<< "stackstring:" << stackstring
		<< ", stacktype:" << stacktype;
	
	_msg = ss.str();
}
Program::NotInt8Exception::NotInt8Exception(Program::NotInt8Exception const &ex) : AVMException(ex), _msg(ex._msg) {}
Program::NotInt8Exception::~NotInt8Exception() throw () {}
Program::NotInt8Exception &Program::NotInt8Exception::operator=(Program::NotInt8Exception const &) { return *this; }
const char * Program::NotInt8Exception::what(void) const throw() { return _msg.c_str(); }

Program::SizeEmptyException::SizeEmptyException(void) {}
Program::SizeEmptyException::SizeEmptyException(SizeEmptyException const &ex) : AVMException(ex) {}
Program::SizeEmptyException &Program::SizeEmptyException::operator=(
		SizeEmptyException const &)  {	return (*this); }
Program::SizeEmptyException::~SizeEmptyException(void) throw () {}
const char * Program::SizeEmptyException::what(void) const throw () {
	return "Program::SizeEmptyException : Size is empty.";
}


Program::NoExitException::NoExitException(void) {}
Program::NoExitException::NoExitException(NoExitException const &ex) : AVMException(ex) {}
Program::NoExitException &Program::NoExitException::operator=(Program::NoExitException const &) { return *this; }
Program::NoExitException::~NoExitException(void) throw () {}
const char * Program::NoExitException::what(void) const throw () {
	return "Program::NoExitException : No Exit command at the end of program.";
}


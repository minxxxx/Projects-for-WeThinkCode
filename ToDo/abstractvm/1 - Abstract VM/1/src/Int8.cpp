/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:07:36 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 12:09:26 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"
#include "OperandFactory.class.hpp"
#include "AVM.hpp"
#include <sstream>

#define _verbose AVM::verbose()


const	eOperandType Int8::_type = PRECISION_INT8;

Int8::Int8() : _v8(0), _str("") {}

Int8::Int8(char c) : _v8(c)
{
	_str = std::to_string(c);
}

Int8::Int8(long long int v) 
{
//TRACER(	std::cout << "appel du constructeur Int8(long long " << v << ")" <<std::endl );
	if (v < MIN)
		throw(Int8::UnderflowException());
	else if (v > MAX)
		throw(Int8::OverflowException());
	_v8 = static_cast<char>(v);	
	_str = std::to_string(v);
}

Int8::Int8(std::string const & s) : _str(s)
{
//	TRACER(	std::cout << "appel du constructeur Int8(std::string const & " << s << ")" <<std::endl );

	//long int v = std::strtol(s.c_str(), NULL, 10);
	long int v = std::atol(s.c_str());
	//TRACER(	std::cout << "std::atol(s.c_str()) = " << v << ")" <<std::endl );

	if (v < MIN){
		//TRACER(	std::cout << "OUPS " << v << " < " << MIN << std::endl );
		throw(Int8::UnderflowException());
	}else if (v > MAX){
		//TRACER(	std::cout << "OUPS " << v << " > " << MIN << std::endl );
		throw(Int8::OverflowException());
	}

	_v8 = static_cast<char>(v);
}

Int8::Int8(Int8 const &o)
{
	TRACER(	std::cout << "appel du constructeur par copie Int8(" << o.toString() << ")" <<std::endl );
	*this = o;
}

Int8::~Int8() {}

char    	 	Int8::toChar( void ) const { return _v8; }
long int     	Int8::toLongInt( void ) const { return static_cast<long int>(_v8); }
long double    	Int8::toLongDouble( void ) const { return static_cast<long double>(_v8); };

std::string const & Int8::toString( void ) const{
	return _str;
}

std::string 		Int8::description( void ) const{
	std::stringstream ss;
	ss << "Int8(" << static_cast<int>(_v8) << ")";
	return ss.str();
}

Int8  &Int8::operator=(Int8 const &o)
{
	_v8 = o.toChar();
	_str = o.toString();
	return (*this);
}

int Int8::getPrecision( void ) const{
	return 8;
} // Precision of the type of the instance

eOperandType Int8::getType( void ) const{
	return _type;
} // Type of the instance


bool	Int8::operator==( IOperand const & o ) const{
	if (_type != o.getType())
		return false;
	Int8 const & op = dynamic_cast<Int8 const &>(o);
	return _v8 == op.toChar();
}
bool	Int8::operator!=( IOperand const & o ) const{
	return !(*this == o);
}


IOperand const * Int8::operator+( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int8 const & i = dynamic_cast<Int8 const &>(o);
		long int v = toChar() + i.toChar();
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " + " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = (*tmp) + o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this + *tmp;
		delete tmp;
		return res;
	}
} // Sum

IOperand const * Int8::operator-( IOperand const & o ) const{ // Difference
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int8 const & i = dynamic_cast<Int8 const &>(o);
		long int v = toChar() - i.toChar();
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " - " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
TRACER(
		std::cout << " <" << tmp->description() << " - " << o.description() << "> ";
);		
		IOperand const * res = (*tmp) - o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = (*this) - *tmp;
		delete tmp;
		return res;
	}
}

IOperand const * Int8::operator*( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int8 const & i = dynamic_cast<Int8 const &>(o);
		long int v = toChar() * i.toChar();
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " * " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp * o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this * *tmp;
		delete tmp;
		return res;
	}
}

IOperand const * Int8::operator/( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int8 const & i = dynamic_cast<Int8 const &>(o);
		long int v = i.toChar();
		if (v == 0)
			throw( DivisionByZeroException());
		v = _v8 / v;
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " / " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp / o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this / *tmp;
		delete tmp;
		return res;
	}
} // Quotient

IOperand const * Int8::operator%( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int8 const & i = dynamic_cast<Int8 const &>(o);
		long int v = i.toChar();
		if (v == 0)
			throw( DivisionByZeroException());
		v = _v8 % v;
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " % " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp % o;
		delete tmp;
		return res;
	} else {//if (_type > o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this % *tmp;
		delete tmp;
		return res;
	}	
} // Modulo


Int8::OverflowException::OverflowException() {}
Int8::OverflowException::OverflowException(Int8::OverflowException const & e) : AVMException(e) {}
Int8::OverflowException::~OverflowException() throw () {}
Int8::OverflowException &Int8::OverflowException::operator=(Int8::OverflowException const &) { return *this; }
const char * Int8::OverflowException::what(void) const throw () 
{
	return "OverflowException : Number Too High";
}

Int8::UnderflowException::UnderflowException() {}
Int8::UnderflowException::UnderflowException(Int8::UnderflowException const & e) : AVMException(e)  {}
Int8::UnderflowException::~UnderflowException() throw () {}
Int8::UnderflowException &Int8::UnderflowException::operator=(Int8::UnderflowException const &) { return *this; }
const char * Int8::UnderflowException::what(void) const throw ()
{
	return "UnderflowException : Number Too Low";
}

Int8::DivisionByZeroException::DivisionByZeroException() {}
Int8::DivisionByZeroException::DivisionByZeroException(Int8::DivisionByZeroException const & e) : AVMException(e) {}
Int8::DivisionByZeroException::~DivisionByZeroException() throw () {}
Int8::DivisionByZeroException &Int8::DivisionByZeroException::operator=(Int8::DivisionByZeroException const &) { return *this; }
const char * Int8::DivisionByZeroException::what(void) const throw ()
{
	return "DivsionByZeroException : Division by zero";
}

std::ostream	&operator<<(std::ostream &out, Int8 const &f)
{
	out << "Int8(" << f.toString() <<")";
	return out;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:07:36 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 12:09:26 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int16.hpp"
#include "OperandFactory.class.hpp"
#include <sstream>

#include "AVM.hpp"
#define _verbose AVM::verbose()

const	eOperandType Int16::_type = PRECISION_INT16;

Int16::Int16() : _v16(0), _str("") {}

Int16::Int16(short int si) : _v16(si)
{
	_str = std::to_string(si);
}

Int16::Int16(long long int v)
{
//TRACER(	std::cout << "appel du constructeur Int16(long long int & " << v << ")" <<std::endl );
	if (v < MIN)
		throw(Int16::UnderflowException());
	else if (v > MAX)
		throw(Int16::OverflowException());
	_v16 = static_cast<short int>(v);
	_str = std::to_string(v);
}

Int16::Int16(std::string const & s) : _str(s)
{
//TRACER(	std::cout << "appel du constructeur Int16(std::string const & " << s << ")" <<std::endl );

	long int v = std::strtol(s.c_str(), NULL, 10);

	if (v < MIN)
		throw(Int16::UnderflowException());
	else if (v > MAX)
		throw(Int16::OverflowException());

	_v16 = static_cast<short int>(v);
}

Int16::Int16(Int16 const &o)
{
//TRACER(	std::cout << "appel du constructeur de copie Int16(" << o.description() << ")" <<std::endl );
	*this = o;
}

Int16::~Int16() {}

short int   	 	Int16::toShortInt( void ) const { return _v16; }
long int   		  	Int16::toLongInt( void ) const { return static_cast<long int>(_v16); }
long double    		Int16::toLongDouble( void ) const { return static_cast<long double>(_v16); };
std::string const & Int16::toString( void ) const{
	return _str;
}

std::string 		Int16::description( void ) const{
	std::stringstream ss;
	ss << "Int16(" << _v16 << ")";
	return ss.str();
}

Int16  &Int16::operator=(Int16 const &o)
{
	_v16 = o.toShortInt();
	_str = o.toString();
	return (*this);
}


int Int16::getPrecision( void ) const{
	return 16;
} // Precision of the type of the instance

eOperandType Int16::getType( void ) const{
	return _type;
} // Type of the instance

bool	Int16::operator==( IOperand const & o ) const{
	if (_type != o.getType())
		return false;
	Int16 const & op = dynamic_cast<Int16 const &>(o);
	//TRACER( std::cout << this->description() << " is " << (_v16 == op.toShortInt() ? "==" : "!=") << o.description() << std::endl);
	return _v16 == op.toShortInt();
}
bool	Int16::operator!=( IOperand const & o ) const{
	return !(*this == o);
}

IOperand const * Int16::operator+( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int16 const & i = dynamic_cast<Int16 const &>(o);
		long int v = toLongInt() + i.toLongInt();
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
		IOperand const * res = (*this) + (*tmp);
		delete tmp;
		return res;
	}
} // Sum

IOperand const * Int16::operator-( IOperand const & o ) const{ // Difference
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int16 const & i = dynamic_cast<Int16 const &>(o);
		long int v = toLongInt() - i.toLongInt();
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " - " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = (*tmp) - o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = (*this) - (*tmp);
		delete tmp;
		return res;
	}
}

IOperand const * Int16::operator*( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int16 const & i = dynamic_cast<Int16 const &>(o);
		long int v = toLongInt() * i.toLongInt();
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

IOperand const * Int16::operator/( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int16 const & i = dynamic_cast<Int16 const &>(o);
		long int v = i.toShortInt();
		if (v == 0)
			throw( DivisionByZeroException());
		v = _v16 / v;
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
	} else {//if (_type > o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this / *tmp;
		delete tmp;
		return res;
	}
} // Quotient

IOperand const * Int16::operator%( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int16 const & i = dynamic_cast<Int16 const &>(o);
		long int v = i.toShortInt();
		if (v == 0)
			throw( DivisionByZeroException());
		v = _v16 % v;
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
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this % *tmp;
		delete tmp;
		return res;
	}	
} // Modulo


Int16::OverflowException::OverflowException() {}
Int16::OverflowException::OverflowException(Int16::OverflowException const &e) : AVMException(e) { *this=e; }
Int16::OverflowException::~OverflowException() throw () {}
Int16::OverflowException &Int16::OverflowException::operator=(Int16::OverflowException const &) { return *this; }
const char * Int16::OverflowException::what(void) const throw () 
{
	return "Overflow : Number Too High";
}

Int16::UnderflowException::UnderflowException() {}
Int16::UnderflowException::UnderflowException(Int16::UnderflowException const &e) : AVMException(e) { *this=e; }
Int16::UnderflowException::~UnderflowException() throw () {}
Int16::UnderflowException &Int16::UnderflowException::operator=(Int16::UnderflowException const &) { return *this; }
const char * Int16::UnderflowException::what(void) const throw ()
{
	return "Underflow : Number Too Low";
}

Int16::DivisionByZeroException::DivisionByZeroException() {}
Int16::DivisionByZeroException::DivisionByZeroException(Int16::DivisionByZeroException const &e) : AVMException(e) { *this=e; }
Int16::DivisionByZeroException::~DivisionByZeroException() throw () {}
Int16::DivisionByZeroException &Int16::DivisionByZeroException::operator=(Int16::DivisionByZeroException const &) { return *this; }
const char * Int16::DivisionByZeroException::what(void) const throw ()
{
	return "DivsionByZeroException : Division by zero";
}


std::ostream	&operator<<(std::ostream &out, Int16 const *f)
{
	out << "Int16(" << f->toString() <<")";
	return out;
}


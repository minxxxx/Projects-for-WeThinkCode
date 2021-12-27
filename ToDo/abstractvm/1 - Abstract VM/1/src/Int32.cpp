/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:07:36 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 12:09:26 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"
#include "OperandFactory.class.hpp"
#include <sstream>

#include "AVM.hpp"
#define _verbose AVM::verbose()


const	eOperandType Int32::_type = PRECISION_INT32;

Int32::Int32() : _v32(0), _str("") {}

Int32::Int32(short int si) : _v32(si)
{
	_str = std::to_string(si);
}

Int32::Int32(long long int v) : _v32(v)
{
//	TRACER(	std::cout << "appel du constructeur Int32(long long int " << v << ")" <<std::endl );
	if (v < MIN)
		throw(Int32::UnderflowException());
	else if (v > MAX)
		throw(Int32::OverflowException());
	_str = std::to_string(v);
}

Int32::Int32(std::string const & s) : _str(s)
{
//	TRACER(	std::cout << "appel du constructeur Int32(std::string const & " << s << ")" <<std::endl );

	long long int v = std::strtol(s.c_str(), NULL, 10);

	if (v < MIN)
		throw(Int32::UnderflowException());
	else if (v > MAX)
		throw(Int32::OverflowException());

	_v32 = static_cast<long int>(v);
}

Int32::Int32(Int32 const &o)
{
	*this = o;
}

Int32::~Int32() {}

long int   		  	Int32::toLongInt( void ) const { return _v32; }
long long int   	Int32::toLongLongInt( void ) const { return static_cast<long long int>(_v32); } 
long double    		Int32::toLongDouble( void ) const { return static_cast<long double>(_v32); };
std::string const & Int32::toString( void ) const{
	return _str;
}

std::string 		Int32::description( void ) const{
	std::stringstream ss;
	ss << "Int32(" << _v32 << ")";
	return ss.str();
}

Int32  &Int32::operator=(Int32 const &o)
{
	_v32 = o.toLongInt();
	_str = o.toString();
	return (*this);
}


int Int32::getPrecision( void ) const{
	return 32;
} // Precision of the type of the instance

eOperandType Int32::getType( void ) const{
	return _type;
} // Type of the instance

bool	Int32::operator==( IOperand const & o ) const{
	if (_type != o.getType())
		return false;
	Int32 const & op = dynamic_cast<Int32 const &>(o);
	return _v32 == op.toLongInt();
}
bool	Int32::operator!=( IOperand const & o ) const{
	return !(*this == o);
}


IOperand const * Int32::operator+( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int32 const & i = dynamic_cast<Int32 const &>(o);
		long long int v = toLongLongInt() + i.toLongLongInt();
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(	std::cout << this->description() << " + " << o.description() << " = " << iop->description() );		
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

IOperand const * Int32::operator-( IOperand const & o ) const{ // Difference
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int32 const & i = dynamic_cast<Int32 const &>(o);
		long long int v = toLongLongInt() - i.toLongLongInt();
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER( std::cout << this->description() << " - " << o.description() << " = " << iop->description() );
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = (*tmp) - o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this - *tmp;
		delete tmp;
		return res;
	}
}

IOperand const * Int32::operator*( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int32 const & i = dynamic_cast<Int32 const &>(o);
		long long int v = toLongLongInt() * i.toLongLongInt();
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(	std::cout << this->description() << " * " << o.description() << " = " << iop->description() );		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp * o;
		delete tmp;
		return res;
	} else {//if (_type > o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this * *tmp;
		delete tmp;
		return res;
	}
}

IOperand const * Int32::operator/( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int32 const & i = dynamic_cast<Int32 const &>(o);
		long long int v = i.toLongInt();
		if (v == 0)
			throw( DivisionByZeroException());
		v = _v32 / v;
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(	std::cout << this->description() << " / " << o.description() << " = " << iop->description() );
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

IOperand const * Int32::operator%( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Int32 const & i = dynamic_cast<Int32 const &>(o);
		long long int v = i.toLongInt();
		if (v == 0)
			throw( DivisionByZeroException());
		v = _v32 % v;
		std::stringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << this->description() << " % " << o.description() << " = " << iop->description();
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


Int32::OverflowException::OverflowException() {}
Int32::OverflowException::OverflowException(Int32::OverflowException const & e) : AVMException(e) {}
Int32::OverflowException::~OverflowException() throw () {}
Int32::OverflowException &Int32::OverflowException::operator=(Int32::OverflowException const &) { return *this; }
const char * Int32::OverflowException::what(void) const throw () 
{
	return "Overflow : Number Too High";
}

Int32::UnderflowException::UnderflowException() {}
Int32::UnderflowException::UnderflowException(Int32::UnderflowException const & e) : AVMException(e) {}
Int32::UnderflowException::~UnderflowException() throw () {}
Int32::UnderflowException &Int32::UnderflowException::operator=(Int32::UnderflowException const &) { return *this; }
const char * Int32::UnderflowException::what(void) const throw ()
{
	return "Underflow : Number Too Low";
}

Int32::DivisionByZeroException::DivisionByZeroException() {}
Int32::DivisionByZeroException::DivisionByZeroException(Int32::DivisionByZeroException const & e) : AVMException(e) {}
Int32::DivisionByZeroException::~DivisionByZeroException() throw () {}
Int32::DivisionByZeroException &Int32::DivisionByZeroException::operator=(Int32::DivisionByZeroException const &) { return *this; }
const char * Int32::DivisionByZeroException::what(void) const throw ()
{
	return "DivsionByZeroException : Division by zero";
}

std::ostream	&operator<<(std::ostream &out, Int32 const *f)
{
	out << "Int32(" << f->toString() <<")";
	return out;
}


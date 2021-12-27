/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:07:36 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 12:09:26 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"
#include "OperandFactory.class.hpp"
#include <sstream>
#include <cmath>

#include "AVM.hpp"
#define _verbose AVM::verbose()


const	eOperandType Float::_type = PRECISION_FLOAT;


Float::Float() : _vF(0), _str("") {}

Float::Float(float f) : _vF(f)
{
	_str = std::to_string(f);
	
}

Float::Float(long double ld)
{
	if (ld < MIN){
//TRACER( std::cout << " error : " << ld << " < MIN : " << MIN <<std::endl );
		throw(Float::UnderflowException());
	}else if (ld > MAX){
		throw(Float::OverflowException());
	}
	_vF = static_cast<float>(ld);
	_str = std::to_string(ld);
}

Float::Float(std::string const & s) : _str(s)
{
//TRACER(	std::cout << "appel du constructeur Float(std::string const & " << s << ")" <<std::endl );

	long double v = std::stold(s.c_str());

	if (v < MIN)
		throw(Float::UnderflowException());
	else if (v > MAX)
		throw(Float::OverflowException());

	_vF = static_cast<float>(v);
}

Float::Float(Float const &o)
{
	*this = o;
}

Float::~Float() {}

float   		  	Float::toFloat( void ) const { return _vF; }
long double    		Float::toLongDouble( void ) const { return static_cast<long double>(_vF); };
std::string const & Float::toString( void ) const{
	return _str;
}

std::string 		Float::description( void ) const{
	std::stringstream ss;
	ss << "Float(" << _vF << ")";
	return ss.str();
}


Float  &Float::operator=(Float const &o)
{
	_vF = o.toFloat();
	_str = o.toString();
	return (*this);
}


int Float::getPrecision( void ) const{
	return 32;
} // Precision of the type of the instance

eOperandType Float::getType( void ) const{
	return _type;
} // Type of the instance

bool	Float::operator==( IOperand const & o ) const{
	if (_type != o.getType())
		return false;
	Float const & op = dynamic_cast<Float const &>(o);
	return _vF == op.toFloat();
}
bool	Float::operator!=( IOperand const & o ) const{
	return !(*this == o);
}


IOperand const * Float::operator+( IOperand const & o ) const{
	OperandFactory & factory = OperandFactory::get();
	eOperandType type = o.getType();

	if (_type == type) {
		Float const & f = dynamic_cast<Float const &>(o); 
		long double v = toLongDouble() + f.toLongDouble();
		std::ostringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " + " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp + o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this + *tmp;
		delete tmp;
		return res;
	}
} // Sum

IOperand const * Float::operator-( IOperand const & o ) const{ // Difference
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Float const & f = dynamic_cast<Float const &>(o);
		long double v = toLongDouble() - f.toLongDouble();
		std::ostringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " - " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp - o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this - *tmp;
		delete tmp;
		return res;
	}
}

IOperand const * Float::operator*( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Float const & f = dynamic_cast<Float const &>(o);
		long double v = toLongDouble() * f.toLongDouble();
		std::ostringstream ss;
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

IOperand const * Float::operator/( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Float const & f = dynamic_cast<Float const &>(o);
		long double v = f.toLongDouble();
		if (v == 0)
			throw( DivisionByZeroException());
		v = toLongDouble() / v;
		std::ostringstream ss;
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

IOperand const * Float::operator%( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Float const & f = dynamic_cast<Float const &>(o);
		float v = f.toFloat();
		if (v == 0)
			throw( DivisionByZeroException());
		v = fmod(_vF, v);;
		std::ostringstream ss;
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


Float::OverflowException::OverflowException() {}
Float::OverflowException::OverflowException(Float::OverflowException const & e) : AVMException(e) {}
Float::OverflowException::~OverflowException() throw () {}
Float::OverflowException &Float::OverflowException::operator=(Float::OverflowException const &) { return *this; }
const char * Float::OverflowException::what(void) const throw () 
{
	return "Overflow : Number Too High";
}

Float::UnderflowException::UnderflowException() {}
Float::UnderflowException::UnderflowException(Float::UnderflowException const & e) : AVMException(e) {}
Float::UnderflowException::~UnderflowException() throw () {}
Float::UnderflowException &Float::UnderflowException::operator=(Float::UnderflowException const &) { return *this; }
const char * Float::UnderflowException::what(void) const throw ()
{
	return "Underflow : Number Too Low";
}

Float::BadOperationException::BadOperationException() {}
Float::BadOperationException::BadOperationException(Float::BadOperationException const & e) : AVMException(e) {}
Float::BadOperationException::~BadOperationException() throw () {}
Float::BadOperationException &Float::BadOperationException::operator=(Float::BadOperationException const &) { return *this; }
const char * Float::BadOperationException::what(void) const throw ()
{
	return "Bad operation : Operation '%%' is not defined for type float.";
}

Float::DivisionByZeroException::DivisionByZeroException() {}
Float::DivisionByZeroException::DivisionByZeroException(Float::DivisionByZeroException const & e) : AVMException(e) {}
Float::DivisionByZeroException::~DivisionByZeroException() throw () {}
Float::DivisionByZeroException &Float::DivisionByZeroException::operator=(Float::DivisionByZeroException const &) { return *this; }
const char * Float::DivisionByZeroException::what(void) const throw ()
{
	return "DivsionByZeroException : Division by zero";
}

std::ostream	&operator<<(std::ostream &out, Float const *f)
{
	out << "Float(" << f->toString() <<")";
	return out;
}


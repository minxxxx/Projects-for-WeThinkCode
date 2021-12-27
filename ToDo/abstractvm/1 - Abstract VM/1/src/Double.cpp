/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:07:36 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 12:09:26 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"
#include "OperandFactory.class.hpp"
#include <sstream>
#include <cmath>

#include "AVM.hpp"
#define _verbose AVM::verbose()

const	eOperandType Double::_type = PRECISION_DOUBLE;


Double::Double() : _vD(0), _str("") {}

Double::Double(double d) : _vD(d)
{
	_str = std::to_string(d);
}

Double::Double(long double ld)
{
	if (ld < MIN)
		throw(Double::UnderflowException());
	else if (ld > MAX)
		throw(Double::OverflowException());
	_vD = static_cast<double>(ld);
	_str = std::to_string(ld);
}

Double::Double(std::string const & s) : _str(s)
{
//TRACER(	std::cout << "appel du constructeur Double(std::string const & " << s << ")" <<std::endl );
	long double v = std::stold(s.c_str());
//TRACER( std::cout << "v = std::stold(s.c_str()) = \"" << v << "\"" << std::endl);
	if (v < MIN)
		throw(Double::UnderflowException());
	else if (v > MAX)
		throw(Double::OverflowException());

	_vD = static_cast<double>(v);
//TRACER( std::cout << " constructeur Double(" << v << "): _vD=" << _vD << ", _str = " << _str << std::endl);
}

Double::Double(Double const &o)
{
	*this = o;
}

Double::~Double() {}

double   		  	Double::toDouble( void ) const { return _vD; }
long double    		Double::toLongDouble( void ) const { return static_cast<long double>(_vD); };
std::string const & Double::toString( void ) const{
	return _str;
}

std::string 		Double::description( void ) const{
	std::stringstream ss;
	ss << "Double(" << _vD << ")";
	return ss.str();
}


Double  &Double::operator=(Double const &o)
{
	_vD = o.toDouble();
	_str = o.toString();
	return (*this);
}


int Double::getPrecision( void ) const{
	return 64;
} // Precision of the type of the instance

eOperandType Double::getType( void ) const{
	return _type;
} // Type of the instance

bool	Double::operator==( IOperand const & o ) const{
	if (_type != o.getType())
		return false;
	Double const & op = dynamic_cast<Double const &>(o);
	return (_vD == op.toDouble());
}
bool	Double::operator!=( IOperand const & o ) const{
	return (!(*this == o));
}


IOperand const * Double::operator+( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Double const & d = dynamic_cast<Double const &>(o);
		long double v = toLongDouble() + d.toLongDouble();
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

IOperand const * Double::operator-( IOperand const & o ) const{ // Difference
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Double const & d = dynamic_cast<Double const &>(o);
		long double v = toLongDouble() - d.toLongDouble();
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

IOperand const * Double::operator*( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Double const & d = dynamic_cast<Double const &>(o);
		long double v = toLongDouble() * d.toLongDouble();
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
	} else {//if (_type > o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this * *tmp;
		delete tmp;
		return res;
	}
}

IOperand const * Double::operator/( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Double const & d = dynamic_cast<Double const &>(o);
		long double v = d.toLongDouble();
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
	} else {//if (_type > o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this / *tmp;
		delete tmp;
		return res;
	}
} // Quotient

IOperand const * Double::operator%( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		Double const & d = dynamic_cast<Double const &>(o);
		long double v = d.toLongDouble();
		if (v == 0)
			throw( DivisionByZeroException());
		v = fmod(toLongDouble(), d.toLongDouble());
		std::ostringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
TRACER(
		std::cout << " {" << this->description() << " % " << o.description() << " = " << iop->description() << "} ";
);		
		return iop;
	} else if (_type < o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, _str);
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


Double::OverflowException::OverflowException() {}
Double::OverflowException::OverflowException(Double::OverflowException const & e) : AVMException(e) {}
Double::OverflowException::~OverflowException() throw () {}
Double::OverflowException &Double::OverflowException::operator=(Double::OverflowException const &) { return *this; }
const char * Double::OverflowException::what(void) const throw () 
{
	return "Overflow : Number Too High";
}

Double::UnderflowException::UnderflowException() {}
Double::UnderflowException::UnderflowException(Double::UnderflowException const & e) : AVMException(e) {}
Double::UnderflowException::~UnderflowException() throw () {}
Double::UnderflowException &Double::UnderflowException::operator=(Double::UnderflowException const &) { return *this; }
const char * Double::UnderflowException::what(void) const throw ()
{
	return "Underflow : Number Too Low.";
}

Double::DivisionByZeroException::DivisionByZeroException() {}
Double::DivisionByZeroException::DivisionByZeroException(Double::DivisionByZeroException const & e) : AVMException(e) {}
Double::DivisionByZeroException::~DivisionByZeroException() throw () {}
Double::DivisionByZeroException &Double::DivisionByZeroException::operator=(Double::DivisionByZeroException const &) { return *this; }
const char * Double::DivisionByZeroException::what(void) const throw ()
{
	return "DivsionByZeroException : Division by zero";
}

std::ostream	&operator<<(std::ostream &out, Double const *f)
{
	out << "Double(" << f->description() <<")";
	return out;
}
std::ostream	&operator<<(std::ostream &out, Double const &f)
{
	out << "Double(" << f.description() <<")";
	return out;
}


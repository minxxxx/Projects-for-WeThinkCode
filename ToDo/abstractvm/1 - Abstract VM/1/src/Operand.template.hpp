/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.template.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:03:51 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 21:43:03 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

#include "IOperand.class.hpp"
#include "OperandFactory.class.hpp"
#include "AVMException.hpp"
#include <iostream>
#include <sstream>
#include <float.h>
#include <cmath>
#include "AVM.hpp"



static constexpr const long double VALMIN[5] = { SCHAR_MIN, SHRT_MIN, LONG_MIN, -FLT_MAX, -DBL_MAX};
static constexpr const long double VALMAX[5] = { SCHAR_MAX, SHRT_MAX, LONG_MAX, FLT_MAX, DBL_MAX};
static const int PRECISION[5] = { 8, 16, 32, 32, 64 };
static const std::string TYPENAME[5] = { "Int8", "Int16", "Int32", "Float", "Double" };



template <typename baseType, eOperandType opType>
class Operand : public IOperand
{
private:
	static const	eOperandType _type = opType;
	baseType		_v;
	std::string 	_str;

public:

	Operand() : _v(0), _str("") {}
	Operand(baseType v) : _v(v) { _str = std::to_string(v); }
	Operand(long double v) {
		//if(AVM::verbose()) {	std::cout << "appel du constructeur " << TYPENAME[opType] << "(long double " << v << ")" <<std::endl ;}
		if (v < VALMIN[opType])
			throw(UnderflowException());
		else if (v > VALMAX[opType])
			throw(OverflowException());
		_v = static_cast<baseType>(v);
		_str = std::to_string(v);
	}

	Operand(std::string const & s) : _str(s)
	{
		//if(AVM::verbose()) {	std::cout << "appel du constructeur " << TYPENAME[opType] << "(std::string const & " << s << ")" <<std::endl ;}
		long double v = std::stold(s.c_str());
		if(AVM::verbose()) { std::cout << "_v = std::stold(s.c_str()) = \"" << v << "\"" << std::endl;}
		if (v < VALMIN[opType]){
			//if(AVM::verbose()) { std::cout << "  => UnderflowException ! " << v << " <  " << VALMIN[opType] << std::endl;}
			throw(UnderflowException());
		}else if (v > VALMAX[opType]){
			//if(AVM::verbose()) { std::cout << "  => OverflowException ! " << v << " >  " << VALMIN[opType] << std::endl;}
			throw(OverflowException());
		}

		_v = static_cast<baseType>(v);
		//if(AVM::verbose()) { std::cout << " constructeur " << TYPENAME[opType] << "(" << v << "): _v=" << _v << ", _str = " << _str << std::endl;}
	}

	Operand(Operand const &o) {	*this = o; }
	
	~Operand() {}
	
	Operand  &operator=(Operand const &o)
	{
		_v = o.toOperand();
		_str = o.toString();
		return (*this);
	}

	eOperandType 		getType( void ) const 		{ return _type; }  // Type of the instance
	int getPrecision( void ) const{
		return PRECISION[opType];
	} // Precision of the type of the instance



	baseType  toBaseType( void ) const { return _v; }

	long double    		toLongDouble( void ) const {
		return static_cast<long double>(_v); 
	};

	std::string const & toString( void ) const{
		return _str;
	}

	std::string 		description( void ) const{
		std::stringstream ss;
		ss << TYPENAME[opType] <<"(" << _str << ")";
		return ss.str();
	}

	bool 				operator==( IOperand const & o ) const {
		if (_type != o.getType())
			return false;
		Operand<baseType, opType> const & op = dynamic_cast<Operand<baseType, opType> const &>(o);
		return _v == op._v;
	}
	bool 				operator!=( IOperand const & o) const {
		return !(*this == o);
	}

	bool 				operator>( IOperand const & o ) const {
		eOperandType type = o.getType();

		OperandFactory & factory = OperandFactory::get();
		if (_type == type) {
			Operand<baseType, opType> const & d = dynamic_cast<Operand<baseType, opType> const &>(o);
			bool result = (toLongDouble() > d.toLongDouble());
// if(AVM::verbose() && result) { std::cout << " { ds >" << this << "  >  "  << o << "} "; }
// if(AVM::verbose() && !result) { std::cout << " { ds > " << this << "  <=  "  << o << "} "; }		
			return result;
		} else if (_type < type) {
			IOperand const * tmp = factory.createOperand(type, _str);
			//IOperand const * res = *tmp + o;
			bool result = (*tmp > o);
			delete tmp;
			return result;
		} else {//if (_type > type) {
			IOperand const * tmp = factory.createOperand(_type, o.toString());
			//IOperand const * res = *this + *tmp;
			bool result = (*this > *tmp);
			delete tmp;
			return result;
		}
	} // >
	
	bool 				operator<( IOperand const & o) const {
		bool result = (!(*this > o) && (*this != o));
// if(AVM::verbose() && result) { std::cout << " {ds <" << this << "  <  "  << o << "} "; }
// if(AVM::verbose() && !result) { std::cout << " { ds  <" << this << "  >=  "  << o << "} "; }
		return result;
	}

	bool 				operator>=( IOperand const & o) const {
		bool result = ((*this > o) || (*this == o));
// if(AVM::verbose() && result) { std::cout << " { ds >= true  " << this << "  >=  "  << o << "} "; }
// if(AVM::verbose() && !result) { std::cout << " {ds >=  false" << this << "  <  "  << o << "} "; }
		return result;
	}

	bool 				operator<=( IOperand const & o) const {
		bool result = ((*this < o) || (*this == o));
// if(AVM::verbose() && result) { std::cout << " {ds <=" << this << "  <=  "  << o << "} "; }
// if(AVM::verbose() && !result) { std::cout << " {ds <=" << this << "  <  "  << o << "} "; }
		return result;
	}

	// IOperand const * 	getmax( IOperand const &op1, IOperand const &op2) const {
	// 	if (op1 > op2)
	// 		return &op1;
	// 	else
	// 		return &op2;
	// }


	IOperand const * operator+( IOperand const & o ) const{
		eOperandType type = o.getType();

		OperandFactory & factory = OperandFactory::get();
		if (_type == type) {
			Operand<baseType, opType> const & d = dynamic_cast<Operand<baseType, opType> const &>(o);
			long double v = toLongDouble() + d.toLongDouble();
			//long double v = toLongDouble() + o.toLongDouble();
			std::ostringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
if(AVM::verbose()) { std::cout << " {" << this << " + " << o << " = " << iop << "} "; }		
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

	IOperand const * operator-( IOperand const & o ) const{ // Difference
		eOperandType type = o.getType();

		OperandFactory & factory = OperandFactory::get();
		if (_type == type) {
			Operand<baseType, opType> const & d = dynamic_cast<Operand<baseType, opType> const &>(o);
			long double v = toLongDouble() - d.toLongDouble();
			std::ostringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
if(AVM::verbose()) { std::cout << " {" << this << " - " << o << " = " << iop << "} "; }		
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

	IOperand const * operator*( IOperand const & o ) const{
		eOperandType type = o.getType();

		OperandFactory & factory = OperandFactory::get();
		if (_type == type) {
			Operand<baseType, opType> const & d = dynamic_cast<Operand<baseType, opType> const &>(o);
			long double v = toLongDouble() * d.toLongDouble();
			std::ostringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
if(AVM::verbose()) { std::cout << " {" << this << " * " << o << " = " << iop << "} ";}		
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

	IOperand const * operator/( IOperand const & o ) const{
		eOperandType type = o.getType();

		OperandFactory & factory = OperandFactory::get();
		if (_type == type) {
			Operand<baseType, opType> const & d = dynamic_cast<Operand<baseType, opType> const &>(o);
			long double v = d.toLongDouble();
			if (v == 0)
				throw( DivisionByZeroException());
			v = toLongDouble() / v;
			std::ostringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
if(AVM::verbose()) { std::cout << " {" << this << " / " << o << " = " << iop << "} "; }		
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

	IOperand const * operator%( IOperand const & o ) const{
		eOperandType type = o.getType();

		OperandFactory & factory = OperandFactory::get();
		if (_type == type) {
			Operand<baseType, opType> const & d = dynamic_cast<Operand<baseType, opType> const &>(o);
			long double v = d.toLongDouble();
			if (v == 0)
				throw( DivisionByZeroException());
			v = fmodl(toLongDouble(), d.toLongDouble());
			std::ostringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
if(AVM::verbose()) { std::cout << " {" << this << " % " << o << " = " << iop << "} "; }		
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


	class OverflowException : public AVMException {
	public:
		OverflowException(){}
		OverflowException(OverflowException const & e) : AVMException(e) {}
		~OverflowException() throw (){}
		OverflowException &operator=(OverflowException const &){ return *this; }
		const char * what(void) const throw ()
		{
			return "Overflow : Number Too High";
		}
	};

	class UnderflowException : public AVMException {
	public:
		UnderflowException(){}
		UnderflowException(UnderflowException const & e) : AVMException(e) {}
		~UnderflowException() throw (){}
		UnderflowException &operator=(UnderflowException const &){ return *this; }
		const char * what(void) const throw ()
		{
			return "Underflow : Number Too Low.";
		}
	};
	class DivisionByZeroException : public AVMException {
	public:
		DivisionByZeroException(){}
		DivisionByZeroException(DivisionByZeroException const & e) : AVMException(e) {}
		~DivisionByZeroException() throw (){}
		DivisionByZeroException &operator=(DivisionByZeroException const &){ return *this; }
		const char * what(void) const throw ()
		{
			return "DivsionByZeroException : Division by zero";
		}
	};
};

template <typename baseType, eOperandType opType>
std::ostream	&operator<<(std::ostream &out, Operand<baseType, opType> const *f)
{
	out << TYPENAME[opType] << "(" << f->description() <<")";
	return out;
}

template <typename baseType, eOperandType opType>
std::ostream	&operator<<(std::ostream &out, Operand<baseType, opType> const &f)
{
	out << TYPENAME[opType] << "(" << f.description() <<")";
	return out;
}

#endif

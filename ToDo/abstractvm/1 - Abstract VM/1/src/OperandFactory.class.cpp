/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:49:33 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/22 17:14:52 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.class.hpp"
#include "Operand.template.hpp"
#include <iostream>


typedef Operand<char, PRECISION_INT8>  Int8;
typedef Operand<short int, PRECISION_INT16> Int16;
typedef Operand<long int, PRECISION_INT32> Int32;
typedef Operand<float, PRECISION_FLOAT> Float;
typedef Operand<double, PRECISION_DOUBLE> Double;


OperandFactory::OperandFactory() {

	createFuncs[PRECISION_INT8] = &OperandFactory::createInt8;
	createFuncs[PRECISION_INT16] = &OperandFactory::createInt16;
	createFuncs[PRECISION_INT32] = &OperandFactory::createInt32;
	createFuncs[PRECISION_FLOAT] = &OperandFactory::createFloat;
	createFuncs[PRECISION_DOUBLE] = &OperandFactory::createDouble;	
}
OperandFactory::OperandFactory(OperandFactory const &) {}
OperandFactory  &OperandFactory::operator=(OperandFactory const &) { return (*this); }
OperandFactory::~OperandFactory() {}

IOperand const *OperandFactory::createInt8(std::string const & value) const
{
	return new Int8(value);
	//return new Int8(std::stoll(value));
}

IOperand const *OperandFactory::createInt16(std::string const & value) const
{
	return new Int16(value);
	//return new Int16(std::stoll(value));
}

IOperand const *OperandFactory::createInt32(std::string const & value) const
{
	return new Int32(value);
	//return new Int32(std::stoll(value));
}

IOperand const *OperandFactory::createFloat(std::string const & value) const
{
	return new Float(value);
//	return new Float(std::stold(value));
}

IOperand const *OperandFactory::createDouble(std::string const & value) const
{
	return new Double(value);
//	return new Double(std::stold(value));
}


IOperand const * OperandFactory::createOperand(
		eOperandType type, std::string const & value ) const
{
	return ((*this).*createFuncs[type])(value);
}

std::ostream	&operator<<(std::ostream &out, IOperand const &iop)
{
	out << TYPENAME[iop.getType()] << "(" << iop.toString() <<")";
	return out;
}

std::ostream	&operator<<(std::ostream &out, IOperand const *iop)
{
	out << TYPENAME[iop->getType()] << "(" << iop->toString() <<")";
	return out;
}



#include <Double.hpp>
#include <iostream>
#include <to_string.hpp>

Double::Double(void)
{
}

Double::Double(double value)
{
	this->_value = value;
	this->_stringRepresentation = to_string(value);
}

Double::Double(Double const & src)
{
	*this = src;
}

Double::~Double(void)
{
}

Double & Double::operator=(Double const & rhs)
{
	_value = rhs._value;
	return *this;
}

int	Double::getPrecision(void) const
{
	return static_cast<int>(OperandTypeDouble);
}

eOperandType	Double::getType(void) const
{
	return OperandTypeDouble;
}

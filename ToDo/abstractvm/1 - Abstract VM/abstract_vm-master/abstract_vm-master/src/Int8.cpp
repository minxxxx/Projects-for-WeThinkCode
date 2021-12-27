#include <Int8.hpp>
#include <iostream>
#include <to_string.hpp>

Int8::Int8(void)
{
}

Int8::Int8(int8_t value)
{
	this->_value = value;
	this->_stringRepresentation = to_string(value);
}

Int8::Int8(Int8 const & src)
{
	*this = src;
}

Int8::~Int8(void)
{
}

Int8 & Int8::operator=(Int8 const & rhs)
{
	_value = rhs._value;
	return *this;
}

int	Int8::getPrecision(void) const
{
	return static_cast<int>(OperandTypeInt8);
}

eOperandType	Int8::getType(void) const
{
	return OperandTypeInt8;
}

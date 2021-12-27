#include <OperandFactory.hpp>
#include <Int8.hpp>
#include <Int16.hpp>
#include <Int32.hpp>
#include <Float.hpp>
#include <Double.hpp>

IOperand const * (OperandFactory::*OperandFactory::_hashTable[5])(std::string const &) const = {
	&OperandFactory::createInt8,
	&OperandFactory::createInt16,
	&OperandFactory::createInt32,
	&OperandFactory::createFloat,
	&OperandFactory::createDouble
};

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	return (this->*_hashTable[type])(value);
}


IOperand const * OperandFactory::createInt8(std::string const & value) const
{
	double dvalue = 0;
	try {
		dvalue = std::stod(value);
	} catch (std::out_of_range const & e)
	{
		throw RuntimeException("Out of range, this value could not fit in an int8");
	}

	if (dvalue < std::numeric_limits<int8_t>::min())
		throw RuntimeException("Underflow : tried to store " + value + " in an int8.");
	else if (dvalue > std::numeric_limits<int8_t>::max())
		throw RuntimeException("Overflow : tried to store " + value + " in an int8.");
	return new Int8(static_cast<int8_t>(dvalue));
}

IOperand const * OperandFactory::createInt16(std::string const & value) const
{
	double dvalue = 0;
	try {
		dvalue = std::stod(value);
	} catch (std::out_of_range const & e)
	{
		throw RuntimeException("Out of range, this value could not fit in an int16");
	}

	if (dvalue < std::numeric_limits<int16_t>::min())
		throw RuntimeException("Underflow : tried to store " + value + " in an int16.");
	else if (dvalue > std::numeric_limits<int16_t>::max())
		throw RuntimeException("Overflow : tried to store " + value + " in an int16.");
	return new Int16(static_cast<int16_t>(std::stod(value)));
}

IOperand const * OperandFactory::createInt32(std::string const & value) const
{
	double dvalue = 0;
	try {
		dvalue = std::stod(value);
	} catch (std::out_of_range const & e)
	{
		throw RuntimeException("Out of range, this value could not fit in an int32");
	}

	if (dvalue < std::numeric_limits<int32_t>::min())
		throw RuntimeException("Underflow : tried to store " + value + " in an int32.");
	else if (dvalue > std::numeric_limits<int32_t>::max())
		throw RuntimeException("Overflow : tried to store " + value + " in an int32.");
	return new Int32(static_cast<int32_t>(std::stod(value)));
}

IOperand const * OperandFactory::createFloat(std::string const & value) const
{
	double dvalue = 0;
	try {
		dvalue = std::stod(value);
	} catch (std::out_of_range const & e)
	{
		throw RuntimeException("Out of range, this value could not fit in a float");
	}

	if (dvalue < std::numeric_limits<float>::min())
		throw RuntimeException("Underflow : tried to store " + value + " in a float.");
	else if (dvalue > std::numeric_limits<float>::max())
		throw RuntimeException("Overflow : tried to store " + value + " in a float.");
	return new Float(static_cast<float>(std::stod(value)));
}

IOperand const * OperandFactory::createDouble(std::string const & value) const
{
	double dvalue = 0;
	try {
		dvalue = std::stod(value);
	} catch (std::out_of_range const & e)
	{
		throw RuntimeException("Out of range, this value could not fit in a double");
	}

	return new Double(dvalue);
}

OperandFactory::OperandFactory(void)
{

}

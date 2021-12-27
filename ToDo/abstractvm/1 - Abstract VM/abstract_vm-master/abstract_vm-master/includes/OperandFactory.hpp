#ifndef OPERAND_FACTORY_CLASS_H
# define OPERAND_FACTORY_CLASS_H

# include <string>
# include <iostream>
# include <IOperand.hpp>

# define INT8_MIN -128
# define INT8_MAX 127
# define INT16_MIN -32768
# define INT16_MAX 32767
# define INT32_MAX 2147483647

# include <cfloat>

class OperandFactory {
public:
	OperandFactory(void);

	IOperand const * createOperand(eOperandType type, std::string const & value) const;

private:
	static IOperand const * (OperandFactory::*_hashTable[5])(std::string const &) const;

	IOperand const * createInt8(std::string const & value) const;
	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;

};
#endif

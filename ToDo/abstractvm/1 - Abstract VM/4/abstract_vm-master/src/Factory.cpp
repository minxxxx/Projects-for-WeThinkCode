
#include "../include/VirtualMachine.hpp"
#include "../include/Operand.hpp"

Factory::Factory(){
	funcs.push_back(&Factory::createInt8);
	funcs.push_back(&Factory::createInt16);
	funcs.push_back(&Factory::createInt32);
	funcs.push_back(&Factory::createFloat);
	funcs.push_back(&Factory::createDouble);
}

Factory::~Factory() {}

IOperand const* Factory::createOperand(eOperandType type, std::string const &value) const
{
	IOperand const* (Factory::*func)(std::string const & value) const;
	func = funcs[type];
	return (const IOperand *) ((*this.*func)(value));
}

IOperand const* Factory::createInt8(std::string const &value) const
{
	int val = std::stoi(value);
	return new Operand<int8_t>(0, std::to_string(val), eOperandType::INT8, (int8_t)std::stoi(value));
}

IOperand const* Factory::createInt16(std::string const &value) const
{
	int val = std::stoi(value);
	return new Operand<int16_t>(1, std::to_string(val), eOperandType::INT16, (int16_t)std::stoi(value));
}

IOperand const* Factory::createInt32(std::string const &value) const
{
	int val = std::stoi(value);
	return new Operand<int>(2, std::to_string(val), eOperandType::INT32, std::stoi(value));
}

IOperand const* Factory::createFloat(std::string const &value) const
{
	return new Operand<float>(3, value, eOperandType::FLOAT, (int8_t)std::stof(value));
}

IOperand const* Factory::createDouble(std::string const &value) const
{
	return new Operand<double>(4, value, eOperandType::DOUBLE, (int8_t)std::stod(value));
}
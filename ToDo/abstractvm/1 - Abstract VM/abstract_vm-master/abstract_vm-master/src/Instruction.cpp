#include <Instruction.hpp>
#include <SyntaxicException.hpp>

Instruction::Instruction(eInstructionType type) : _type(type)
{
}
Instruction::Instruction(eInstructionType type, const IOperand *value) : _type(type), _value(value)
{
}


Instruction::Instruction (Instruction const & src)
{
	*this = src;
}

Instruction::Instruction(void)
{
	throw SyntaxicException("Tried to call private constructor of Instruction.");
}

Instruction & Instruction::operator=(Instruction const & rhs)
{
	_type = rhs._type;
	_value = rhs._value; // should i deep or shallow copy ? Not yet sure.

	return *this;
}

Instruction::~Instruction(void)
{
}

eInstructionType	Instruction::getType(void) const
{
	return _type;
}

const IOperand	*Instruction::getValue(void) const
{
	return _value;
}

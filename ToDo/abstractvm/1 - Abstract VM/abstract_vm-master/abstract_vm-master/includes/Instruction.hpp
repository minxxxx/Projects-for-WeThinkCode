#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <eInstructionType.hpp>
# include <IOperand.hpp>

class Instruction {
public:
	Instruction(eInstructionType type);
	Instruction(eInstructionType type, const IOperand *value);

	Instruction(Instruction const & src);
	~Instruction(void);

	Instruction & operator=(Instruction const & rhs);

	eInstructionType	getType(void) const;
	const IOperand			*getValue(void) const;
private:
	Instruction(void);

	eInstructionType _type;
	const IOperand	*_value;
};

#endif

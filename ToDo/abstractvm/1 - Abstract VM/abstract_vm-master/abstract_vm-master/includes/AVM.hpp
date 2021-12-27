#ifndef AVM_CLASS_H
# define AVM_CLASS_H

# include <Instruction.hpp>
# include <IOperand.hpp>
# include <stack>
# include <vector>
# include <map>
# include <eInstructionType.hpp>

class AVM {
public:
	AVM(std::vector<Instruction> instructions);
	AVM(AVM const & src);
	~AVM(void);

	AVM & operator=(AVM const & rhs);

	void	execute(void);

private:
	static std::map<eInstructionType, void (AVM::*)(const Instruction &)> _funcMap;

	AVM(void);

	std::stack<const IOperand*> _stack;
	std::vector<Instruction> _instructions;

	void	ExecPush(const Instruction & _instruction);
	void	ExecPop(const Instruction & _instruction);
	void	ExecDump(const Instruction & _instruction);
	void	ExecAssert(const Instruction & _instruction);
	void	ExecAdd(const Instruction & _instruction);
	void	ExecSub(const Instruction & _instruction);
	void	ExecMul(const Instruction & _instruction);
	void	ExecDiv(const Instruction & _instruction);
	void	ExecMod(const Instruction & _instruction);
	void	ExecPrint(const Instruction & _instruction);
	void	ExecExit(const Instruction & _instruction);

	const IOperand	*pop_operand(std::string operation);
	const IOperand	*peek_operand(std::string operation);

};
#endif

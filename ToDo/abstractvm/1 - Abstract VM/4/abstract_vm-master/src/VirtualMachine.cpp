#include "../include/VirtualMachine.hpp"

void    execute_cmds(std::vector<Instruction> & cmds){
    if (cmds[cmds.size() - 1].cmd != Instructions::EXIT)
        throw myexception("Error: Last command is not an EXIT command");
    std::cout << "all good" << std::endl;

	std::vector<IOperand const *> stack;
	for (size_t i = 0, size = cmds.size(); i < size; i++){
		//std::cout << "stack size : " << stack.size() << std::endl;
		//if (stack.size() > 0)
		//	std::cout << "stack top : " << stack[stack.size() - 1]->toString() << std::endl;
		try
		{
			switch (cmds[i].cmd){
				case Instructions::PUSH:
					pushInstruction(cmds[i], stack);
					break;
				case Instructions::POP:
					popInstruction(stack);
					break;
				case Instructions::DUMP:
					dumpInstruction(stack);
					break;
				case Instructions::ASSERT:
					assertInstruction(cmds[i], stack);
					break;
				case Instructions::ADD :
					addInstruction(stack);
					break;
				case Instructions::SUB :
					subInstruction(stack);
					break;
				case Instructions::MUL :
					mulInstruction(stack);
					break;
				case Instructions::DIV :
					divInstruction(stack);
					break;
				case Instructions::MOD :
					modInstruction(stack);
					break;
				case Instructions::PRINT :
					printInstruction(stack);
					break;
				case Instructions::EXIT :
					exitInstruction(stack);
					return;
				default:
					throw myexception((std::string("Invalid Instruction") +
					  cmds[i].instruction_line).c_str());
			}
		}catch (myexception & e){
			exit(EXIT_FAILURE);
		}

	}
}

eOperandType    getType(long double num){
	if (num < -128 || num > 127)
		return eOperandType::INT8;
	if (num < -32768 || num > 32767)
		return eOperandType::INT16;
	if (num < -2147483648 || num > 2147483647)
		return eOperandType::INT32;
	if (num < -FLT_MAX || num > FLT_MAX)
		return eOperandType::FLOAT;
	if (num < -DBL_MAX || num > DBL_MAX)
		return eOperandType::DOUBLE;
	return eOperandType::ZERO;
}

void    pushInstruction(Instruction & cmd, std::vector<IOperand const *> & stack){
	Factory factory;
	IOperand const * val = factory.createOperand(cmd.type, cmd.value);
	stack.push_back(val);
}

void    popInstruction(std::vector<IOperand const *> & stack){
	if (stack.size() == 0)
		throw myexception("Error: Stack is empty. Cannot perform pops ops");
	const IOperand * val = stack[stack.size() - 1];
	delete val;
	stack.pop_back();
}

void    dumpInstruction(std::vector<IOperand const *> & stack){
	if (stack.size() == 0)
		return;
	std::cout << "--------------" << std::endl;
	for (size_t i = stack.size() - 1; i != 0; i--){
		std::cout << stack[i]->toString() << std::endl;
	}
	std::cout << stack[0]->toString() << std::endl;
	std::cout << "--------------" << std::endl;
}

void    assertInstruction(Instruction & cmd, std::vector<IOperand const *> & stack){
	if (stack.size() == 0)
		throw myexception("Error: stack is empty. Cannot perform assert ops");
	long double val = std::stold(cmd.value);
	if (cmd.type != stack[stack.size() - 1]->getType())
		throw myexception("Assert value type does not match stack top type");
	if (val != std::stold(stack[stack.size() - 1]->toString()))
		throw myexception("Assert value does not match stack top value");
}

void    addInstruction(std::vector<IOperand const *> & stack){
	if (stack.size() < 2)
		throw myexception("Error: Stack has less than 2 values to perform add ops");
	const IOperand *top = stack[stack.size() - 1];
	stack.pop_back();
	const IOperand *next = stack[stack.size() - 1];
	stack.pop_back();
	stack.push_back(*next + *top);
	delete top;
	delete next;
}

void    subInstruction(std::vector<IOperand const *> & stack){
	if (stack.size() < 2)
		throw myexception("Error: Stack has less than 2 values to perform sub ops");
	const IOperand *top = stack[stack.size() - 1];
	stack.pop_back();
	const IOperand *next = stack[stack.size() - 1];
	stack.pop_back();
	stack.push_back(*next - *top);
	delete top;
	delete next;
}
void    mulInstruction(std::vector<IOperand const *> & stack){
	if (stack.size() < 2)
		throw myexception("Error: Stack has less than 2 values to perform mul ops");
	const IOperand *top = stack[stack.size() - 1];
	stack.pop_back();
	const IOperand *next = stack[stack.size() - 1];
	stack.pop_back();
	stack.push_back(*next * *top);
	delete top;
	delete next;
}
void    divInstruction(std::vector<IOperand const *> & stack){
	if (stack.size() < 2)
		throw myexception("Error: Stack has less than 2 values to perform div ops");
	const IOperand *top = stack[stack.size() - 1];
	stack.pop_back();
	const IOperand *next = stack[stack.size() - 1];
	stack.pop_back();
	stack.push_back(*next / *top);
	delete top;
	delete next;
}
void    modInstruction(std::vector<IOperand const *> & stack){
	if (stack.size() < 2)
		throw myexception("Error: Stack has less than 2 values to perform mod ops");
	const IOperand *top = stack[stack.size() - 1];
	stack.pop_back();
	const IOperand *next = stack[stack.size() - 1];
	stack.pop_back();
	stack.push_back(*next % *top);
	delete top;
	delete next;
}

void    printInstruction(std::vector<IOperand const *> & stack){

}

void    exitInstruction(std::vector<IOperand const *> & stack){
	for (size_t i = stack.size() - 1; i != 0; i--){
		const IOperand * val = stack[i];
		delete val;
	}
	const IOperand * val = stack[0];
	delete val;
	stack.erase(stack.begin(), stack.end());
}
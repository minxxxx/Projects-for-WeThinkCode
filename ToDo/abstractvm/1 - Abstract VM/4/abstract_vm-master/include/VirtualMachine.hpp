
#ifndef ABSTRACT_VM_INSTRUCTION_HPP
#define ABSTRACT_VM_INSTRUCTION_HPP

#include <fstream>
#include <regex>
#include <float.h>
#include "Tools.hpp"
#include "IOperand.hpp"

enum Instructions {
	PUSH,
	POP,
	DUMP,
	ASSERT,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PRINT,
	EXIT,
	NONE
};

struct Instruction{
	Instructions    cmd;
	std::string     value;
    eOperandType    type;
	std::string     instruction_line;

	Instruction(Instructions cmd, std::string val, eOperandType type, std::string line) :
			cmd(cmd), value(val), type(type), instruction_line(line){}
};

struct Flags{
	bool    diagnose;
	bool    gui;
	bool    autoplay;
	bool    is_file;
	bool    error;
};

struct  Factory{
public:
	Factory();
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	~Factory();

private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

	std::vector<IOperand const * (Factory::*)(std::string const & value) const> funcs;

};

//read && input functions
void    get_flags(Flags & flag, int ac, char **av);
bool    check_file_exist(int ac, char **av);
void    read_asm(int ac, char **av, Flags & flag);
void    read_stdin(Flags & flags);

//lexer && parser functions
void    my_lexer(std::string & line, Flags & flag, std::vector<Instruction> & cmds);
void    process_push_assert_cmd(std::string & val, eOperandType & d_type, std::string & num);
void	execute_cmds(std::vector<Instruction> & cmds);

//stack operations
void    pushInstruction(Instruction & cmd, std::vector<IOperand const *> & stack);
void    popInstruction(std::vector<IOperand const *> & stack);
void    dumpInstruction(std::vector<IOperand const *> & stack);
void    assertInstruction(Instruction & cmd, std::vector<IOperand const *> & stack);
void    addInstruction(std::vector<IOperand const *> & stack);
void    subInstruction(std::vector<IOperand const *> & stack);
void    mulInstruction(std::vector<IOperand const *> & stack);
void    divInstruction(std::vector<IOperand const *> & stack);
void    modInstruction(std::vector<IOperand const *> & stack);
void    printInstruction(std::vector<IOperand const *> & stack);
void    exitInstruction(std::vector<IOperand const *> & stack);

#endif //ABSTRACT_VM_INSTRUCTION_HPP

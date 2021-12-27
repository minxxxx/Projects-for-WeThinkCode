#include "../include/VirtualMachine.hpp"

int     main(int ac, char **av) {
	//instructions enum
	/*std::cout << "Instruction Enum Test" << std::endl;
	std::cout << "push enum is " << Instructions::PUSH << std::endl;
	std::cout << "add enum is " << Instructions::ADD << std::endl;
	std::cout << "exit enum is " << Instructions::EXIT << std::endl;

	Instruction tmp;

	tmp.type = DataTypes::INT16;
	tmp.instruction_line = "push int16(7)";
	tmp.cmd = Instructions::PUSH;
	tmp.value = "7";
	std::cout << "instruction tmp type : " << tmp.type << std::endl;
	std::cout << "instruction tmp line : " << tmp.instruction_line << std::endl;
	std::cout << "instruction tmp cmd : " << tmp.cmd << std::endl;
	std::cout << "instruction tmp value : " << tmp.value << std::endl;*/

	Flags   flag;

	get_flags(flag, ac, av);
	/*std::cout << "flag autoplay : " << flag.autoplay << std::endl;
	std::cout << "flag diagnose : " << flag.diagnose << std::endl;
	std::cout << "flag gui : " << flag.gui << std::endl;

	std::cout << "read from file : " << check_file_exist(ac, av) << std::endl;*/
	//read_stdin(flag);
	flag.is_file = check_file_exist(ac, av);
	read_asm(ac, av, flag);
	//Factory factory;

	/*Operand<int8_t>* a = (Operand<int8_t> *)factory.createOperand(eOperandType::INT8, std::string("5"));
	Operand<float> * b = (Operand<float> *)factory.createOperand(eOperandType::FLOAT, std::string("5.95"));
	Operand<double> * c = (Operand<double> *)factory.createOperand(eOperandType::DOUBLE, std::string("2300.5678"));
	Operand<int16_t> * d = (Operand<int16_t> *)factory.createOperand(eOperandType::INT16, std::string("0"));*/

	/*IOperand const * a = factory.createOperand(eOperandType::INT32, std::string("5.0"));
	IOperand const * b = factory.createOperand(eOperandType::FLOAT, std::string("5.95"));
	IOperand const * c = factory.createOperand(eOperandType::DOUBLE, std::string("2300.5678"));
	IOperand const * d = factory.createOperand(eOperandType::INT8, std::string("0"));
	IOperand const * e = factory.createOperand(eOperandType::DOUBLE, std::string("50.0"));
	IOperand const * f = factory.createOperand(eOperandType::INT8, std::string("125"));
	IOperand const * g = factory.createOperand(eOperandType::INT8, std::string("5"));

	std::cout << "value in a : " << a->toString() << std::endl;
	std::cout << "value in b : " << b->toString() << std::endl;
	std::cout << "value in c : " << c->toString() << std::endl;
	std::cout << "value in d : " << d->toString() << std::endl;

	try{
		std::cout << "a + b : " << (*a + *b)->toString() << std::endl;
		std::cout << "c - a : " << (*c - *a)->toString() << std::endl;
		std::cout << "a * a : " << (*a * *a)->toString() << std::endl;
		std::cout << "e / a : " << (*e / *a)->toString() << std::endl;
		//std::cout << "e / d : " << (*e / *d)->toString() << std::endl;
		//std::cout << "e % d : " << (*e % *d)->toString() << std::endl;
		std::cout << "f + g : " << (*f + *g)->toString() << std::endl;
	}catch (myexception & e){
		exit(EXIT_FAILURE);
	}*/

	return 0;
}
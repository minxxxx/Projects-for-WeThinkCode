#include "../include/VirtualMachine.hpp"

void    verify_max_min_num(std::string  & str_num, eOperandType & type, std::string & value){
	std::smatch sm;
	long double num;

	if (!std::regex_search(str_num, sm, std::regex("\\([-]?[0-9]+[\\.]?[0-9]*\\)")))
		throw myexception((std::string("Invalid number value in ")+str_num).c_str());
	//std::cout << "out val : " << sm[0] << std::endl;
	if (sm[0].str().size() < 2)
		throw myexception((std::string("Invalid number value in ")+str_num).c_str());
	num = std::stold(sm[0].str().substr(1));
	if (type == eOperandType::INT8 && (num < -128 || num > 127))
		throw myexception((std::string("Exceeds datatype int8: ") + sm[0].str()).c_str());
	if (type == eOperandType::INT16 && (num < -32768 || num > 32767))
		throw myexception((std::string("Exceeds datatype int16: ") + sm[0].str()).c_str());
	if (type == eOperandType::INT32 && (num < -2147483648 || num > 2147483647))
		throw myexception((std::string("Exceeds datatype int32: ") + sm[0].str()).c_str());
	if (type == eOperandType::FLOAT && (num < -FLT_MAX || num > FLT_MAX))
		throw myexception((std::string("Exceeds datatype float: ") + sm[0].str()).c_str());
	if (type == eOperandType::DOUBLE && (num < -DBL_MAX || num > DBL_MAX))
		throw myexception((std::string("Exceeds datatype float: ") + sm[0].str()).c_str());
	value = std::to_string(num);
}

void    process_push_assert_cmd(std::string & val, eOperandType & d_type, std::string & num){
	std::smatch sm;

	if (std::regex_match(val, sm, std::regex("(int8\\([-]?[0-9]+\\))"))){
		//std::cout << "found int8 " << sm[0] << std::endl;
		d_type = eOperandType::INT8;
		verify_max_min_num(val, d_type, num);
		return ;
	}
	if (std::regex_match(val, sm, std::regex("(int16\\([-]?[0-9]+\\))"))){
		//std::cout << "found int16 " << sm[0] << std::endl;
		d_type = eOperandType::INT16;
		verify_max_min_num(val, d_type, num);
		return ;
	}
	if (std::regex_match(val, sm, std::regex("(int32\\([-]?[0-9]+\\))"))){
		//std::cout << "found int32 " << sm[0] << std::endl;
		d_type = eOperandType::INT32;
		verify_max_min_num(val, d_type, num);
		return ;
	}
	if (std::regex_match(val, sm, std::regex("(float\\([-]?[0-9]+[\\.]?[0-9]*\\))"))){
		//std::cout << "found float " << sm[0] << std::endl;
		d_type = eOperandType::FLOAT;
		verify_max_min_num(val, d_type, num);
		return ;
	}
	if (std::regex_match(val, sm, std::regex("double\\([-]?[0-9]+[\\.]?[0-9]*\\))"))){
		//std::cout << "found double " << sm[0] << std::endl;
		d_type = eOperandType::DOUBLE;
		verify_max_min_num(val, d_type, num);
		return ;
	}
	throw myexception((std::string("Invalid number : ")+val).c_str());
}


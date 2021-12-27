
#ifndef ABSTRACT_VM_NEW_OPERAND_HPP
#define ABSTRACT_VM_NEW_OPERAND_HPP

#include "IOperand.hpp"
#include "Tools.hpp"
#include <float.h>
#include <math.h>
#include "VirtualMachine.hpp"

template <typename T>
class Operand : public IOperand{
private:
    int             _precision;
    std::string     _strValue;
    eOperandType    _type;
    T               _value;

	static void    checkOverValue(eOperandType type, long double num){
		if (type == eOperandType::INT8 && (num < -128 || num > 127))
			throw myexception((std::string("Error: Number exceeds datatype INT8 : ") + std::to_string(num)).c_str());
		if (type == eOperandType::INT16 && (num < -32768 || num > 32767))
			throw myexception((std::string("Error: Number exceeds datatype INT16 : ") + std::to_string(num)).c_str());
		if (type == eOperandType::INT32 && (num < -2147483648 || num > 2147483647))
			throw myexception((std::string("Error: Number exceeds datatype INT32 : ") + std::to_string(num)).c_str());
		if (type == eOperandType::FLOAT && (num < -FLT_MAX || num > FLT_MAX))
			throw myexception((std::string("Error: Number exceeds datatype FLOAT : ") + std::to_string(num)).c_str());
		if (type == eOperandType::DOUBLE && (num < -DBL_MAX || num > DBL_MAX))
			throw myexception((std::string("Error: Number exceeds datatype DOUBLE : ") + std::to_string(num)).c_str());
	}

public:
    Operand(int precision, std::string strValue, eOperandType  type, T value) :
            _precision(precision), _strValue(strValue), _type(type), _value(value){}

	int getPrecision( void ) const{
	    return _precision;
    }

	eOperandType getType( void ) const{
	    return _type;
    }

	std::string const & toString( void ) const{
		return _strValue;
	}

	IOperand const * operator+( IOperand const & rhs ) const{
		long double newValue = _value + std::stod(rhs.toString());
		int     newPrecision = (_precision > rhs.getPrecision()) ? _precision : rhs.getPrecision();
		checkOverValue((eOperandType)newPrecision, newValue);
		Factory factory;
		return factory.createOperand((eOperandType)newPrecision, std::to_string(newValue));
	}

    IOperand const * operator-( IOperand const & rhs ) const{
	    long double newValue = _value - std::stod(rhs.toString());
	    int     newPrecision = (_precision > rhs.getPrecision()) ? _precision : rhs.getPrecision();
	    checkOverValue((eOperandType)newPrecision, newValue);
	    Factory factory;
	    return factory.createOperand((eOperandType)newPrecision, std::to_string(newValue));
    }

    IOperand const * operator*( IOperand const & rhs ) const{
	    long double newValue = _value * std::stod(rhs.toString());
	    int     newPrecision = (_precision > rhs.getPrecision()) ? _precision : rhs.getPrecision();
	    checkOverValue((eOperandType)newPrecision, newValue);
	    Factory factory;
	    return factory.createOperand((eOperandType)newPrecision, std::to_string(newValue));
    }

    IOperand const * operator/( IOperand const & rhs ) const{
	    if (std::stod(rhs.toString()) == 0.0f)
		    throw myexception("Error: Cannot divide by a 0");
	    long double newValue = _value / std::stod(rhs.toString());
	    int     newPrecision = (_precision > rhs.getPrecision()) ? _precision : rhs.getPrecision();
	    checkOverValue((eOperandType)newPrecision, newValue);
	    Factory factory;
	    return factory.createOperand((eOperandType)newPrecision, std::to_string(newValue));
    }

    IOperand const * operator%( IOperand const & rhs ) const{
	    if (std::stod(rhs.toString()) == 0.0f)
		    throw myexception("Error: Cannot mod by a 0");
	    long double newValue = fmodl(_value, std::stod(rhs.toString()));
	    int     newPrecision = (_precision > rhs.getPrecision()) ? _precision : rhs.getPrecision();
	    checkOverValue((eOperandType)newPrecision, newValue);
	    Factory factory;
	    return factory.createOperand((eOperandType)newPrecision, std::to_string(newValue));
    }
};

#endif //ABSTRACT_VM_NEW_OPERAND_HPP

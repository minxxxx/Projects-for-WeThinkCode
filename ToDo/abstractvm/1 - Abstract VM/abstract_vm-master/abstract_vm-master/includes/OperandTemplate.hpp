#ifndef OPERANDTEMPLATE_HPP
# define OPERANDTEMPLATE_HPP

# include <to_string.hpp>
# include <IOperand.hpp>
# include <OperandFactory.hpp>
# include <cmath>
# include <RuntimeException.hpp>

template <typename T>
class OperandTemplate : public IOperand{
public:
	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;

	bool operator==( IOperand const & rhs ) const;
	bool operator!=( IOperand const & rhs ) const;


	std::string const & toString( void ) const;

protected:
	std::string	_stringRepresentation;
	T _value;
};

template<typename T>
bool OperandTemplate<T>::operator==( IOperand const & rhs ) const
{
	if (rhs.getType() != this->getType() ||
		rhs.toString() != this->toString())
		return false;
	else
		return true;
}

template<typename T>
bool OperandTemplate<T>::operator!=( IOperand const & rhs ) const
{
	return  !(*this == rhs);
}


template <typename T>
std::string const & OperandTemplate<T>::toString(void) const
{
	return _stringRepresentation;
}

template <typename T>
IOperand const * OperandTemplate<T>::operator+( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());
	double rez;

	rez = _value + std::stod(rhs.toString());

	OperandFactory op;
	return op.createOperand(returnType, to_string(rez));
}

template <typename T>
IOperand const * OperandTemplate<T>::operator-( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());
	double rez;

	rez = _value - std::stod(rhs.toString());

	OperandFactory op;
	return op.createOperand(returnType, to_string(rez));
}

template <typename T>
IOperand const * OperandTemplate<T>::operator*( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());
	double rez;

	rez = _value * std::stod(rhs.toString());

	OperandFactory op;
	return op.createOperand(returnType, to_string(rez));
}

template <typename T>
IOperand const * OperandTemplate<T>::operator/( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());
	double rez;

	if (std::stod(rhs.toString()) == 0)
	{
		throw RuntimeException("Division by zero.");
	}

	rez = _value / std::stod(rhs.toString());

	OperandFactory op;
	return op.createOperand(returnType, to_string(rez));
}

template <typename T>
IOperand const * OperandTemplate<T>::operator%( IOperand const & rhs ) const
{
	eOperandType returnType = std::max(this->getType(), rhs.getType());
	double rez;

	if (std::stod(rhs.toString()) == 0)
	{
		throw RuntimeException("Division by zero.");
	}

	rez = fmod(_value, std::stod(rhs.toString()));

	OperandFactory op;
	return op.createOperand(returnType, to_string(rez));
}

#endif

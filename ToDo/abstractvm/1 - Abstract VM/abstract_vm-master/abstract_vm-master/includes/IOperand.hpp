#ifndef IOPERAND
# define IOPERAND

#include <string>
#include <eOperandType.hpp>

class IOperand {
public:
	virtual int getPrecision( void ) const = 0;
	virtual eOperandType getType( void ) const = 0;

	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; //Sum
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0; //Difference
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0; //Product
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0; //Quotient
	virtual IOperand const * operator%( IOperand const & rhs ) const = 0; //Modulo

	virtual bool operator==( IOperand const & rhs ) const = 0;
	virtual bool operator!=( IOperand const & rhs ) const = 0;

	virtual std::string const & toString( void ) const = 0; // String representation of the instance

	virtual ~IOperand( void ) {}
};

#endif

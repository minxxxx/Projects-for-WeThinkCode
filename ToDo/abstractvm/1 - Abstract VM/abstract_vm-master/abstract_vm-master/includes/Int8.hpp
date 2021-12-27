#ifndef INT8_CLASS_H
# define INT8_CLASS_H

# include <string>
# include <OperandTemplate.hpp>
# include <IOperand.hpp>

class Int8 : public OperandTemplate<int8_t> {
public:
	Int8(int8_t value);
	Int8(Int8 const & src);
	~Int8(void);

	Int8 & operator=(Int8 const & rhs);

	int getPrecision( void ) const;
	eOperandType getType( void ) const;


private:
	Int8(void);
};
#endif

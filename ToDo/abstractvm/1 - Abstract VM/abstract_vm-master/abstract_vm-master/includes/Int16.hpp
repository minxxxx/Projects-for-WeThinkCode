#ifndef INT16_CLASS_H
# define INT16_CLASS_H

# include <string>
# include <OperandTemplate.hpp>
# include <IOperand.hpp>

class Int16 : public OperandTemplate<int16_t> {
public:
	Int16(int16_t value);
	Int16(Int16 const & src);
	~Int16(void);

	Int16 & operator=(Int16 const & rhs);

	int getPrecision( void ) const;
	eOperandType getType( void ) const;


private:
	Int16(void);
};
#endif

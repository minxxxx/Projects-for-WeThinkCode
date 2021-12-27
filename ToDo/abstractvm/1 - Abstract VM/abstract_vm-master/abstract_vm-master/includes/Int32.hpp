#ifndef INT32_CLASS_H
# define INT32_CLASS_H

# include <string>
# include <OperandTemplate.hpp>
# include <IOperand.hpp>

class Int32 : public OperandTemplate<int32_t> {
public:
	Int32(int32_t value);
	Int32(Int32 const & src);
	~Int32(void);

	Int32 & operator=(Int32 const & rhs);

	int getPrecision( void ) const;
	eOperandType getType( void ) const;


private:
	Int32(void);
};
#endif

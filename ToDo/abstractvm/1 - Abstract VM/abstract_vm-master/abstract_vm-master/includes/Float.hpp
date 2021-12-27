#ifndef FLOAT_CLASS_H
# define FLOAT_CLASS_H

# include <string>
# include <OperandTemplate.hpp>
# include <IOperand.hpp>

class Float : public OperandTemplate<float> {
public:
	Float(float value);
	Float(Float const & src);
	~Float(void);

	Float & operator=(Float const & rhs);

	int getPrecision( void ) const;
	eOperandType getType( void ) const;


private:
	Float(void);
};
#endif

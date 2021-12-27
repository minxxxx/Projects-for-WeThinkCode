#ifndef DOUBLE_CLASS_H
# define DOUBLE_CLASS_H

# include <string>
# include <OperandTemplate.hpp>
# include <IOperand.hpp>

class Double : public OperandTemplate<double> {
public:
	Double(double value);
	Double(Double const & src);
	~Double(void);

	Double & operator=(Double const & rhs);

	int getPrecision( void ) const;
	eOperandType getType( void ) const;


private:
	Double(void);
};
#endif

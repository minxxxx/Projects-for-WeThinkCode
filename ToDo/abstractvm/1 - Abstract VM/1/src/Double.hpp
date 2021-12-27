/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:03:51 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 21:43:03 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
# define DOUBLE_HPP

#include "IOperand.class.hpp"
#include "AVMException.hpp"
#include <float.h>

class Double : public IOperand
{
private:
	static const	eOperandType _type;// = PRECISION_DOUBLE;
	double			_vD;
	std::string 	_str;



public:
	static constexpr long double MAX = DBL_MAX;
	static constexpr long double MIN = -DBL_MAX; //DBL_MIN;

	Double();
	Double(double v);
	Double(long double v);
	Double(std::string const& v);
	Double(Double const &);
	~Double();
	Double	&operator=(Double const &);


	eOperandType 		getType( void ) const; // Type of the instance
	int 				getPrecision( void ) const; // Precision of the type of the instance
	IOperand const * 	operator+( IOperand const & rhs ) const; // Sum
	IOperand const * 	operator-( IOperand const & rhs ) const; // Difference
	IOperand const * 	operator*( IOperand const & rhs ) const; // Product
	IOperand const * 	operator/( IOperand const & rhs ) const; // Quotient
	IOperand const * 	operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	std::string 		description( void ) const; // String representation of the instance

	double   		toDouble( void ) const;
	long double    	toLongDouble( void ) const;

	bool		operator==( IOperand const & rhs ) const;
	bool		operator!=( IOperand const & rhs ) const;


	class OverflowException : public AVMException {
	public:
		OverflowException();
		OverflowException(OverflowException const &Ex);
		~OverflowException() throw ();
		OverflowException &operator=(OverflowException const &);
		const char * what(void) const throw ();
	};

	class UnderflowException : public AVMException {
	public:
		UnderflowException();
		UnderflowException(UnderflowException const &);
		~UnderflowException() throw ();
		UnderflowException &operator=(UnderflowException const &);
		const char * what(void) const throw ();
	};
	class DivisionByZeroException : public AVMException {
	public:
		DivisionByZeroException();
		DivisionByZeroException(DivisionByZeroException const &);
		~DivisionByZeroException() throw ();
		DivisionByZeroException &operator=(DivisionByZeroException const &);
		const char * what(void) const throw ();
	};
};

std::ostream	&operator<<(std::ostream &out, Double const *f);
std::ostream	&operator<<(std::ostream &out, Double const &f);

#endif

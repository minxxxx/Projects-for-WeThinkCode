/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:03:51 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 21:43:03 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
# define FLOAT_HPP

#include "IOperand.class.hpp"
#include "AVMException.hpp"
#include <float.h>

class Float : public IOperand
{
private:
	static const	eOperandType _type;// = PRECISION_FLOAT;
	float			_vF;
	std::string 	_str;


public:
	static constexpr long double MAX = FLT_MAX;
	static constexpr long double MIN = -FLT_MAX;//FLT_MIN;

	Float();
	Float(float v);
	Float(long double v);
	Float(std::string const& v);
	Float(Float const &);
	~Float();
	Float	&operator=(Float const &);


	eOperandType 		getType( void ) const; // Type of the instance
	int 				getPrecision( void ) const; // Precision of the type of the instance
	IOperand const * 	operator+( IOperand const & rhs ) const; // Sum
	IOperand const * 	operator-( IOperand const & rhs ) const; // Difference
	IOperand const * 	operator*( IOperand const & rhs ) const; // Product
	IOperand const * 	operator/( IOperand const & rhs ) const; // Quotient
	IOperand const * 	operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	std::string 		description( void ) const; // String representation of the instance

	float   		toFloat( void ) const;
	long double    	toLongDouble( void ) const;

	bool		operator==( IOperand const & rhs ) const;
	bool		operator!=( IOperand const & rhs ) const;

	class OverflowException : public AVMException  {
	public:
		OverflowException();
		OverflowException(OverflowException const &Ex);
		~OverflowException() throw ();
		OverflowException &operator=(OverflowException const &);
		const char * what(void) const throw ();
	};

	class UnderflowException : public AVMException  {
	public:
		UnderflowException();
		UnderflowException(UnderflowException const &);
		~UnderflowException() throw ();
		UnderflowException &operator=(UnderflowException const &);
		const char * what(void) const throw ();
	};

	class BadOperationException : public AVMException  {
	public:
		BadOperationException();
		BadOperationException(BadOperationException const &Ex);
		~BadOperationException() throw ();
		BadOperationException &operator=(BadOperationException const &);
		const char * what(void) const throw ();
	};
	class DivisionByZeroException : public AVMException  {
	public:
		DivisionByZeroException();
		DivisionByZeroException(DivisionByZeroException const &);
		~DivisionByZeroException() throw ();
		DivisionByZeroException &operator=(DivisionByZeroException const &);
		const char * what(void) const throw ();
	};
};

std::ostream	&operator<<(std::ostream &out, Float const *f);

#endif

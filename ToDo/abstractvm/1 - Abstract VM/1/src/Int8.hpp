/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:03:51 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 21:43:03 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

#include "IOperand.class.hpp"
#include "AVMException.hpp"
#include <limits.h>

class Int8 : public IOperand
{
private:
	static const	eOperandType _type;// = PRECISION_INT8;
	char			_v8;
	std::string 	_str;

public:
	static const long int MAX = CHAR_MAX;//127;
	static const long int MIN = CHAR_MIN;//-128;

	Int8();
	Int8(char v);
	Int8(long long int v);
	Int8(std::string const& v);
	Int8(Int8 const &);
	~Int8();
	Int8	&operator=(Int8 const &);


	eOperandType 		getType( void ) const; // Type of the instance
	int 				getPrecision( void ) const; // Precision of the type of the instance
	IOperand const * 	operator+( IOperand const & rhs ) const; // Sum
	IOperand const * 	operator-( IOperand const & rhs ) const; // Difference
	IOperand const * 	operator*( IOperand const & rhs ) const; // Product
	IOperand const * 	operator/( IOperand const & rhs ) const; // Quotient
	IOperand const * 	operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	std::string 		description( void ) const; // String representation of the instance

	bool 				operator==( IOperand const & rhs ) const;
	bool 				operator!=( IOperand const & rhs ) const;

	char    	 	toChar( void ) const;
	long int     	toLongInt( void ) const;
	long double    	toLongDouble( void ) const;

	class OverflowException  : public AVMException {
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
	class DivisionByZeroException : public AVMException  {
	public:
		DivisionByZeroException();
		DivisionByZeroException(DivisionByZeroException const &);
		~DivisionByZeroException() throw ();
		DivisionByZeroException &operator=(DivisionByZeroException const &);
		const char * what(void) const throw ();
	};
	

};

std::ostream	&operator<<(std::ostream &out, Int8 const &f);

#endif

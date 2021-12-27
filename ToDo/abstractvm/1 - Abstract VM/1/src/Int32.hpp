/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:03:51 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 21:43:03 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
# define INT32_HPP

#include "IOperand.class.hpp"
#include "AVMException.hpp"
#include <limits.h>

class Int32 : public IOperand
{
private:
	static const	eOperandType _type;// = PRECISION_INT32;
	long int		_v32;
	std::string 	_str;

public:
	static const long long int MAX = LONG_MAX;//0x7fffffff;
	static const long long int MIN = LONG_MIN;//-0x80000000;

	Int32();
	Int32(short int v);
	Int32(long long int v);
	Int32(std::string const& v);
	Int32(Int32 const &);
	~Int32();
	Int32	&operator=(Int32 const &);


	eOperandType 		getType( void ) const; // Type of the instance
	int 				getPrecision( void ) const; // Precision of the type of the instance
	IOperand const * 	operator+( IOperand const & rhs ) const; // Sum
	IOperand const * 	operator-( IOperand const & rhs ) const; // Difference
	IOperand const * 	operator*( IOperand const & rhs ) const; // Product
	IOperand const * 	operator/( IOperand const & rhs ) const; // Quotient
	IOperand const * 	operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	std::string 		description( void ) const; // String representation of the instance
	
	long int    	toLongInt( void ) const;
	long long int   toLongLongInt( void ) const;
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
	class DivisionByZeroException : public AVMException  {
	public:
		DivisionByZeroException();
		DivisionByZeroException(DivisionByZeroException const &);
		~DivisionByZeroException() throw ();
		DivisionByZeroException &operator=(DivisionByZeroException const &);
		const char * what(void) const throw ();
	};
};

std::ostream	&operator<<(std::ostream &out, Int32 const *f);

#endif

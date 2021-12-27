/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:15:12 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/23 15:44:02 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND__CLASS_HPP
# define IOPERAND__CLASS_HPP

#include <string>
#include <vector>
#include <iostream>

typedef enum eOperandType {
	PRECISION_INT8, PRECISION_INT16, PRECISION_INT32,
	PRECISION_FLOAT, PRECISION_DOUBLE
} t_precision;

class IOperand {
public:
	virtual eOperandType 		getType( void ) const = 0; // Type of the instance
	virtual int 				getPrecision( void ) const = 0; // Precision of the type of the instance
	virtual IOperand const		* operator+( IOperand const & rhs ) const = 0; // Sum
	virtual IOperand const		* operator-( IOperand const & rhs ) const = 0; // Difference
	virtual IOperand const		* operator*( IOperand const & rhs ) const = 0; // Product
	virtual IOperand const 		* operator/( IOperand const & rhs ) const = 0; // Quotient
	virtual IOperand const 		* operator%( IOperand const & rhs ) const = 0; // Modulo
	//virtual IOperand const 		* getmax( IOperand const &op1, IOperand const &op2) const = 0; // Modulo
	virtual std::string const 	& toString( void ) const = 0; // String representation of the instance

	virtual ~IOperand( void ) {}


	virtual bool 				operator==( IOperand const & rhs ) const = 0; // equality
	virtual bool 				operator!=( IOperand const & rhs ) const = 0; // inequality
	virtual bool 				operator>( IOperand const & rhs ) const = 0; // greater than
	virtual bool 				operator>=( IOperand const & rhs ) const = 0; // greater than or equal
	virtual bool 				operator<( IOperand const & rhs ) const = 0; // less than
	virtual bool 				operator<=( IOperand const & rhs ) const = 0; // less than or equal

	//add by our
//	virtual IOperand const 		* squareroot( IOperand const & rhs ) const = 0; // Modulo
//	virtual std::string 		description( void ) const = 0;
//	virtual long double     	toLongDouble( void ) const = 0;

/*	class OverflowException : public std::exception
	{
	public:
		virtual ~OverflowException() throw ();
		virtual const char * what(void) const throw() = 0;	//{ return "Overflow : Number Too High"; }
	};

	class UnderflowException : public std::exception
	{
	public:
		virtual ~UnderflowException() throw ();
		virtual const char * what(void) const throw () = 0; //{	return "Underflow : Number Too Low"; }
	};

	class DivisionByZeroException : public std::exception
	{
	public:
		virtual ~DivisionByZeroException() throw ();
		virtual const char * what(void) const throw () = 0; //{ return "Error : division by zero "; }
	};
*/
};

#endif

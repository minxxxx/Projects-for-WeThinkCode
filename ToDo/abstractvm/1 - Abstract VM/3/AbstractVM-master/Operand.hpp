/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13/38/57 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/16 07:11:00 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		OPERAND_HPP
# define	OPERAND_HPP

# include "IOperand.hpp"
# include "Parse.hpp"

template<typename T>
class Operand : public IOperand {
	public:
		Operand( void );
		Operand(std::string val, eOperandType type); 
		Operand( Operand const & src );
		virtual ~Operand( void ); 
		std::string			_val;
		eOperandType		_type;
		virtual eOperandType getType( void ) const;
		virtual int getPrecision( void ) const;
		virtual std::string const & toString( void ) const;
		virtual IOperand const * operator+( IOperand const & rhs ) const; 
		virtual IOperand const * operator-( IOperand const & rhs ) const; 
		virtual IOperand const * operator*( IOperand const & rhs ) const; 
		virtual IOperand const * operator/( IOperand const & rhs ) const; 
		virtual IOperand const * operator%( IOperand const & rhs ) const; 
		IOperand const & operator=( IOperand const & rhs); 
};

#include "Operand.cpp"

#endif

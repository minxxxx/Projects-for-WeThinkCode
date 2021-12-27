/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:54:32 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/22 17:34:03 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_CLASS_HPP
# define OPERANDFACTORY_CLASS_HPP

#include "IOperand.class.hpp"
//#include "Operand.template.hpp"


class OperandFactory   
{
private :
		OperandFactory();
		OperandFactory(OperandFactory const &);
		OperandFactory	&operator=(OperandFactory const &);
		
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

	typedef IOperand const * (OperandFactory::* CreatFunc) (std::string const & ) const;
	
		CreatFunc createFuncs[5];


public:
    ~OperandFactory();

    static OperandFactory &get(void)
    {
        static OperandFactory instance;
        return instance;
    }

    //void Register(const std::string &val, createOperandFn pfnCreate);
    IOperand const *createOperand( eOperandType type, std::string const & value) const;
};

std::ostream	&operator<<(std::ostream &out, IOperand const &f);
std::ostream	&operator<<(std::ostream &out, IOperand const *f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10/31/41 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/16 07:10:00 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FACTORY_HPP
# define	FACTORY_HPP

#include "IOperand.hpp"

// Factory method
class Factory {
	public:
		Factory( void );
		Factory & operator=(Factory const & src);
		~Factory( void );

		IOperand const * createInt8(std::string const & value) const;
		IOperand const * createInt16(std::string const & value) const;
		IOperand const * createInt32(std::string const & value) const;
		IOperand const * createFloat(std::string const & value) const;
		IOperand const * createDouble(std::string const & value) const;
		IOperand const * createOperand(eOperandType type, std::string const & value) const;
		
		typedef IOperand const * (Factory::*pt2Function)(std::string const &) const;
};

#endif

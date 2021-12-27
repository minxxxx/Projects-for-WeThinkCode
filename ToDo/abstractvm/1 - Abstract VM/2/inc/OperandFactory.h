/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 09:14:59 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/25 08:10:02 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_H
# define OPERANDFACTORY_H

# include <IOperand.h>

class OperandFactory
{
public:
    OperandFactory(void);
    virtual ~OperandFactory(void);
    IOperand const * createOperand(eOperandType type, const std::string &value) const;
    
private:
    /* INTERNAL VARS */
    std::map<eOperandType, IOperand const *(OperandFactory::*)(const std::string &) const> mm_func;

    /* FUNCTIONS */
    IOperand const * createInt8(const std::string &value) const;
    IOperand const * createInt16(const std::string &value) const;
    IOperand const * createInt32(const std::string &value) const;
    IOperand const * createFloat(const std::string &value) const;
    IOperand const * createDouble(const std::string &value) const;

    /* COPLIEN... */
    OperandFactory(OperandFactory &src) = delete;
    OperandFactory(OperandFactory const &src) = delete;
    OperandFactory &operator=(OperandFactory &&rhs) = delete;
    OperandFactory &operator=(OperandFactory const &rhs) = delete;
};

#endif

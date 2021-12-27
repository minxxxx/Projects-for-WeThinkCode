/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:03:52 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/31 15:47:57 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
# define OPERAND_H

#include <OperandFactory.h>

template <typename T>
class Operand : public IOperand
{
public:

    Operand(std::string const &value, eOperandType type, int precision)
    : mc_value( type == Int32 ? stol(value) : type == Float ? stof(value) : type == Double ? stod(value) : stoi(value) )
    , mz_origValue( (mc_value) ? value : "0")
    , mc_type(type)
    , m4_precision(precision)
    {
        std::stringstream lc_ss(std::stringstream::out);
        if (ISDECIMAL(mc_type))
            lc_ss << std::setprecision(TYPE2PRECISION(mc_type)) << std::stold(mz_origValue);
        else
            lc_ss << std::stoll(mz_origValue);
        mz_value = lc_ss.str();
    }

    virtual ~Operand(void) { }

    /*
    ** Return the precision
    */
    int getPrecision(void) const { return (m4_precision); }

    /*
    ** Return the type
    */
    eOperandType getType(void) const { return (mc_type); }

    /*
    ** Operator +, add instance + another instance and return fresh instance
    */
    IOperand const *operator+(IOperand const &rhs) const
    {
        // define the biggest eOperandType
        eOperandType lc_curType = ( (mc_type > rhs.getType()) ? mc_type : rhs.getType() );

        // ss used for convertion
        std::stringstream lc_ss(std::stringstream::out);

        // build the stringstream (if decimal, build as Double + set precision else build as Int32)
        if (ISDECIMAL(lc_curType))
            lc_ss << std::setprecision(TYPE2PRECISION(lc_curType)) << std::stold(mz_value) + std::stold(rhs.toString());
        else
            lc_ss << std::stoll(mz_value) + std::stoll(rhs.toString());

        // return a fresh new instance
        return (mc_operandFactory.createOperand(lc_curType, lc_ss.str()));
    }

    IOperand const *operator-(IOperand const &rhs) const
    {
        // define the biggest eOperandType
        eOperandType lc_curType = ( (mc_type > rhs.getType()) ? mc_type : rhs.getType() );

        // ss used for convertion
        std::stringstream lc_ss(std::stringstream::out);

        // build the stringstream (if decimal, build as Double + set precision else build as Int32)
        if (ISDECIMAL(lc_curType))
            lc_ss << std::setprecision(TYPE2PRECISION(lc_curType)) << std::stold(mz_value) - std::stold(rhs.toString());
        else
            lc_ss << std::stoll(mz_value) - std::stoll(rhs.toString());

        // return a fresh new instance
        return (mc_operandFactory.createOperand(lc_curType, lc_ss.str()));
    }

    IOperand const *operator*(IOperand const &rhs) const
    {
        // define the biggest eOperandType
        eOperandType lc_curType = ( (mc_type > rhs.getType()) ? mc_type : rhs.getType() );

        // ss used for convertion
        std::stringstream lc_ss(std::stringstream::out);

        // build the stringstream (if decimal, build as Double + set precision else build as Int32)
        if (ISDECIMAL(lc_curType))
            lc_ss << std::setprecision(TYPE2PRECISION(lc_curType)) << std::stold(mz_value) * std::stold(rhs.toString());
        else
            lc_ss << std::stoll(mz_value) * std::stoll(rhs.toString());

        // return a fresh new instance
        return (mc_operandFactory.createOperand(lc_curType, lc_ss.str()));
    }

    IOperand const *operator/(IOperand const &rhs) const
    {
        // define the biggest eOperandType
        eOperandType lc_curType = ( (mc_type > rhs.getType()) ? mc_type : rhs.getType() );

        // ss used for convertion
        std::stringstream lc_ss(std::stringstream::out);

        // build the stringstream (if decimal, build as Double + set precision else build as Int32)
        if (ISDECIMAL(lc_curType))
            lc_ss << std::setprecision(TYPE2PRECISION(lc_curType)) << std::stold(mz_value) / std::stold(rhs.toString());
        else
            lc_ss << std::stoll(mz_value) / std::stoll(rhs.toString());

        // return a fresh new instance
        return (mc_operandFactory.createOperand(lc_curType, lc_ss.str()));
    }

    IOperand const *operator%(IOperand const &rhs) const
    {
        // define the biggest eOperandType
        eOperandType lc_curType = ( (mc_type > rhs.getType()) ? mc_type : rhs.getType() );

        // ss used for convertion
        std::stringstream lc_ss(std::stringstream::out);

        // build the stringstream (if decimal, build as Double + set precision else build as Int32)
        if (ISDECIMAL(lc_curType))
            lc_ss << std::setprecision(TYPE2PRECISION(lc_curType)) << fmod(std::stold(mz_value), std::stold(rhs.toString()));
        else
            lc_ss << std::stoll(mz_value) % std::stoll(rhs.toString());

        // return a fresh new instance
        return (mc_operandFactory.createOperand(lc_curType, lc_ss.str()));
    }

    std::string const &toString(void) const { return (mz_value); }

private:

    const T                 mc_value;
    const std::string       mz_origValue;
    std::string             mz_value;
    const eOperandType      mc_type;
    const byte4             m4_precision;
    const OperandFactory    mc_operandFactory;

    /* COPLIEN..... */
    Operand(void);
    Operand(Operand &src) = delete;
    Operand(Operand const &src) = delete;
    Operand &operator=(Operand &&rhs) = delete;
    Operand &operator=(Operand const &rhs) = delete;
};

#endif

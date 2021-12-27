/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 09:14:59 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/31 13:31:57 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_H
# define IOPERAND_H

# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <cstdlib>
# include <regex>
# include <algorithm>
# include <cmath>
# include <AvmException.h>
typedef int byte4;
typedef size_t byte8;
# define ENABLE_DBG false
# define DBG_FUNC(x) if (ENABLE_DBG) { std::cout << "[DBG] " << x << std::endl; }
# define SET_RED_COLOR "\033[31m"
# define SET_DEF_COLOR "\033[39m"
# define RGX_OP "^\\s*(\\S+)\\s*(\\S+)?\\s*$"
# define RGX_VAL "^(\\S+)\\((\\S+)\\)$"
# define STR2EOPERAND(x) (x == "int8" ? Int8 : x == "int16" ? Int16 : x == "int32" ? Int32 : x == "float" ? Float : Double)
# define TYPE2PRECISION(x) (x == Float ? 7 : x == Double ? 14 : 0)
# define ISDECIMAL(x) ( (x < Float) ? false : true )

enum eOperandType
{
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

class IOperand
{
public:
	virtual int getPrecision(void) const = 0; // Precision of the type of the instance
	virtual eOperandType getType(void) const = 0; // Type of the instance
	virtual IOperand const *operator+(IOperand const &rhs) const = 0; //Sum
	virtual IOperand const *operator-(IOperand const &rhs) const = 0; //Difference
	virtual IOperand const *operator*(IOperand const &rhs) const = 0; //Product
	virtual IOperand const *operator/(IOperand const &rhs) const = 0; //Quotient
	virtual IOperand const *operator%(IOperand const &rhs) const = 0; //Moudlo
	virtual std::string const & toString(void) const = 0; // String representation of the instance
	virtual ~IOperand(void) {}
};

#endif

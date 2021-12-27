/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cxx                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:03:52 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/26 00:43:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <Operand.h>

/*
** Constructor
*/
OperandFactory::OperandFactory()
{
    mm_func.clear();
    mm_func[Int8] = &OperandFactory::createInt8;
    mm_func[Int16] = &OperandFactory::createInt16;
    mm_func[Int32] = &OperandFactory::createInt32;
    mm_func[Float] = &OperandFactory::createFloat;
    mm_func[Double] = &OperandFactory::createDouble;
}

/*
** Destructor
*/
OperandFactory::~OperandFactory() { }

/*
** OperandCreator
*/
IOperand const * OperandFactory::createOperand(eOperandType type, const std::string &value) const { return ((this->*mm_func.at(type))(value)); }

/*
** Create an int8 (char)
*/
IOperand const * OperandFactory::createInt8(const std::string &value) const { return (new Operand<char>(value, Int8, 0)); }

/*
** Create an int16 (short int)
*/
IOperand const * OperandFactory::createInt16(const std::string &value) const { return (new Operand<short int>(value, Int16, 0)); }

/*
** Create an int32 (int)
*/
IOperand const * OperandFactory::createInt32(const std::string &value) const { return (new Operand<int>(value, Int32, 0)); }

/*
** Create a float
*/
IOperand const * OperandFactory::createFloat(const std::string &value) const { return (new Operand<float>(value, Float, 7)); }

/*
** Create a double
*/
IOperand const * OperandFactory::createDouble(const std::string &value) const { return (new Operand<double>(value, Double, 14)); }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.cxx                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:11:02 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/31 14:53:44 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Avm.h>

/*
** Process operation on stack, push case
*/
void         AVM::operation_push(void)
{
    DBG_FUNC("AVM::operation_push");

    try
    {
        // push back a new operand
        mv_ioStack.push_back(mc_operandFactory.createOperand(STR2EOPERAND(mz_rgx_typ), mz_rgx_val));
    }
    catch (std::invalid_argument const &e)
    {
        throw AVMException("invalid_argument");
    }
    catch (std::out_of_range const &e)
    {
        throw AVMException("underflow/overflow");
    }
}

/*
** Process operation on stack, pop case
*/
void         AVM::operation_pop(void)
{
    DBG_FUNC("AVM::operation_pop");

    // real delete on elem
    delete mv_ioStack.back();
    
    // delete it from stack
    mv_ioStack.pop_back();
}

/*
** Process operation on stack, dump case
*/
void         AVM::operation_dump(void)
{
    DBG_FUNC("AVM::operation_dump");

    // check size
    if (!mv_ioStack.size())
        return ;

    // for each elem, print the toString()
    for (std::vector<IOperand const*>::iterator it = mv_ioStack.end();;)
    {
        std::cout << (*--it)->toString() << std::endl;
        if (it == mv_ioStack.begin())
            break;
    }
}

/*
** Process operation on stack, assert case
*/
void         AVM::operation_assert(void)
{
    DBG_FUNC("AVM::operation_assert");

    // define the biggest eOperandType
    eOperandType lc_curType = ( (mv_ioStack.back()->getType() > STR2EOPERAND(mz_rgx_typ)) ? mv_ioStack.back()->getType() : STR2EOPERAND(mz_rgx_typ) );

    // compare
    if ((ISDECIMAL(lc_curType) && std::stold(mv_ioStack.back()->toString()) == std::stold(mz_rgx_val))
    || (!ISDECIMAL(lc_curType) && std::stoll(mv_ioStack.back()->toString()) == std::stoll(mz_rgx_val)))
        return ;
    else
        throw AVMException("values are differents");
}

/*
** Process operation on stack, add case
*/
void         AVM::operation_add(void)
{
    DBG_FUNC("AVM::operation_add");

    IOperand const *lc_first, *lc_second;

    // get 1st elem + pop it from stack
    lc_first = mv_ioStack.back();
    mv_ioStack.pop_back();

    // get 2nd elem + pop it from stack
    lc_second = mv_ioStack.back();
    mv_ioStack.pop_back();

    try
    {
        // push back the new elem
        mv_ioStack.push_back( (*lc_second) + (*lc_first) );
    }
    catch (std::invalid_argument const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("invalid_argument");
    }
    catch (std::out_of_range const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("underflow/overflow");
    }

    // delete the 2 old elem
    delete lc_first;
    delete lc_second;
}

/*
** Process operation on stack, sub case
*/
void         AVM::operation_sub(void)
{
    DBG_FUNC("AVM::operation_sub");

    IOperand const *lc_first, *lc_second;

    // get 1st elem + pop it from stack
    lc_first = mv_ioStack.back();
    mv_ioStack.pop_back();

    // get 2nd elem + pop it from stack
    lc_second = mv_ioStack.back();
    mv_ioStack.pop_back();

    try
    {
        // push back the new elem
        mv_ioStack.push_back( (*lc_second) - (*lc_first) );
    }
    catch (std::invalid_argument const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("invalid_argument");
    }
    catch (std::out_of_range const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("underflow/overflow");
    }

    // delete the 2 old elem
    delete lc_first;
    delete lc_second;
}

/*
** Process operation on stack, mul case
*/
void         AVM::operation_mul(void)
{
    DBG_FUNC("AVM::operation_mul");

    IOperand const *lc_first, *lc_second;

    // get 1st elem + pop it from stack
    lc_first = mv_ioStack.back();
    mv_ioStack.pop_back();

    // get 2nd elem + pop it from stack
    lc_second = mv_ioStack.back();
    mv_ioStack.pop_back();

    try
    {
        // push back the new elem
        mv_ioStack.push_back( (*lc_second) * (*lc_first) );
    }
    catch (std::invalid_argument const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("invalid_argument");
    }
    catch (std::out_of_range const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("underflow/overflow");
    }

    // delete the 2 old elem
    delete lc_first;
    delete lc_second;
}

/*
** Process operation on stack, div case
*/
void         AVM::operation_div(void)
{
    DBG_FUNC("AVM::operation_div");

    IOperand const *lc_first, *lc_second;

    // get 1st elem + pop it from stack
    lc_first = mv_ioStack.back();
    mv_ioStack.pop_back();

    // get 2nd elem + pop it from stack
    lc_second = mv_ioStack.back();
    mv_ioStack.pop_back();

    try
    {
        // check if div by 0
        if (lc_first->toString() == "0")
            throw AVMException("div by 0");

        // push back the new elem
        mv_ioStack.push_back( (*lc_second) / (*lc_first) );
    }
    catch (std::invalid_argument const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("invalid_argument");
    }
    catch (std::out_of_range const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("underflow/overflow");
    }
    catch (AVMException const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException(e.what());
    }

    // delete the 2 old elem
    delete lc_first;
    delete lc_second;
}

/*
** Process operation on stack, mod case
*/
void         AVM::operation_mod(void)
{
    DBG_FUNC("AVM::operation_mod");

    IOperand const *lc_first, *lc_second;

    // get 1st elem + pop it from stack
    lc_first = mv_ioStack.back();
    mv_ioStack.pop_back();

    // get 2nd elem + pop it from stack
    lc_second = mv_ioStack.back();
    mv_ioStack.pop_back();

    try
    {
        // check if div by 0
        if (lc_first->toString() == "0")
            throw AVMException("mod by 0");

        // push back the new elem
        mv_ioStack.push_back( (*lc_second) % (*lc_first) );
    }
    catch (std::invalid_argument const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("invalid_argument");
    }
    catch (std::out_of_range const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException("underflow/overflow");
    }
    catch (AVMException const &e)
    {
        mv_ioStack.push_back(lc_second);
        mv_ioStack.push_back(lc_first);
        throw AVMException(e.what());
    }

    // delete the 2 old elem
    delete lc_first;
    delete lc_second;
}

/*
** Process operation on stack, print case
*/
void         AVM::operation_print(void)
{
    DBG_FUNC("AVM::operation_print");

    if (mv_ioStack.back()->getType() != Int8)
        throw AVMException("top stack value must be a 8-bit integer");

    std::cout << (char)stoi(mv_ioStack.back()->toString()) << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Avm.cxx                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:03:52 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/31 15:59:22 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Avm.h>

/*
** Constructor with stdin read
*/
AVM::AVM(void)
: mb_readFromStdin(true)
, mb_exitAsked(false)
, mc_rgx_op(RGX_OP)
, mc_rgx_val(RGX_VAL)
, m8_nbLinesRead(0)
{
    DBG_FUNC("AVM::AVM");

    start();
}

/*
** Constructor with regular file read
*/
AVM::AVM(const char *pz_filename)
: mb_readFromStdin(false)
, mz_file(pz_filename)
, mb_exitAsked(false)
, mc_rgx_op(RGX_OP)
, mc_rgx_val(RGX_VAL)
, m8_nbLinesRead(0)
{
    DBG_FUNC("AVM::AVM");

    if (!mz_file.is_open())
    {
        std::cerr << "error: cannot open file" << std::endl;
        exit(1);
    }
    
    start();
}

/*
** Destructor
*/
AVM::~AVM(void)
{
    DBG_FUNC("AVM::~AVM");

    while (mv_ioStack.size())
        operation_pop();
}

/*
** Launch the avm
*/
void	AVM::start(void)
{
    DBG_FUNC("AVM::start");

    clearLine();
    while (getLine())
    {
        prepareLine();
        if (isLineValid())
            addLineToAvm();
        clearLine();
    }
}

/*
** Clear the line
*/
void        AVM::clearLine(void)
{
    DBG_FUNC("AVM::clearLine");

    mz_line.clear();
    mz_rgx_op.clear();
    mz_rgx_typ.clear();
    mz_rgx_val.clear();
}

/*
** Read a new line from good stream
*/
bool        AVM::getLine(void)
{
    DBG_FUNC("AVM::getLine");

    if (mb_readFromStdin)
    {
        if (mb_exitAsked || !std::getline(std::cin, mz_line))
            return (false);
    }
    else
    {
        if (!std::getline(mz_file, mz_line))
        {
            if (mb_exitAsked)
                return (false);
            return (printErrorAndRetFalse("missing exit command"));
        }
    }

    if (mb_exitAsked)
        return (printErrorAndRetFalse("exit command not at EOF"));

    ++m8_nbLinesRead;

    return (true);
}

/*
** Prepare the fresh line to be parsed (clean it)
*/
void      AVM::prepareLine(void)
{
    DBG_FUNC("AVM::prepareLine");

    byte8   l8_pos;
    
    // simple/double comma handler
    if ((l8_pos = mz_line.find(';')) != std::string::npos && (l8_pos + 1 == mz_line.length() || mz_line[l8_pos+1] != ';'))
        mz_line.erase(l8_pos);
    else if ((l8_pos = mz_line.find(";;")) != std::string::npos)
        mz_line.erase(l8_pos+2);

    // we do tolower on string
    std::transform(mz_line.begin(), mz_line.end(), mz_line.begin(), ::tolower);
}

/*
** print the error and return false
*/
bool        AVM::printErrorAndRetFalse(const std::string &pz_msg)
{
    DBG_FUNC("AVM::printErrorAndRetFalse");

    std::cerr << SET_RED_COLOR;

    if (mb_readFromStdin)
        std::cerr << "error";
    else
        std::cerr << "error line " << m8_nbLinesRead;

    std::cerr << ": " << pz_msg << std::endl << SET_DEF_COLOR;

    return (false);
}

/*
** Parse the line to check if is valid or not
*/
bool        AVM::isLineValid(void)
{
    DBG_FUNC("AVM::isLineValid");

    // ignore empty lines
    if (!mz_line.size() || mz_line.find_first_not_of(" \t") == std::string::npos)
        return (false);

    // we apply first regex
    std::smatch lc_smatch;
    if (!std::regex_search(mz_line, lc_smatch, mc_rgx_op) || !lc_smatch.size() || !lc_smatch.str(1).size())
        return (printErrorAndRetFalse("syntax error"));
    mz_rgx_op = lc_smatch.str(1);
    mz_rgx_typ = lc_smatch.str(2);

    // if second group found, we apply second regex on it
    if (mz_rgx_typ.size())
    {
       if (!std::regex_search(mz_rgx_typ, lc_smatch, mc_rgx_val) || !lc_smatch.size())
            return (printErrorAndRetFalse("syntax error"));
        mz_rgx_val = lc_smatch.str(2);
        mz_rgx_typ = lc_smatch.str(1);
    }

    // we check the op validity
    if (mz_rgx_op == "push" || mz_rgx_op == "assert")
    {
        // check if called without value
        if (!mz_rgx_typ.size() || !mz_rgx_val.size())
            return (printErrorAndRetFalse("the operator '" + mz_rgx_op + "' must be called with a value"));

        // check the type availability
        if (mz_rgx_typ != "int8" && mz_rgx_typ != "int16" && mz_rgx_typ != "int32" && mz_rgx_typ != "float" && mz_rgx_typ != "double")
            return (printErrorAndRetFalse("unknown type '" + mz_rgx_typ + "'"));

        // check composition
        if (mz_rgx_typ == "int8" || mz_rgx_typ == "int16" || mz_rgx_typ == "int32")
        {
            // check if contains only numeric
            if (mz_rgx_val.find_first_not_of("+-0123456789") != std::string::npos)
                return (printErrorAndRetFalse("value '" + mz_rgx_val + "' is not valid for type " + mz_rgx_typ));
        }
        else
        {
            // check if only numeric + one '.'
            if (mz_rgx_val.find_first_not_of("+-0123456789.") != std::string::npos || mz_rgx_val.find_first_of('.') != mz_rgx_val.find_last_of('.'))
                return (printErrorAndRetFalse("value '" + mz_rgx_val + "' is not valid for type " + mz_rgx_typ));
        }

        // check sign nb
        if (mz_rgx_val.find_first_of('+') != mz_rgx_val.find_last_of('+') || mz_rgx_val.find_first_of('-') != mz_rgx_val.find_last_of('-'))
            return (printErrorAndRetFalse("value '" + mz_rgx_val + "' is not valid for type " + mz_rgx_typ));

        // check sign position
        if ((mz_rgx_val.find('+') != std::string::npos && mz_rgx_val.find('+')) || (mz_rgx_val.find('-') != std::string::npos && mz_rgx_val.find('-')))
            return (printErrorAndRetFalse("value '" + mz_rgx_val + "' is not valid for type " + mz_rgx_typ));

    }
    else if (mz_rgx_op == "pop" || mz_rgx_op == "dump" || mz_rgx_op == "add" || mz_rgx_op == "sub" || mz_rgx_op == "mul" || mz_rgx_op == "div" || mz_rgx_op == "mod" || mz_rgx_op == "print" || mz_rgx_op == "exit" || mz_rgx_op == ";;")
    {
        if (mz_rgx_typ.size() || mz_rgx_val.size())
            return (printErrorAndRetFalse("the operator '" + mz_rgx_op + "' cannot be called with a value"));
    }
    else
        return (printErrorAndRetFalse("unknown operator '" + mz_rgx_op + "'"));

    return (true);
}

/*
** Try to add the line to the avm
*/
void         AVM::addLineToAvm(void)
{
    DBG_FUNC("AVM::addLineToAvm");
    DBG_FUNC("l" + std::to_string((int)m8_nbLinesRead) + ": op=" + mz_rgx_op + ((mz_rgx_val.size()) ? (" typ=" + mz_rgx_typ + " val=" + mz_rgx_val) : ""))

    // if exit asked, set the boolean and do nothind more
    if (mz_rgx_op == "exit" || mz_rgx_op == ";;")
    {
        mb_exitAsked = true;
        return ;
    }

    // check stack size
    if ((mv_ioStack.size() < 2 && (mz_rgx_op == "add" || mz_rgx_op == "sub" || mz_rgx_op == "mul" || mz_rgx_op == "div" || mz_rgx_op == "mod"))
    || ((mv_ioStack.size() < 1) && (mz_rgx_op == "pop" || mz_rgx_op == "assert" || mz_rgx_op == "print")))
        return ((void)printErrorAndRetFalse("not enought elements in stack to '" + mz_rgx_op + "' "));

    try
    {
        processOperation();
    }
    catch (AVMException const &e)
    {
        printErrorAndRetFalse(e.what());
    }
    catch (std::exception const &e)
    {
        printErrorAndRetFalse("error:");
    }
}

/*
** Try to process an operation on the stack
*/
void         AVM::processOperation(void)
{
    DBG_FUNC("AVM::processOperation");

    if (mz_rgx_op == "push")
        operation_push();
    else if (mz_rgx_op == "pop")
        operation_pop();
    else if (mz_rgx_op == "dump")
        operation_dump();
    else if (mz_rgx_op == "assert")
        operation_assert();
    else if (mz_rgx_op == "add")
        operation_add();
    else if (mz_rgx_op == "sub")
        operation_sub();
    else if (mz_rgx_op == "mul")
        operation_mul();
    else if (mz_rgx_op == "div")
        operation_div();
    else if (mz_rgx_op == "mod")
        operation_mod();
    else
        operation_print();
}

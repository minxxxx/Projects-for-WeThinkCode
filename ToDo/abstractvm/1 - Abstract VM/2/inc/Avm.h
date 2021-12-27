/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Avm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 09:08:23 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/31 13:31:12 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_H
# define AVM_H

# include <OperandFactory.h>

class AVM
{
public:
    AVM(void);
	AVM(const char *pz_filename);
	virtual ~AVM(void);
    
    /* LINE */
    void                    clearLine(void);
    bool                    getLine(void);
    void                    prepareLine(void);
    bool                    isLineValid(void);
    void                    addLineToAvm(void);
    void                    processOperation(void);

    /* Operations */
    void                    operation_push(void);
    void                    operation_pop(void);
    void                    operation_dump(void);
    void                    operation_assert(void);
    void                    operation_add(void);
    void                    operation_sub(void);
    void                    operation_mul(void);
    void                    operation_div(void);
    void                    operation_mod(void);
    void                    operation_print(void);

private:
	/* INTERNAL VARS */
    bool                    mb_readFromStdin;
    std::ifstream           mz_file;
    bool                    mb_exitAsked;
    std::vector<IOperand const*>  mv_ioStack;
    OperandFactory          mc_operandFactory;

    /* REGEX VARS */
    std::regex              mc_rgx_op;
    std::regex              mc_rgx_val;
    std::string             mz_rgx_op;
    std::string             mz_rgx_typ;
    std::string             mz_rgx_val;
    
    /* FUNCTIONS */
    void                    start(void);
    bool                    printErrorAndRetFalse(const std::string &pz_msg);

    /* LINE */
    std::string             mz_line;
    byte8                   m8_nbLinesRead;

    /* COPLIEN..... */
    AVM(AVM &src) = delete;
    AVM(AVM const &src) = delete;
    AVM &operator=(AVM &&rhs) = delete;
    AVM &operator=(AVM const &rhs) = delete;
};

#endif

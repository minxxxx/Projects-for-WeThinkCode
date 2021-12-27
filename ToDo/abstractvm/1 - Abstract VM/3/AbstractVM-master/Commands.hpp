/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:11:39 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/16 07:10:07 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
# define COMMANDS_HPP

# include <vector>
# include <iostream>
# include "Operand.hpp"
# include "Parse.hpp"

void	push(int line, std::string cmds[4], std::vector<IOperand const *> & stack, std::string input);
void	run_reg_cmds(std::string cmds[4], std::vector<IOperand const *> & stack, int line);
void	assert(int line, std::string cmds[4], std::vector<IOperand const *> & stack, std::string input);

#endif

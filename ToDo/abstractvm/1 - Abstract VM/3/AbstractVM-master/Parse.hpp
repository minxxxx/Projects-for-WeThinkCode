/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:58:51 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/16 07:09:48 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HPP
# define PARSE_HPP

# include <limits.h>
# include <cfloat>
# include <cmath>
# include <iostream>
# include <vector>
# include <sstream>
# include <regex>
# include "Error.hpp"
# include "IOperand.hpp"

std::vector<std::string>	splitspace(std::string input);

int		remove_comment(std::string & input);
void	validate(int line, std::string & input, std::string cmds[]);
void	CheckOUFlow(int line, std::string cmds[4], std::string input);
void	CheckOverUnderFlow(eOperandType _type, long double size);
void	create_file(std::vector<std::string> & lines);

#endif

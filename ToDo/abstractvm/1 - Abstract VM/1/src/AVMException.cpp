/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVMException.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:34:50 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/24 19:18:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AVMException.hpp"

AVMException::AVMException() {}
AVMException::AVMException(AVMException const & e) { *this = e; }

AVMException &AVMException::operator=(AVMException const &) { return *this; }

const char * AVMException::what(void) const throw () { return "General AVM Exception"; }

AVMException::~AVMException() {}


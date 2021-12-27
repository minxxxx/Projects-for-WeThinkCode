/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVMException.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:30:48 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/23 16:53:29 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVMEXCEPTION_HPP
#define AVMEXCEPTION_HPP

#include <iostream>
#include <fstream>
#include <exception>

class AVMException : public std::exception
{
public:
	AVMException();
	AVMException(AVMException const&);
	AVMException &operator=(AVMException const &);
	virtual ~AVMException();
	const char * what(void) const throw (); //{ return _msg.c_str(); }
};

#endif


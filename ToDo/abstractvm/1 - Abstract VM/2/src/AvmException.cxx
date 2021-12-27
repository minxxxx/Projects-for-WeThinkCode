/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvmException.cxx                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:03:52 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/31 14:56:51 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AvmException.h>

    AVMException::AVMException(const char *pz_msg) throw()
    : std::runtime_error(pz_msg)
    , mz_msg(pz_msg)
    {      
    }

    AVMException::AVMException(AVMException const &src)
    : std::runtime_error(src.what())
    , mz_msg(src.what())
    {
    }

    AVMException::~AVMException(void) throw()
    {
    }

    const char *AVMException::what(void) const throw()
    {
        return (mz_msg);
    }

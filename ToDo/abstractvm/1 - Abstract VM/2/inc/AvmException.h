/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvmException.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 09:14:59 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/31 14:55:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVMEXCEPTION_H
# define AVMEXCEPTION_H

# include <stdexcept>

class AVMException : public std::runtime_error
{
public:
    AVMException(const char *pz_msg) throw();
    AVMException(AVMException const &src);
    virtual ~AVMException(void) throw();
    virtual const char *what(void) const throw();
    
private:
    /* COPLIEN... */
    AVMException(void) throw();
    AVMException(AVMException &src) = delete;
    AVMException &operator=(AVMException &&rhs) = delete;
    AVMException &operator=(AVMException const &rhs) = delete;

    const char *mz_msg;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cxx                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:03:52 by wide-aze          #+#    #+#             */
/*   Updated: 2016/07/31 13:20:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Avm.h>

int     main(int ac, char **av)
{  
    if (ac > 2)
	{
        std::cerr << "error: too many args" << std::endl;
        return (1);
    }
    
    if (ac == 2)
        AVM((const char *)av[1]);
    else
        AVM();

	return (0);
}

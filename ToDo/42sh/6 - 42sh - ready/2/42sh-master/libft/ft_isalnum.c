/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:10:58 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:11:01 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Checks if it is a alphanumberical using isaplha and isdigit
*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

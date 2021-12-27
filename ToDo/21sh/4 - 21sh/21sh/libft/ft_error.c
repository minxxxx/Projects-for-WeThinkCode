/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 11:34:02 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/24 11:40:48 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(int err, char *str)
{
	if (err == 1)
		printf("error : failed to allocate memory for %s.\n", str);
	else if (err == 2)
		printf("error : failed to open file : %s.\n", str);
	printf("Program exited\n");
	exit(-1);
}

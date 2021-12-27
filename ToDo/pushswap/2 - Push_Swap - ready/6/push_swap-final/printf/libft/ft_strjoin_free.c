/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:55:04 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/09 14:52:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int choice)
{
	char			*new;

	new = NULL;
	if (!(new = ft_strjoin(s1, s2)))
		return (NULL);
	if (choice == 1)
		ft_strdel(&s1);
	else if (choice == 2)
		ft_strdel(&s2);
	else
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (new);
}

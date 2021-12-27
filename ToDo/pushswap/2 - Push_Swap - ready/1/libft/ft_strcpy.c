/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:11:18 by vtouffet          #+#    #+#             */
/*   Updated: 2017/11/09 10:51:53 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char const *src)
{
	char *s;

	s = dest;
	while ((*s++ = *src++))
		;
	return (dest);
}

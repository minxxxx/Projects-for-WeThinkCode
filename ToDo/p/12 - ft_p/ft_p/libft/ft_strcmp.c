/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:05:09 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/13 07:21:56 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (4242);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while ((*str1 == *str2) && (*str1) && (*str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

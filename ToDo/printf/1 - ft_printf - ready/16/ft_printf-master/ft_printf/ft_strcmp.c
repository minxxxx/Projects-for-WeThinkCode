/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:20:43 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 14:52:01 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		index1;
	int		index2;
	int		s;

	index1 = 0;
	index2 = 0;
	while (s1[index1] == s2[index2])
	{
		index1++;
		index2++;
		if (s1[index1] == '\0' && s2[index2] == '\0')
			return (0);
	}
	s = (unsigned char)s1[index1] - (unsigned char)s2[index2];
	return (s);
}

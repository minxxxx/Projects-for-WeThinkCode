/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 07:14:15 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/13 07:16:19 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_word(char const *s, char delim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (s[i] == delim)
			while (s[i] == delim)
				i++;
		if (s[i] != delim && s[i])
		{
			i++;
			j++;
			while (s[i] != delim && s[i])
				i++;
		}
	}
	return (j);
}

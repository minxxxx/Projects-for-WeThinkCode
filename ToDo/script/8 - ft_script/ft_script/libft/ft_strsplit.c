/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 09:34:15 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/10 18:12:43 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int			ft_count_string(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i] != c && s[i])
		{
			i++;
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static const char	*ft_give_string(char const *s, char c, int *global_counter)
{
	unsigned int	start;
	int				end;
	int				i;

	i = *global_counter;
	while (s[i] == c)
		i++;
	start = i;
	while (s[i] != c && s[i])
		i++;
	end = i;
	while (s[i] && s[i] != c)
		i++;
	*global_counter = i;
	return (ft_strsub(s, start, end - start));
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		global_counter;
	int		nb_string;
	char	**tab;

	if (s)
	{
		nb_string = ft_count_string(s, c);
		tab = (char**)malloc(sizeof(char*) * (nb_string + 1));
		if (tab == NULL)
			return (NULL);
		i = 0;
		global_counter = 0;
		while (i != nb_string)
		{
			tab[i] = ft_strdup(ft_give_string(s, c, &global_counter));
			i++;
		}
		tab[i] = (char*)malloc(sizeof(tab[i]) * 1);
		if (tab[i] == NULL)
			return (NULL);
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}

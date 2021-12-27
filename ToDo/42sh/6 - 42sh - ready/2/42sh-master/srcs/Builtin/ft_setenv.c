/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 10:38:13 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:50:59 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

char	*ft_equal(char *str)
{
	char	*temp;

	if (ft_strchr(str, '=') == NULL)
	{
		temp = ft_strjoin(str, "=");
		free(str);
		str = NULL;
		return (temp);
	}
	return (str);
}

int		ft_chkenv(t_all *a, char *b)
{
	int	i;

	i = 0;
	a->yes = 1;
	while (a->new[i])
	{
		if (ft_strstr(a->new[i], b) != NULL)
			return (1);
		i++;
	}
	return (0);
}

void	ft_makecap(t_all *a)
{
	int	i;

	i = 0;
	while (a->array[1][i] && a->array[1][i] != '=')
	{
		if (ft_islower(a->array[1][i]) == 1)
			a->array[1][i] = ft_toupper(a->array[1][i]);
		i++;
	}
}

void	ft_setenv(t_all *a)
{
	t_setenv	b;

	a->array[1] = ft_equal((a->array[1]));
	ft_makecap(a);
	b.str = ft_strsplit(a->array[1], '=');
	if (ft_chkenv(a, b.str[0]) == 0 && b.str[1] == NULL)
	{
		ft_delarray(b.str);
		b.newenv = ft_arraysdupone(a->new, a->array[1]);
		ft_delarray(a->new);
		a->new = ft_arraysdup(b.newenv);
		ft_delarray(b.newenv);
	}
	else if (b.str[1] != NULL)
	{
		b.newenv = ft_value(a, b.str);
		ft_delarray(b.str);
	}
	else
		ft_delarray(b.str);
}

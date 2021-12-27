/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:47:50 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:50:24 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

char	**ft_unsetenv(t_all *a)
{
	t_unset		uns;
	int			k;

	uns.i = ft_arraylen(a->new);
	uns.j = 0;
	a->array[1] = ft_equal(a->array[1]);
	ft_makecap(a);
	uns.n = ft_strlen(a->array[1]);
	uns.newenv = (char **)malloc(sizeof(char *) * (uns.i));
	k = 0;
	while (k < uns.i && a->new[uns.j])
	{
		if (ft_strncmp(a->new[uns.j], a->array[1], uns.n) == 0 && a->new[uns.j])
			uns.j++;
		if (a->new[uns.j] != NULL)
			uns.newenv[k] = ft_strdup(a->new[uns.j]);
		k++;
		uns.j++;
	}
	return (uns.newenv);
}

char	**ft_value(t_all *a, char **str)
{
	t_value		v;

	v.i = 0;
	while (ft_strstr(a->new[v.i], str[0]) == NULL)
		v.i++;
	v.s = ft_strsplit(a->new[v.i], '=');
	if (v.s[1] == NULL)
	{
		v.name = ft_strjoin(a->new[v.i], str[1]);
		ft_strdel(&(a->new[v.i]));
		a->new[v.i] = ft_strdup(v.name);
		ft_strdel(&v.name);
		ft_delarray(v.s);
		return (a->new);
	}
	else
	{
		ft_strdel(&(v.s[1]));
		v.s[0] = ft_addequal(v.s[0]);
		v.name = ft_strjoin(v.s[0], str[1]);
		a->new[v.i] = ft_strreplace(a->new[v.i], a->new[v.i], v.name);
		ft_delarray(v.s);
		ft_strdel(&v.name);
		return (a->new);
	}
}

/*
 ** This prints the env variable found
*/

void	ft_printenv(t_all *a)
{
	int		i;

	i = 0;
	while (a->new[i] != NULL)
	{
		ft_putendl(a->new[i]);
		i++;
	}
}

int		ft_setwithequal(t_all *a)
{
	int		n;
	char	**tmp;

	n = -1;
	if (ft_strchr(a->array[1], '=') != NULL)
	{
		while (a->array[1][n++] != '=')
			a->array[1][n] = ft_toupper(a->array[1][n]);
		tmp = ft_strsplit(a->array[1], '=');
		if (tmp[1] != NULL && ft_chkenv(a, tmp[0]) == 0)
			n = 1;
		ft_delarray(tmp);
	}
	if (n == 1)
	{
		tmp = ft_arraysdupone(a->new, a->array[1]);
		ft_delarray(a->new);
		a->new = ft_arraysdup(tmp);
		ft_delarray(tmp);
		return (1);
	}
	a->yes = 0;
	return (0);
}

void	ft_env(t_all *a)
{
	int		i;

	i = 0;
	if (ft_strcmp(a->array[0], "setenv") == 0)
	{
		i = (a->array[1] != NULL) ? ft_setwithequal(a) : 100;
		if (i == 0)
		{
			if (a->array[1] != NULL)
				ft_setenv(a);
			else
				ft_putendl("minishell: setenv: no value given");
		}
	}
	else if (ft_strcmp(a->array[0], "unsetenv") == 0)
		ft_unset_norm(a);
	else if (ft_strcmp(a->array[0], "env") == 0)
		ft_printenv(a);
}

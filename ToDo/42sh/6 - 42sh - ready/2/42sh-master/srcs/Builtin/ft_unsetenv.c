/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:01:09 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:51:08 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define SET_COUNT row=0;currentrow=0
#define FREE tmparr[row] = NULL;ft_strdel(&temp);ft_delarray(a->new)
#define TEMP temp=ft_addequ(var);temp=ft_strupr(temp);row=ft_arraylen(a->new)
#define WHILE tmparr[row]=ft_strdup(a->new[currentrow]);currentrow++;row++
#define INI char *temp;char **tmparr;int currentrow;int row;int n

int		ft_find_var(char *tofind, char **array)
{
	int		i;
	int		find;

	find = 0;
	i = ft_strlen(tofind);
	while (array[find] != NULL && ft_strnstr(array[find], tofind, i) == NULL)
		find++;
	i = ft_arraylen(array);
	if (find == i)
		return (0);
	return (1);
}

/*
 ** This will add an equel sign to the end of input to find better matches.
*/

char	*ft_addequ(char *str)
{
	int		i;
	char	*temp;

	i = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (i + 2));
	i = -1;
	while (str[++i])
	{
		temp[i] = str[i];
	}
	temp[i] = '=';
	temp[i + 1] = '\0';
	return (temp);
}

/*
 ** This will remove the str that matches the input. then return the new
 ** enviroment.
*/

char	**ft_unsetenv_new(t_all *a, char *var, int vlen)
{
	INI;
	n = ft_find_var(a->array[1], a->new);
	if (n == 1)
	{
		TEMP;
		tmparr = (char **)malloc(sizeof(char *) * (row));
		SET_COUNT;
		while (a->new[currentrow] != NULL)
		{
			if (a->new[row + 1] == NULL)
				break ;
			else if (ft_strncmp(a->new[currentrow], temp, (vlen + 1)) == 0)
				currentrow++;
			WHILE;
		}
		FREE;
		return (tmparr);
	}
	else
	{
		tmparr = ft_arraydup(a->new);
		ft_delarray(a->new);
		return (tmparr);
	}
}

/*
 ** This will start the unsetenv sequence if there was input after unsetenv.
*/

void	ft_unset_norm(t_all *a)
{
	int		len;

	len = (a->array[1] != NULL) ? ft_strlen(a->array[1]) : 1000;
	if (a->array[1] != NULL)
		a->new = ft_unsetenv_new(a, a->array[1], len);
	else
		ft_putendl("minishell: command not found: unsetenv");
}

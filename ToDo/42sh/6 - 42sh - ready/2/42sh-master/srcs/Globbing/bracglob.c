/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracglob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:02:16 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:52:07 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define BLOCKLEN (leninbrac(str) + 2)

static int				leninbrac(char *str)
{
	int			i;

	i = 0;
	while (str[i + 1] != ']')
		i++;
	return (i);
}

static char				*letters(char *str)
{
	int			i;
	int			k;
	char		*tmp;

	i = 1;
	k = 0;
	tmp = (char *)malloc(sizeof(char) * leninbrac(str));
	if ((str[0] == '[') && (brackets(str, 0)) && tmp != NULL)
	{
		while (str[i] != ']')
		{
			tmp[k] = str[i];
			k++;
			i++;
		}
	}
	return (tmp);
}

static char				*rangebrac(char *let, int i, int k)
{
	char		*rep;
	char		*buff;
	char		*wait;

	rep = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	buff = ft_strchr(rep, let[0]);
	while (buff[i] != let[2])
		i++;
	wait = (char *)malloc(sizeof(char) * i);
	while (buff[k] != let[2])
	{
		wait[k] = buff[k];
		k++;
	}
	wait[k] = let[2];
	free(let);
	return (wait);
}

static int				abstraction(const char *name, char *str, char *let)
{
	int k;

	k = 0;
	if ((str[0] == '[') && (brackets(str, 0)) && let != NULL)
	{
		if ((ft_strstr(name, &str[BLOCKLEN]) != 0)
	&& (ft_strlen(name) == (ft_strlen(str) - (BLOCKLEN - 1))))
			while (k < (int)ft_strlen(let))
			{
				if (name[0] == let[k])
				{
					free(let);
					return (1);
				}
				k++;
			}
		free(let);
	}
	return (0);
}

int						bracglob(const char *name, char *str)
{
	int			k;
	char		*let;
	char		*let1;

	k = 0;
	let1 = NULL;
	let = letters(str);
	if (rangeisvalid(let) == 0)
		return (0);
	if (let[1] == '-')
	{
		let1 = rangebrac(let, 0, 0);
		if (abstraction(name, str, let1) == 1)
			return (1);
	}
	else if (let[1] != '-')
	{
		if (abstraction(name, str, let) == 1)
			return (1);
	}
	return (0);
}

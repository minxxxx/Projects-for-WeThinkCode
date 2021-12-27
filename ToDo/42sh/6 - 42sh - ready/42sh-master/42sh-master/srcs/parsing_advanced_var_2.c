/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_advanced_var_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	while_arg_add_backslah(char *arg, int *i, int *j, char *ret)
{
	while (arg[*i])
	{
		if (is_quote(arg[*i]) || arg[*i] == '$'
			|| arg[*i] == '!' || arg[*i] == '\\')
		{
			ret[*j] = '\\';
			(*j)++;
		}
		ret[*j] = arg[*i];
		(*j)++;
		(*i)++;
	}
}

static char	*arg_add_backslash(char *arg)
{
	size_t		count;
	int			i;
	char		*ret;
	int			j;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (is_quote(arg[i]) || arg[i] == '$'
			|| arg[i] == '!' || arg[i] == '\\')
			count++;
		count++;
		i++;
	}
	ret = mallocp(sizeof(char) * (count + 1));
	i = 0;
	j = 0;
	while_arg_add_backslah(arg, &i, &j, ret);
	free(arg);
	ret[j] = '\0';
	return (ret);
}

int			delete_var_and_replace(char **str,
	size_t index, size_t length, char *arg)
{
	char	*new_str;
	size_t	real_length;

	if (index > 0)
		new_str = ft_strsub(*str, 0, index);
	else
		new_str = ft_strdup("");
	arg = arg_add_backslash(arg);
	real_length = ft_strlen(arg);
	new_str = ft_strjoinaf12(new_str, arg);
	new_str = ft_strjoinaf1(new_str, (*str) + length);
	free(*str);
	*str = new_str;
	return (real_length);
}

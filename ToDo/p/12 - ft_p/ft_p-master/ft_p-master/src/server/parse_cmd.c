/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:48 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:49 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static int	find_nbr_from_str_2(char *str, int len)
{
	if (ft_strnequ(str, NAME_LIST, len))
		return (VALUE_LIST);
	else if (ft_strnequ(str, NAME_TYPE, len))
		return (VALUE_TYPE);
	else if (ft_strnequ(str, NAME_SIZE, len))
		return (VALUE_SIZE);
	else if (ft_strnequ(str, NAME_MDTM, len))
		return (VALUE_MDTM);
	else if (ft_strnequ(str, NAME_RETR, len))
		return (VALUE_RETR);
	else if (ft_strnequ(str, NAME_STOR, len))
		return (VALUE_STOR);
	else if (ft_strnequ(str, NAME_QUIT, len))
		return (VALUE_QUIT);
	else
		return (-1);
}

static int	find_nbr_from_str(char *str, int len)
{
	if (ft_strnequ(str, NAME_USER, len))
		return (VALUE_USER);
	else if (ft_strnequ(str, NAME_PASS, len))
		return (VALUE_PASS);
	else if (ft_strnequ(str, NAME_SYST, len))
		return (VALUE_SYST);
	else if (ft_strnequ(str, NAME_FEAT, len))
		return (VALUE_FEAT);
	else if (ft_strnequ(str, NAME_CWD, len))
		return (VALUE_CWD);
	else if (ft_strnequ(str, NAME_PWD, len))
		return (VALUE_PWD);
	else if (ft_strnequ(str, NAME_CDUP, len))
		return (VALUE_CDUP);
	else if (ft_strnequ(str, NAME_PASV, len))
		return (VALUE_PASV);
	else
		return (find_nbr_from_str_2(str, len));
}

static char	*get_next_part(char *str, int *i)
{
	int	len;
	int	j;

	len = 1;
	j = -1;
	while (str[*i])
	{
		if (str[*i] == ' ')
		{
			if (j != -1)
				return (ft_strsub(str, j, len));
		}
		else
		{
			if (j == -1)
				j = *i;
			else
				len++;
		}
		(*i)++;
	}
	if (j != -1)
		return (ft_strsub(str, j, len));
	return (NULL);
}

t_command	parse_cmd(char *str, t_data *data)
{
	t_command	ret;
	int			i;

	i = 0;
	ret.str_commande = get_next_part(str, &i);
	if (ret.str_commande == NULL)
	{
		data->error = 1;
		ret.nbr_commande = -1;
		return (ret);
	}
	ret.argument = get_next_part(str, &i);
	ret.nbr_commande = find_nbr_from_str(ret.str_commande,
			ft_strlen(ret.str_commande));
	return (ret);
}

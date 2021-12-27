/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 07:41:25 by rde-beer          #+#    #+#             */
/*   Updated: 2017/11/24 02:55:30 by rde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define CHECK_IF_I_EQUALS_MATCH if(i==match)break;
#define GNL if(get_next_line(0,&c)==0)break;

/*
 ** Creates a new array with no "<<" symbols
*/

char	**ft_remove_arrows(char **array)
{
	char	**temp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (array[i])
	{
		if (ft_strcmp(array[i], "<<") != 0)
			len++;
		i++;
	}
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	i = -1;
	len = -1;
	while (array[++i] != NULL)
	{
		if (ft_strcmp(array[i], "<<") != 0)
			temp[++len] = ft_strdup(array[i]);
	}
	temp[len] = NULL;
	return (temp);
}

/*
 ** If only one then run this. example when to run this function: << eof
*/

void	ft_single(char **array)
{
	char	**heredoc;
	char	*c;

	heredoc = ft_set_heredoc_arr();
	while (1)
	{
		ft_putstr(RED"heredoc > "RESET);
		GNL;
		if (ft_strcmp(array[1], c) == 0)
			break ;
		else
			heredoc = ft_add_to_array(heredoc, c);
		ft_strdel(&c);
	}
	ft_print_arr(heredoc);
	ft_strdel(&c);
	ft_delarray(heredoc);
}

/*
 ** Remove all strs with "<<" out the array
*/

char	**remove_strs(char **old, char *to_rm)
{
	int			i;
	int			len;
	char		**new;

	i = -1;
	len = 0;
	while (old[++i] != NULL)
	{
		if (ft_strcmp(old[i], to_rm) != 0)
			len++;
	}
	i = -1;
	new = (char **)malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (old[++i])
	{
		if (ft_strcmp(old[i], to_rm) != 0)
		{
			new[len] = ft_strdup(old[i]);
			len++;
		}
	}
	new[len] = NULL;
	return (new);
}

/*
 ** If only multi then run this. example when to run this function: << eof << e
*/

void	ft_multi(char **array)
{
	char	**heredoc;
	char	*c;
	char	**strs;
	int		i;
	int		match;

	strs = remove_strs(array, "<<");
	match = ft_arraylen(strs);
	i = 0;
	heredoc = ft_set_heredoc_arr();
	while (1)
	{
		ft_putstr(RED"heredoc > "RESET);
		GNL;
		if (ft_strcmp(c, strs[i]) == 0)
			i++;
		else
			heredoc = ft_add_to_array(heredoc, c);
		CHECK_IF_I_EQUALS_MATCH;
		ft_strdel(&c);
	}
	ft_print_arr(heredoc);
	ft_strdel(&c);
	ft_delarray(strs);
	ft_delarray(heredoc);
}

/*
 ** This command will run if theres nothing before the heredoc arrows
 ** example: "<< eof"
*/

void	ft_heredoc_no_cmd(char **arr, t_all *a)
{
	int	i;

	a->yes = 1;
	i = ft_arraylen(arr) - 1;
	if (i == 1)
		ft_single(arr);
	else
		ft_multi(arr);
}

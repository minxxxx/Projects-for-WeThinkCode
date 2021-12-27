/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:26:46 by rde-beer          #+#    #+#             */
/*   Updated: 2017/11/24 02:55:20 by rde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define GNL	if(get_next_line(0,&c)==0)break;

/*
 **	NULL terminates the array so we can manupilate it.
*/

char	**ft_set_heredoc_arr(void)
{
	char			**temp;

	temp = (char **)malloc(sizeof(char *) * 1);
	temp[0] = NULL;
	return (temp);
}

/*
 ** Run this command if only piping on heredoc.
*/

void	ft_single_heredoc(char **holder, t_all *a)
{
	char	*c;
	char	**heredoc;

	heredoc = ft_set_heredoc_arr();
	while (1)
	{
		ft_putstr(RED"heredoc > "RESET);
		GNL;
		if (ft_strcmp(c, holder[1]) == 0)
			break ;
		else
			heredoc = ft_add_to_array(heredoc, c);
		ft_strdel(&c);
	}
	ft_strdel(&c);
	ft_direct_heredoc(heredoc, holder[0], a);
	ft_delarray(heredoc);
}

/*
 ** Run this command if piping multiple times.
*/

void	ft_multi_heredoc(char **holder, int i, t_all *a)
{
	char	*c;
	char	**heredoc;

	heredoc = ft_set_heredoc_arr();
	while (i)
	{
		ft_putstr(RED"heredoc > "RESET);
		GNL;
		if (ft_strcmp(c, holder[i]) == 0)
			i--;
		else
			heredoc = ft_add_to_array(heredoc, c);
		ft_strdel(&c);
	}
	ft_strdel(&c);
	ft_direct_heredoc(heredoc, holder[0], a);
	ft_delarray(heredoc);
}

/*
 ** Checks the arguments have multiple heredoc files to check for.
*/

void	ft_heredoc(char **holder, t_all *a)
{
	int i;

	a->piped = 1;
	i = ft_arraylen(holder) - 1;
	if (i == 1)
		ft_single_heredoc(holder, a);
	else
		ft_multi_heredoc(holder, i, a);
}

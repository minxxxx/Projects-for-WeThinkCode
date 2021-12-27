/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_stderr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 09:27:10 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:46:38 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define CLOSE_ONE_TWO close(1);close(2)

/*
 ** Need to remove the number "2" from the cmds;
*/

char	*remove_two(char *str)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (len - 1));
	while (str[i] && str[i] != ' ')
	{
		if (i == (len - 1))
			break ;
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	ft_strdel(&str);
	return (temp);
}

/*
 ** Prints out only the error to the file
*/

void	ft_stderr(char **holder, t_all *a)
{
	pid_t	father;
	int		i;
	char	**cmds;

	i = -1;
	while (holder[++i])
	{
		ft_createfile(holder[i], a);
		father = fork();
		if (father == 0)
		{
			close(2);
			open(holder[i], O_WRONLY | O_TRUNC);
			holder[0] = remove_two(holder[0]);
			ft_execvp(holder[0], a);
			CLOSE_ONE_TWO;
			open(holder[i], O_WRONLY | O_TRUNC);
			cmds = ft_strsplit(holder[0], ' ');
			ft_cmd_unknown(cmds[0]);
			ft_delarray(cmds);
			exit(0);
		}
		else
			wait(&father);
	}
}

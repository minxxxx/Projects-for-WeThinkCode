/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipexec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 14:20:58 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:46:02 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define CHKFORPIPE 	b.i=0;if(ft_strstr(holder[0]," | ")!=NULL)b.i = -1
#define CHKFORPIPETWO if(ft_strstr(holder[0]," | ")!=NULL)++b.i
#define FORK father=fork();if(father>0)wait(0)

/*
 ** Create file creates the files that are needed to redirect in if it does not
 ** exist.
*/

void	ft_createfile(char *file, t_all *a)
{
	pid_t	father;
	char	*path;

	path = ft_strjoin("touch ", file);
	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		ft_execvp(path, a);
		ft_putstr("execve failed to create the file: ");
		ft_putendl(file);
		exit(0);
	}
	ft_strdel(&path);
}

/*
 ** This function writes to the end of the file when redirecting if it exists
 ** Need to add extra part that creates none existing file
*/

void	ft_redirect_in_append(char **holder, t_all *a)
{
	char	**cmds;
	pid_t	father;
	int		fd;
	int		i;

	i = 1;
	while (holder[i] != NULL)
	{
		cmds = ft_strsplit(holder[0], ' ');
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
		{
			close(1);
			fd = open(holder[i], O_CREAT | O_WRONLY | O_APPEND, 0777);
			ft_execvp(holder[0], a);
			ft_cmd_unknown(cmds[0]);
			exit(0);
		}
		ft_delarray(cmds);
		i++;
	}
}

/*
 ** This function creates new files or overwrites existing file when redirecting
 ** stdout into the files.
*/

void	ft_redirect_in(char **holder, t_all *a)
{
	pid_t	father;
	t_red	b;

	CHKFORPIPE;
	while (holder[++b.i] != NULL)
	{
		FORK;
		if (father == 0)
		{
			close(1);
			CHKFORPIPETWO;
			b.fd = open(holder[b.i], O_CREAT | O_WRONLY | O_TRUNC, 0666);
			if (ft_strstr(holder[--b.i], "|") != NULL)
				ft_line(holder[b.i], a);
			else
			{
				close(2);
				ft_execvp(holder[0], a);
				b.cmds = ft_strsplit(holder[0], ' ');
				ft_cmd_unknown(b.cmds[0]);
				ft_delarray(b.cmds);
			}
			exit(0);
		}
	}
}

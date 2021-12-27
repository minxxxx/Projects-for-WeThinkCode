/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipexec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 14:20:58 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:45:28 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define CLOSE close(1);close(2)
#define FD_OUT fd_out=open(holder[i],O_WRONLY|O_TRUNC)
#define FD_ERR fd_err=open(holder[i],O_WRONLY|O_TRUNC)
#define FD_OUT_A fd_out=open(holder[i],O_WRONLY|O_APPEND)
#define FD_ERR_A fd_err=open(holder[i],O_WRONLY|O_APPEND)
#define ALL CLOSE;FD_OUT;FD_ERR
#define ALL_APPEND CLOSE;FD_OUT_A;FD_ERR_A
#define UKN cmds=ft_strsplit(holder[0],' ');ft_cmd_unknown(cmds[0])

/*
 ** This function writes to the end of the file when redirecting if it exists
 ** Need to add extra part that creates none existing file
*/

void	ft_std_everything_append(char **holder, t_all *a)
{
	char	**cmds;
	pid_t	father;
	int		fd_out;
	int		fd_err;
	int		i;

	i = ft_arraylen(holder);
	ft_strdel(&(holder[i - 1]));
	holder[i - 2] = remove_two(holder[i - 2]);
	i = 0;
	while (holder[++i] != NULL)
	{
		ft_createfile(holder[i], a);
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
		{
			ALL_APPEND;
			ft_execvp(holder[0], a);
			UKN;
			ft_delarray(cmds);
			exit(0);
		}
	}
}

/*
 ** This function creates new files or overwrites existing file when redirecting
 ** stdout into the files.
*/

void	ft_std_everything(char **holder, t_all *a)
{
	char	**cmds;
	pid_t	father;
	int		fd_out;
	int		fd_err;
	int		i;

	i = ft_arraylen(holder);
	ft_strdel(&(holder[i - 1]));
	holder[i - 2] = remove_two(holder[i - 2]);
	i = 0;
	while (holder[++i] != NULL)
	{
		ft_createfile(holder[i], a);
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
		{
			ALL;
			ft_execvp(holder[0], a);
			UKN;
			ft_delarray(cmds);
			exit(0);
		}
	}
}

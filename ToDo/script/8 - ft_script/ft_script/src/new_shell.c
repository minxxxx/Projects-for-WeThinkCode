/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 20:19:50 by wide-aze          #+#    #+#             */
/*   Updated: 2015/11/08 17:02:47 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>
#include <fcntl.h>
#include <unistd.h>

#define CMD2LONG_MSG "ft_script: cmd too long"
#define EXECVE_ERR_MSG "ft_script: can't execute cmd"

static char		*convert_cmdtab_to_cmdstr(t_env *env, char *cmdstr, int i)
{
	int		j;

	j = -1;
	ft_bzero(cmdstr, 1024);
	while (CMD(++j))
	{
		ft_memcpy(&cmdstr[i], CMD(j), ft_strlen(CMD(j)));
		i += ft_strlen(CMD(j));
		if (i >= 1024)
		{
			ft_putendl_fd(CMD2LONG_MSG, 2);
			return (NULL);
		}
		if (CMD(j + 1))
		{
			ft_memcpy(&cmdstr[i], " ", 1);
			i++;
			if (i >= 1024)
			{
				ft_putendl_fd(CMD2LONG_MSG, 2);
				return (NULL);
			}
		}
	}
	return (cmdstr);
}

static int		fill_cmdtab(t_env *env, char **cmdtab, char *cmdstr, char *cstr)
{
	cmdtab[0] = SHELLNAME;
	ft_bzero(&cmdtab[1], sizeof(char*) * 3);
	if (NB_CMD)
	{
		cmdtab[1] = cstr;
		if (!(cmdtab[2] = convert_cmdtab_to_cmdstr(env, cmdstr, 0)))
			return (-1);
	}
	return (0);
}

static void		fork_for_master_slave(t_env *env, char **cmdtab)
{
	pid_t			pid;
	struct termios	term_tmp;

	ft_tcattr(0, &term_tmp, TRUE);
	TERM_ATTR = term_tmp;
	ft_cfmakeraw(&term_tmp);
	ft_tcattr(0, &term_tmp, FALSE);
	if ((pid = fork()) < 0)
		ft_putendl_fd(EXECVE_ERR_MSG, 2);
	else if (pid)
	{
		im_master(env);
		ft_tcattr(0, &TERM_ATTR, FALSE);
	}
	else
	{
		im_slave(env, cmdtab);
		_exit(0);
	}
}

int				launch_scripted_shell(t_env *env, const char *cstr)
{
	char	*cmdtab[4];
	char	cmdstr[1024];
	char	readbuf[BUFSIZE];
	char	flushbuf[BUFSIZE];

	READBUF = &readbuf[0];
	FLUSHBUF = &flushbuf[0];
	ft_bzero(READBUF, sizeof(char) * BUFSIZE);
	ft_bzero(FLUSHBUF, sizeof(char) * BUFSIZE);
	if (fill_cmdtab(env, &cmdtab[0], &cmdstr[0], (char*)cstr)
	|| !ft_openpt(env))
		return (-1);
	CMDSTR = &cmdstr[0];
	fork_for_master_slave(env, &cmdtab[0]);
	return (0);
}

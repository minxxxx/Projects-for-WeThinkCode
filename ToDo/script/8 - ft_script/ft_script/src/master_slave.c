/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_slave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 13:53:50 by wide-aze          #+#    #+#             */
/*   Updated: 2015/11/08 15:21:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define EXECVE_ERR_MSG "ft_script: can't execute cmd"
#define TIMEOUT_EXCEEDED (get_time() >= OPT_M_TIME)

static int		ftscript_start_stop_stuffs(t_env *env, t_bool isstart)
{
	ft_flush(env);
	if (OPT_Q)
		return (1);
	if (isstart)
	{
		ft_putstr("Script started, output file is ");
		ft_putendl((FILENAME) ? FILENAME : "typescript");
		ft_putstr_fd("Script started on ", OUTFILE_FD);
		ft_putstr_fd(get_strtime(), OUTFILE_FD);
		if (NB_CMD)
		{
			ft_putstr_fd("command: ", OUTFILE_FD);
			ft_putendl_fd(CMDSTR, OUTFILE_FD);
		}
	}
	else
	{
		ft_putstr("\nScript done, output file is ");
		ft_putendl((FILENAME) ? FILENAME : "typescript");
		ft_putstr_fd("\nScript done on ", OUTFILE_FD);
		ft_putstr_fd(get_strtime(), OUTFILE_FD);
	}
	return (1);
}

void			im_slave(t_env *env, char **cmdtab)
{
	close(PTM);
	dup2(PTS, 0);
	dup2(PTS, 1);
	dup2(PTS, 2);
	close(PTS);
	setsid();
	ioctl(0, TIOCSCTTY, 1);
	execve(SHELLNAME, cmdtab, ENVIRON_SAVE);
	ft_putendl_fd(EXECVE_ERR_MSG, 2);
}

static int		im_master2(t_env *env, fd_set *fd_stdin, int ret)
{
	if (FD_ISSET(0, fd_stdin))
	{
		if ((ret = read(0, READBUF, BUFSIZE)) <= 0)
		{
			ft_putendl("exit");
			return (ftscript_start_stop_stuffs(env, FALSE));
		}
		write(PTM, READBUF, ret);
		if (OPT_K)
			handle_flush(env);
	}
	if (FD_ISSET(PTM, fd_stdin))
	{
		if ((ret = read(PTM, READBUF, BUFSIZE)) <= 0)
			return (ftscript_start_stop_stuffs(env, FALSE));
		write(1, READBUF, ret);
		handle_flush(env);
	}
	return (0);
}

int				im_master(t_env *env)
{
	fd_set	fd_stdin;

	close(PTS);
	ftscript_start_stop_stuffs(env, TRUE);
	while (42)
	{
		if (OPT_M_ENABLED && TIMEOUT_EXCEEDED)
			_exit(0);
		FD_ZERO(&fd_stdin);
		FD_SET(0, &fd_stdin);
		FD_SET(PTM, &fd_stdin);
		if (select(PTM + 1, &fd_stdin, NULL, NULL, NULL) == -1)
			return (ft_putendl_fd_ret("select error", 2, 1));
		if (im_master2(env, &fd_stdin, 0))
			return (1);
	}
}

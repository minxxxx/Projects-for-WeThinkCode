/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:40:29 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:40:30 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

static void	init_child(int pipe_to_read)
{
	char			sbuffer[11];
	struct winsize	w;
	int				fd;

	setsid();
	ioctl(0, TIOCGSIZE, &w);
	read(pipe_to_read, sbuffer, 10);
	close(pipe_to_read);
	fd = open(sbuffer, O_RDWR);
	if (fd == -1)
		_exit(1);
	ioctl(fd, TIOCSCTTY, 0);
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	ioctl(0, TIOCSSIZE, &w);
	close(fd);
}

int			child(int pipe_to_read, t_opt *opt)
{
	int		fd;
	char	shell[1024];

	init_child(pipe_to_read);
	if (opt->argv == NULL)
	{
		ft_strncpy(shell, get_shell(opt->default_args.envp), sizeof(shell));
		fd = execve(shell, (char*[]){shell, NULL}, opt->default_args.envp);
	}
	else
	{
		if (opt->argv[0][0] == '/')
			ft_strncpy(shell, opt->argv[0], 1024);
		else if (!find_in_path(opt->argv[0], opt->default_args.envp, shell))
		{
			ft_putstr_fd(opt->argv[0], 2);
			ft_putstr_fd(": No such file or directory.\n", 2);
			return (0);
		}
		fd = execve(shell, opt->argv, opt->default_args.envp);
	}
	ft_putstr_fd("ft_script: ", 2);
	ft_putstr_fd(shell, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	_exit(88);
}

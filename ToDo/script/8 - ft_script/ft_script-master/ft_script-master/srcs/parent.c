/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:43:00 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:43:00 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

static int	prepare_parent(int pipe_to_write, int *mfd, struct termios *old)
{
	char			mbuffer[11];
	char			sbuffer[11];
	struct termios	new;

	ignore_signals();
	if (open_ttys(mbuffer, sbuffer, mfd) == 0)
		return (0);
	write(pipe_to_write, sbuffer, 10);
	close(pipe_to_write);
	ioctl(0, TIOCGETA, old);
	singelton_tty(old);
	ft_memcpy(&new, old, sizeof(new));
	new.c_lflag &= ~ECHO;
	new.c_lflag &= ~ICANON;
	new.c_lflag &= ~ISIG;
	ioctl(0, TIOCSETA, &new);
	return (1);
}

static void	kill_child_and_exit(int child_pid)
{
	kill(child_pid, SIGKILL);
	_exit(1);
}

static void	print_and_exit_bad_open(char *output_file, int child_pid)
{
	ft_putstr_fd(output_file, 2);
	ft_putstr_fd(": Can't open file.\n", 2);
	reset_terminal();
	kill_child_and_exit(child_pid);
}

static void	print_message_if_needed(int fd, t_opt *opt)
{
	if (!(opt->options & Q_OPT))
	{
		output_file_singelton(fd);
		write_started_message("started", opt->output_file);
		write_time(fd, "started");
		if (opt->argv)
			write_command(fd, opt->argv);
	}
}

int			parent(int pipe_to_write, t_opt *opt, int child_pid)
{
	int				mfd;
	int				pid;
	struct termios	old;
	int				fd;

	if (!prepare_parent(pipe_to_write, &mfd, &old))
		kill_child_and_exit(child_pid);
	fd = open(opt->output_file, opt->open_flags | O_CLOEXEC, 0644);
	if (fd == -1)
		print_and_exit_bad_open(opt->output_file, child_pid);
	print_message_if_needed(fd, opt);
	pid = fork();
	if (pid == -1)
		kill_child_and_exit(child_pid);
	if (pid == 0)
		command_user_multiplex(mfd, fd, &old);
	else
	{
		handler(pid);
		user_command_multiplex(mfd, fd, &old, opt);
	}
	return (1);
}

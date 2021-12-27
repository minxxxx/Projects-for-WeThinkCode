/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:46:33 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:46:34 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

void	write_time(int fd, char *started_or_done)
{
	struct timeval	act_time;

	write(fd, "Script ", 7);
	write(fd, started_or_done, ft_strlen(started_or_done));
	write(fd, " on ", 4);
	gettimeofday(&act_time, NULL);
	write(fd, ctime(&(act_time.tv_sec)), 25);
}

void	write_started_message(char *started_or_done, char *output_file)
{
	static char *stat = NULL;

	if (!stat)
		stat = output_file;
	write(1, "Script ", 7);
	write(1, started_or_done, ft_strlen(started_or_done));
	write(1, ", output file is ", 17);
	if (output_file)
		write(1, output_file, ft_strlen(output_file));
	else
		write(1, stat, ft_strlen(stat));
	write(1, "\n", 1);
}

void	write_command(int fd, char **argv)
{
	int	i;

	write(fd, "command: ", 9);
	i = 0;
	while (argv[i])
	{
		write(fd, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write(fd, " ", 1);
		i++;
	}
	write(fd, "\n", 1);
}

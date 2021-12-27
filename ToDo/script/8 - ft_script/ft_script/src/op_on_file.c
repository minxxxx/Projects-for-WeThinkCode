/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_on_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 07:01:36 by wide-aze          #+#    #+#             */
/*   Updated: 2015/10/27 09:01:19 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>

#define ERR_CLOSE_MSG "./ft_script: close failed: Cannot close file"
#define IS_A_DIR_MSG "./ft_script: open failed: Is a directory"
#define BAD_PERM_MSG "./ft_script: open failed: Permission denied"
#define UNEXP_OPEN_ERR_MSG "./ft_script: open failed: Unexpected error"
#define CHMOD644 (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

time_t	get_time(void)
{
	struct timeval		tp;

	while (gettimeofday(&tp, NULL))
		;
	return (tp.tv_sec);
}

char	*get_strtime(void)
{
	time_t	now;

	while (!(now = get_time()))
		;
	return (ctime(&now));
}

void	close_outfile(t_env *env)
{
	if (close(OUTFILE_FD))
		ft_putendl_fd(ERR_CLOSE_MSG, 2);
}

int		open_outfile(t_env *env)
{
	struct stat		l_s;
	t_bool			file_exist;

	if (lstat(FILENAME, &l_s) < 0)
		file_exist = FALSE;
	else
		file_exist = TRUE;
	if (file_exist && S_ISDIR(l_s.st_mode))
		return (ft_putendl_fd_ret(IS_A_DIR_MSG, 2, -1));
	if (file_exist && !(l_s.st_mode & S_IWUSR))
		return (ft_putendl_fd_ret(BAD_PERM_MSG, 2, -1));
	if (OPT_A)
		OUTFILE_FD = open(FILENAME, O_WRONLY | O_CREAT | O_APPEND, CHMOD644);
	else
		OUTFILE_FD = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, CHMOD644);
	if (OUTFILE_FD == -1)
		return (ft_putendl_fd_ret(UNEXP_OPEN_ERR_MSG, 2, -1));
	return (0);
}

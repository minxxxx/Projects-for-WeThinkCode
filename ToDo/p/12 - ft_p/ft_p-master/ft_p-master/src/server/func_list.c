/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:18 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:18 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

char	*build_line(char *str, struct stat stats, struct dirent *dirent,
		char *rights)
{
	char		*c_time;

	str = ft_strjoinaf1(str, rights);
	str = ft_strjoinaf1(str, " ");
	str = ft_strjoinaf12(str, ft_itoa_base(stats.st_nlink, 10));
	str = ft_strjoinaf1(str, " ");
	str = ft_strjoinaf12(str, ft_itoa_base(stats.st_uid, 10));
	str = ft_strjoinaf1(str, " ");
	str = ft_strjoinaf12(str, ft_itoa_base(stats.st_gid, 10));
	str = ft_strjoinaf1(str, " ");
	str = ft_strjoinaf12(str, ft_itoa_base(stats.st_size, 10));
	str = ft_strjoinaf1(str, " ");
	c_time = ctime(&((stats.st_mtimespec).tv_sec));
	str = ft_strjoinaf12(str, ft_strsub(c_time, 4, 3));
	str = ft_strjoinaf1(str, " ");
	str = ft_strjoinaf12(str, ft_strsub(c_time, 8, 2));
	str = ft_strjoinaf1(str, " ");
	str = ft_strjoinaf12(str, ft_strsub(c_time, 11, 5));
	str = ft_strjoinaf1(str, " ");
	str = ft_strjoinaf1(str, dirent->d_name);
	str = ft_strjoinaf1(str, "\r\n");
	return (str);
}

char	*build_list(char *chemin, DIR *dirp, char rights[11])
{
	char			*chemin_file;
	char			*str;
	struct dirent	*dirent;
	struct stat		stats;
	int				fd;

	str = ft_strdup("");
	while ((dirent = readdir(dirp)))
	{
		chemin_file = ft_strjoinaf1(ft_strjoin(chemin, "/"), dirent->d_name);
		if ((fd = open(chemin_file, O_RDONLY)) != -1)
		{
			if (fstat(fd, &stats) != -1)
				get_rights(rights, stats.st_mode);
			else
				ft_strcpy(rights, "----------");
			close(fd);
		}
		else
			ft_strcpy(rights, "----------");
		str = build_line(str, stats, dirent, rights);
	}
	return (str);
}

void	func_list(t_data *data)
{
	t_command	cmd;
	char		*str;
	char		rights[11];
	char		*chemin;
	DIR			*dirp;

	if (!data->logged_in)
		return (setret(data, 530, " Please login with USER and PASS", 1));
	if (!data->data_connection_on)
		return (setret(data, 425, " Use PASV first.", 1));
	cmd = *(data->cmd);
	if (cmd.argument)
		chemin = cmd.argument;
	else
		chemin = ft_strdup(".");
	dirp = opendir_wrapper(data, chemin);
	if (!dirp)
		return (setret(data, 550, " Can't open the specified directory", 1));
	str = build_list(chemin, dirp, rights);
	free(chemin);
	send_data_list(data, str);
	close_data_connection(data);
	data->return_code = 226;
	data->commentaire = " Directory send OK.";
}

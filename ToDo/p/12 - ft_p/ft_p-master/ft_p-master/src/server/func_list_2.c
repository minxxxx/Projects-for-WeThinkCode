/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_list_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:19 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static char	handle_type(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFREG)
		return ('-');
	else if ((mode & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((mode & S_IFMT) == S_IFSOCK)
		return ('s');
	else
		return ('-');
}

void		get_rights_3(char *ret, mode_t mode)
{
	ret[7] = (mode & S_IROTH ? 'r' : '-');
	ret[8] = (mode & S_IWOTH ? 'w' : '-');
	if (mode & S_ISVTX && !(mode & S_IXOTH))
		ret[9] = 'T';
	else if (mode & S_ISVTX && (mode & S_IXOTH))
		ret[9] = 't';
	else if (!(mode & S_ISVTX) && (mode & S_IXOTH))
		ret[9] = 'x';
	else
		ret[9] = '-';
}

void		get_rights_2(char *ret, mode_t mode)
{
	ret[4] = (mode & S_IRGRP ? 'r' : '-');
	ret[5] = (mode & S_IWGRP ? 'w' : '-');
	if (mode & S_ISGID && !(mode & S_IXGRP))
		ret[6] = 'S';
	else if (mode & S_ISGID && (mode & S_IXGRP))
		ret[6] = 's';
	else if (!(mode & S_ISGID) && (mode & S_IXGRP))
		ret[6] = 'x';
	else
		ret[6] = '-';
}

void		get_rights(char *ret, mode_t mode)
{
	ret[0] = handle_type(mode);
	ret[1] = (mode & S_IRUSR ? 'r' : '-');
	ret[2] = (mode & S_IWUSR ? 'w' : '-');
	if (mode & S_ISUID && !(mode & S_IXUSR))
		ret[3] = 'S';
	else if (mode & S_ISUID && (mode & S_IXUSR))
		ret[3] = 's';
	else if (!(mode & S_ISUID) && (mode & S_IXUSR))
		ret[3] = 'x';
	else
		ret[3] = '-';
	get_rights_2(ret, mode);
	get_rights_3(ret, mode);
	ret[10] = '\0';
}

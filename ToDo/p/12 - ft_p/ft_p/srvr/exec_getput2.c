/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_getput2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 14:33:21 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 16:22:39 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <sys/stat.h>
#include <unistd.h>

#define U_INT unsigned int
#define MSG_READERR "Error while copying file (read error)"
#define MSG_WRTERR "Error while copying file (write error)"

static U_INT	give_file_size(int fd)
{
	struct stat		st;

	if (fstat(fd, &st) < 0)
		return (0);
	return ((U_INT)st.st_size);
}

t_bool			cpy_file(int srcfd, int dstfd, int clnt)
{
	const U_INT	size = give_file_size(srcfd);
	U_INT		count;
	char		buf[1000];

	if (!size)
		return (send_resp_to_clnt(NULL, clnt), TRUE);
	count = 0;
	while (count < size)
	{
		if (read(srcfd, &buf[0], 1) <= 0)
			return (send_resp_to_clnt(MSG_READERR, clnt), FALSE);
		if (write(dstfd, &buf[0], 1) <= 0)
			return (send_resp_to_clnt(MSG_WRTERR, clnt), FALSE);
		count++;
	}
	send_resp_to_clnt(NULL, clnt);
	return (TRUE);
}

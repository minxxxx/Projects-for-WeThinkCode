/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 14:55:26 by wide-aze          #+#    #+#             */
/*   Updated: 2015/10/25 14:57:50 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

#define TIME_SINCE_LASTFLUSH (get_time() - LAST_FLUSHTIME)
#define FLUSHTIME_EXCEEDED ((TIME_SINCE_LASTFLUSH >= (long)OPT_T_VALUE) ? 1 : 0)
#define FLUSHBUF_REMAINING_SPACE (BUFSIZE - ft_strlen(FLUSHBUF) - 1)

static void		ft_fullfill_and_flush(t_env *env)
{
	char	tmp[BUFSIZE];

	ft_bzero(&tmp[0], BUFSIZE);
	ft_strncat(FLUSHBUF, READBUF, FLUSHBUF_REMAINING_SPACE);
	ft_strcat(&tmp[0], &READBUF[FLUSHBUF_REMAINING_SPACE]);
	ft_bzero(READBUF, BUFSIZE);
	ft_strcat(READBUF, &tmp[0]);
	ft_putstr_fd(FLUSHBUF, OUTFILE_FD);
	ft_bzero(FLUSHBUF, BUFSIZE);
	ft_flush(env);
}

void			ft_flush(t_env *env)
{
	ft_strcat(FLUSHBUF, READBUF);
	ft_putstr_fd(FLUSHBUF, OUTFILE_FD);
	ft_bzero(FLUSHBUF, BUFSIZE);
	LAST_FLUSHTIME = get_time();
}

void			handle_flush(t_env *env)
{
	if (!OPT_T_VALUE)
		ft_flush(env);
	else if (ft_strlen(READBUF) > FLUSHBUF_REMAINING_SPACE)
		ft_fullfill_and_flush(env);
	else if (FLUSHTIME_EXCEEDED)
		ft_flush(env);
	else
		ft_strcat(FLUSHBUF, READBUF);
	ft_bzero(READBUF, BUFSIZE);
}

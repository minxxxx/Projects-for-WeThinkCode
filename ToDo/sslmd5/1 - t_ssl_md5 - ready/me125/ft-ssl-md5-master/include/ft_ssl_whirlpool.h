/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_whirlpool.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:38:20 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 09:38:21 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_WHIRLPOOL_H
# define FT_SSL_WHIRLPOOL_H
# include "../libft/include/libft.h"
# include <stdint.h>
# include <string.h>

/*
** ****************************************************************************
** ************************* MACROS for transform *****************************
** ****************************************************************************
*/

# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define WHIRLPOOL_DIGEST_SIZE 64
# define ROR64(a, n) (((a) >> (n)) | ((a) << (64 - (n))))

/*
** ****************************************************************************
** **************************** struct for data *******************************
** ****************************************************************************
*/

typedef	union	u_whh
{
	uint64_t	h[8];
	uint8_t		digest[64];
}				t_whh;

typedef	union	u_whx
{
	uint64_t	x[8];
	uint8_t		buffer[64];
}				t_whx;

typedef struct	s_wh
{
	union u_whh	h;
	union u_whx	x;
	uint64_t	k[8];
	uint64_t	l[8];
	uint64_t	state[8];

	size_t		size;
	uint64_t	totalsize;
	int			i;
	int			j;
}				t_wh;

/*
** ****************************************************************************
** ********************************* files ************************************
** ****************************************************************************
*/

void			whupdate(t_wh *twh, const void *data, size_t length);
void			whfinal(t_wh *twh, uint8_t *digest);
void			whstep(t_wh *twh, uint64_t *x, uint64_t *k, uint64_t *l);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:38:20 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 09:38:21 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H
# include "ft_ssl_des.h"
# include <string.h>
# define ULL unsigned long long

/*
** ****************************************************************************
** *************************** MACRO FOR TRNSFM *******************************
** ****************************************************************************
*/

# define F1(x, y, z) (z ^ (x & (y ^ z)))
# define F2(x, y, z) F1(z, x, y)
# define F3(x, y, z) (x ^ y ^ z)
# define F4(x, y, z) (y ^ (x | ~z))

/*
** ****************************************************************************
** **************************** struct for data *******************************
** ****************************************************************************
*/

typedef struct		s_md5
{
	ULL				buf[4];
	ULL				bits[2];
	unsigned char	in[64];
}					t_md5;

typedef struct		s_mds
{
	ULL				a;
	ULL				b;
	ULL				c;
	ULL				d;
	ULL				in[16];
	int				flag;
}					t_mds;

/*
** ****************************************************************************
** ********************************* files ************************************
** ****************************************************************************
*/

void				before_start_md(char *argv, t_md *data, int md);
void				md5init(t_md5 *md5data);
void				md5update(t_md5 *md5data, unsigned char *buf, unsigned len);
void				md5final(unsigned char digest[], t_md5 *md5data);
void				md5transform(ULL buf[], unsigned char in[]);
unsigned long long	getu32(unsigned char *addr);
void				putu32(ULL data, unsigned char *addr);
void				func1(t_mds *md, ULL val, int l);
void				func6(t_mds *md, ULL val, int l);

#endif

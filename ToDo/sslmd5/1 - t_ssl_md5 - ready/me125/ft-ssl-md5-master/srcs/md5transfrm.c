/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5transfrm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:07:36 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 10:07:37 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include "ft_ssl_md5.h"

void			func5(t_mds *md, ULL val, int l)
{
	if (md->flag == 13)
	{
		md->a += F4(md->b, md->c, md->d) + val;
		md->a &= 0xffffffff;
		md->a = md->a << l | md->a >> (32 - l);
		md->a += md->b;
	}
	else if (md->flag == 14)
	{
		md->d += F4(md->a, md->b, md->c) + val;
		md->d &= 0xffffffff;
		md->d = md->d << l | md->d >> (32 - l);
		md->d += md->a;
	}
	else if (md->flag == 15)
	{
		md->c += F4(md->d, md->a, md->b) + val;
		md->c &= 0xffffffff;
		md->c = md->c << l | md->c >> (32 - l);
		md->c += md->d;
	}
	else
		func6(md, val, l);
}

void			func4(t_mds *md, ULL val, int l)
{
	if (md->flag == 10)
	{
		md->d += F3(md->a, md->b, md->c) + val;
		md->d &= 0xffffffff;
		md->d = md->d << l | md->d >> (32 - l);
		md->d += md->a;
	}
	else if (md->flag == 11)
	{
		md->c += F3(md->d, md->a, md->b) + val;
		md->c &= 0xffffffff;
		md->c = md->c << l | md->c >> (32 - l);
		md->c += md->d;
	}
	else if (md->flag == 12)
	{
		md->b += F3(md->c, md->d, md->a) + val;
		md->b &= 0xffffffff;
		md->b = md->b << l | md->b >> (32 - l);
		md->b += md->c;
	}
	else
		func5(md, val, l);
}

void			func3(t_mds *md, ULL val, int l)
{
	if (md->flag == 7)
	{
		md->c += F2(md->d, md->a, md->b) + val;
		md->c &= 0xffffffff;
		md->c = md->c << l | md->c >> (32 - l);
		md->c += md->d;
	}
	else if (md->flag == 8)
	{
		md->b += F2(md->c, md->d, md->a) + val;
		md->b &= 0xffffffff;
		md->b = md->b << l | md->b >> (32 - l);
		md->b += md->c;
	}
	else if (md->flag == 9)
	{
		md->a += F3(md->b, md->c, md->d) + val;
		md->a &= 0xffffffff;
		md->a = md->a << l | md->a >> (32 - l);
		md->a += md->b;
	}
	else
		func4(md, val, l);
}

void			func2(t_mds *md, ULL val, int l)
{
	if (md->flag == 4)
	{
		md->b += F1(md->c, md->d, md->a) + val;
		md->b &= 0xffffffff;
		md->b = md->b << l | md->b >> (32 - l);
		md->b += md->c;
	}
	else if (md->flag == 5)
	{
		md->a += F2(md->b, md->c, md->d) + val;
		md->a &= 0xffffffff;
		md->a = md->a << l | md->a >> (32 - l);
		md->a += md->b;
	}
	else if (md->flag == 6)
	{
		md->d += F2(md->a, md->b, md->c) + val;
		md->d &= 0xffffffff;
		md->d = md->d << l | md->d >> (32 - l);
		md->d += md->a;
	}
	else
		func3(md, val, l);
}

void			func1(t_mds *md, ULL val, int l)
{
	if (md->flag == 1)
	{
		md->a += F1(md->b, md->c, md->d) + val;
		md->a &= 0xffffffff;
		md->a = md->a << l | md->a >> (32 - l);
		md->a += md->b;
	}
	else if (md->flag == 2)
	{
		md->d += F1(md->a, md->b, md->c) + val;
		md->d &= 0xffffffff;
		md->d = md->d << l | md->d >> (32 - l);
		md->d += md->a;
	}
	else if (md->flag == 3)
	{
		md->c += F1(md->d, md->a, md->b) + val;
		md->c &= 0xffffffff;
		md->c = md->c << l | md->c >> (32 - l);
		md->c += md->d;
	}
	else
		func2(md, val, l);
}

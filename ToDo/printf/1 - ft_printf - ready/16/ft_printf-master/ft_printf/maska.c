/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maska.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:37:10 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/24 16:37:13 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		maska1(unsigned int numb, int ret)
{
	unsigned int	maska1;
	unsigned char	ch;
	unsigned char	print;

	maska1 = 49280;
	ch = ((numb >> 6) << 27) >> 27;
	print = (maska1 >> 8) | ch;
	write(1, &print, 1);
	ch = (numb << 26) >> 26;
	print = (maska1 << 24) >> 24 | ch;
	write(1, &print, 1);
	ret += 2;
	return (ret);
}

int		maska2(unsigned int numb, int ret)
{
	unsigned int	maska2;
	unsigned char	ch;
	unsigned char	print;

	maska2 = 14712960;
	ch = ((numb >> 12) << 28) >> 28;
	print = (maska2 >> 16) | ch;
	write(1, &print, 1);
	ch = ((numb >> 6) << 26) >> 26;
	print = ((maska2 << 16) >> 24) | ch;
	write(1, &print, 1);
	ch = (numb << 26) >> 26;
	print = ((maska2 << 24) >> 24) | ch;
	write(1, &print, 1);
	ret += 3;
	return (ret);
}

int		maska3(unsigned int numb, int ret)
{
	unsigned int	maska3;
	unsigned char	ch;
	unsigned char	print;

	maska3 = 4034953344;
	ch = ((numb >> 18) << 29) >> 29;
	print = (maska3 >> 24) | ch;
	write(1, &print, 1);
	ch = ((numb >> 12) << 26) >> 26;
	print = ((maska3 << 8) >> 24) | ch;
	write(1, &print, 1);
	ch = ((numb >> 6) << 26) >> 26;
	print = ((maska3 << 16) >> 24) | ch;
	write(1, &print, 1);
	ch = ((numb << 26) >> 26);
	print = ((maska3 << 24) >> 24) | ch;
	write(1, &print, 1);
	ret += 4;
	return (ret);
}

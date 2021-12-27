/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_fghi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:42:49 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:32 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

uint	f_md5(uint b, uint c, uint d)
{
	return ((b & c) | ((~b) & d));
}

uint	g_md5(uint b, uint c, uint d)
{
	return ((b & d) | (c & (~d)));
}

uint	h_md5(uint b, uint c, uint d)
{
	return (b ^ c ^ d);
}

uint	i_md5(uint b, uint c, uint d)
{
	return (c ^ (b | (~d)));
}

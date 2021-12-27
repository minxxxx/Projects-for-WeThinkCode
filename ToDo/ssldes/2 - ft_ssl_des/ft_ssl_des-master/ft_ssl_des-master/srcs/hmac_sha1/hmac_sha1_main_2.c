/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_sha1_main_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:24 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:25 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

#define BLOCK_LEN 64

void			fill_ipad_opad(size_t keylen, char *k_ipad, char *k_opad,
	const unsigned char *key)
{
	size_t	i;

	i = 0;
	while (i < (BLOCK_LEN))
	{
		if (i < keylen)
		{
			k_ipad[i] = key[i] ^ 0x36;
			k_opad[i] = key[i] ^ 0x5c;
		}
		else
		{
			k_ipad[i] = 0 ^ 0x36;
			k_opad[i] = 0 ^ 0x5c;
		}
		i++;
	}
}

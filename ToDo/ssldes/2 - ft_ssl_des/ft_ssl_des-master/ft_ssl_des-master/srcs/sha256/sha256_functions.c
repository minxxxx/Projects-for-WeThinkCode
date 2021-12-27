/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:41:09 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:51 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

uint32_t	ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ ((~x) & z));
}

uint32_t	maj(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

uint32_t	gs0(uint32_t x)
{
	return (rotr(2, x) ^ rotr(13, x) ^ rotr(22, x));
}

uint32_t	gs1(uint32_t x)
{
	return (rotr(6, x) ^ rotr(11, x) ^ rotr(25, x));
}

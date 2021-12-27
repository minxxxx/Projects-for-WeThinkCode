/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:40:53 by rfibigr           #+#    #+#             */
/*   Updated: 2018/08/29 18:45:17 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_1_byte(t_buff *buff, wchar_t wc)
{
	unsigned char	c;

	c = (char)wc;
	add_buffer(buff, c);
}

void	write_2_bytes(t_buff *buff, wchar_t wc)
{
	unsigned char	tmp;
	unsigned char	c;

	tmp = 0b00011111 & (wc >> 6);
	c = tmp | 0b11000000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
}

void	write_3_bytes(t_buff *buff, wchar_t wc)
{
	unsigned char	tmp;
	unsigned char	c;

	tmp = 0b00001111 & (wc >> 12);
	c = tmp | 0b11100000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc >> 6);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
}

void	write_4_bytes(t_buff *buff, wchar_t wc)
{
	unsigned char	tmp;
	unsigned char	c;

	tmp = 0b00000111 & (wc >> 18);
	c = tmp | 0b11110000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc >> 12);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc >> 6);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
	tmp = 0b00111111 & (wc);
	c = tmp | 0b10000000;
	add_buffer(buff, c);
}

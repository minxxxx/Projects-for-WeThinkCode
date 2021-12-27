/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_headers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 05:40:38 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:21:04 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	print_header_padd(uint32_t num, int base, int size, uint8_t start)
{
	static char	*str = "0123456789abcdefg";

	if (base == 16 && start)
		ft_putstr("0x");
	if (num == 0 && base == 10 && !start)
		ft_putstr(" ");
	if (size > 0)
		print_header_padd(num / base, base, size - 1, 0);
	if (num == 0 && base == 10 && !start)
		return ;
	write(1, &str[num % base], 1);
}

void	rev_arch(t_fat_arch *arch)
{
	rev_bytes(&arch->cputype, 4);
	rev_bytes(&arch->cpusubtype, 4);
	rev_bytes(&arch->offset, 4);
	rev_bytes(&arch->size, 4);
	rev_bytes(&arch->align, 4);
}

void	print_arch(int cout, t_fat_arch *arch)
{
	ft_putstr("architecture ");
	ft_putendl(ft_itoa(cout));
	ft_putstr("    cputype ");
	ft_putendl(ft_itoa(arch->cputype));
	ft_putstr("    cpusubtype ");
	print_header_padd((arch->cpusubtype >> (8 * 0)) & 0xff +
			(((arch->cpusubtype >> (8 * 1)) & 0xff) << 8) +
			(((arch->cpusubtype >> (8 * 2)) & 0xff) << 16), 10, 2, 1);
	ft_putstr("\n    capabilities ");
	print_header_padd((arch->cpusubtype >> (8 * 3)) & 0xff, 16, 1, 1);
	ft_putstr("\n    offset ");
	ft_putendl(ft_itoa(arch->offset));
	ft_putstr("    size ");
	ft_putendl(ft_itoa(arch->size));
	ft_putstr("    align 2^");
	ft_putstr(ft_itoa(arch->align));
	ft_putstr(" (");
	ft_putstr(ft_itoa(arch->offset));
	ft_putendl(")");
}

void	my_print_fat_header(void *data, uint32_t off, uint8_t rev)
{
	t_fat_header	*h;
	t_fat_arch		*arh;
	uint32_t		i;

	h = (t_fat_header *)data;
	ft_putendl("Fat headers");
	ft_putstr("fat_magic 0x");
	if (rev)
		rev_bytes(&h->magic, 4);
	print_value(h->magic, 7);
	ft_putstr("\nnfat_arch ");
	ft_putendl(ft_itoa(h->nfat_arch));
	i = -1;
	off += sizeof(t_fat_header);
	while (++i < h->nfat_arch)
	{
		arh = (t_fat_arch *)(data + off);
		if (rev)
			rev_arch(arh);
		print_arch(i, arh);
		off += sizeof(t_fat_arch);
	}
}

void	my_print_mach_header(t_mach_header *h, uint8_t is_rev)
{
	(void)is_rev;
	ft_putendl("Mach header");
	ft_putendl("      magic  cputype  cpusubtype   caps  "
			" filetype  ncmds  sizeofcmds       flags");
	print_header_padd(h->magic, 16, 7, 1);
	ft_putstr("  ");
	print_header_padd(h->cputype, 10, 7, 1);
	ft_putstr("  ");
	print_header_padd((h->cpusubtype >> (8 * 0)) & 0xff +
			(((h->cpusubtype >> (8 * 1)) & 0xff) << 8) +
			(((h->cpusubtype >> (8 * 2)) & 0xff) << 16), 10, 9, 1);
	ft_putstr(" ");
	print_header_padd((h->cpusubtype >> (8 * 3)) & 0xff, 16, 1, 1);
	ft_putstr("    ");
	print_header_padd(h->filetype, 10, 7, 1);
	ft_putstr("  ");
	print_header_padd(h->ncmds, 10, 5, 1);
	ft_putstr("  ");
	print_header_padd(h->sizeofcmds, 10, 9, 1);
	ft_putstr("  ");
	print_header_padd(h->flags, 16, 7, 1);
	ft_putstr("\n");
}

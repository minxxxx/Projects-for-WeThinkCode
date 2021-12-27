/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 02:54:51 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:18:27 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "file.h"

int		get_otool_flags(int ac, char **av, t_otool_flags *flags);
int		get_otool_files(int ac, char **av, t_otool_flags *flags);
void	process_otool_file(t_file *file, t_otool_flags *flags, uint32_t off);
void	print_otool_sec_head(t_otool_flags *flags);

void	otool_section_64(t_mach_file *m, char *sec, char *seg, uint32_t off);
void	otool_section_32(t_mach_file *m, char *sec, char *seg, uint32_t off);
void	my_print_mach_header(t_mach_header *h, uint8_t is_rev);
void	my_print_fat_header(void *data, uint32_t off, uint8_t rev);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 15:01:55 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:05:13 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_MACH_H
# define NM_MACH_H

# include "file.h"

void	mach_symbol_table(t_mach_file *mach);
void	print_mach_header(t_mach_header *header);
void	process_syms(t_mach_file *mach, t_sym *syms, size_t size);
void	print_value(uint32_t value, int size);
void	print_value_64(uint64_t value, int size);
void	rev_mach_cmds(t_mach_file *mach, t_file *file, size_t off);
void	rev_symtab(t_mach_sym *tab);

int		mach_name_sort(t_sym *a, t_sym *b);
int		mach_value_sort(t_sym *a, t_sym *b);
void	mach_reverse_table(t_sym *tab, size_t size);
void	mach_sort_symbols(t_sym *syms, size_t size, int (*f)(t_sym *,
			t_sym *));

#endif

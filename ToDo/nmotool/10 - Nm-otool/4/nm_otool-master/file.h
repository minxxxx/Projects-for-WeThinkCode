/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:02:19 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 13:55:58 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include "libft.h"
# include "structs.h"

# define MH_MAGIC 		0xfeedface
# define MH_CIGAM		0xcefaedfe
# define MH_MAGIC_64 	0xfeedfacf
# define MH_CIGAM_64 	0xcffaedfe
# define FAT_MAGIC   	0xcafebabe
# define FAT_CIGAM   	0xbebafeca
# define ELF_MAGIC		0x7f454c46
# define ELF_CIGAM		0x464c457f
# define ARH_MAGIC		0x0a3e686372613c21
# define ARCH_CIGAM		0x213c617263683e0a

# define MH_SEG			0x01
# define MH_SYMTAB		0x02
# define MH_SEG_64		0x19
# define N_STAB			0xe0
# define N_PEXT			0x10
# define N_TYPE			0x0e
# define N_EXT			0x01

void		ft_print_nbr_base(long int nbr, int base);
int			open_file(t_file *file, char *filename);
size_t		my_read(void *dst, size_t size, size_t offset, void *src);
char		ft_get_type(char *segname, char *sectname, uint8_t is_global);
void		my_print_memory(void *src, size_t size);

#endif

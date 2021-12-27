/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:38:12 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:45:50 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# ifdef __x86_64__
#  define CPUTYPE CPU_TYPE_X86_64
# endif
# ifdef __i386__
#  define CPUTYPE CPU_TYPE_I386
# endif

# include <stdio.h>
# include <ft_printf.h>
# include <stdio.h>
# include <ft_printf.h>
# include <libbinary.h>
# include <libft.h>
# include <ar.h>

typedef struct	s_data
{
	void		*binary;
	uint32_t	magic;
	uint32_t	stroff;
	uint32_t	strsize;
	uint32_t	symoff;
	uint32_t	nsyms;
	char		*sections;
	uint32_t	nbsect;
	void		*tend;
	uint32_t	end;
	off_t		size;
	const char	*av;
	int			endiancast;
	int			error;
}				t_data;

void			handle_64(t_data *data, uint64_t offset);
void			handle_32(t_data *data, uint64_t offset);
void			print(t_data *data, void *start, uint64_t size,
		uint64_t print_size);
void			handle_fat(t_data *data);
void			handle_static_lib(t_data *data, uint32_t offset);
int64_t			get_good_endian(t_data data, int64_t nbr);
int				get_good_endianu(t_data data, uint64_t nbr);
void			set_error_and_return(t_data *data);
void			fat_fln(size_t *i, struct fat_header **header,
	void *data_cigam);
void			init_sl(uint32_t *min, uint32_t *max, struct ranlib **start,
	struct ranlib *symtab);
#endif

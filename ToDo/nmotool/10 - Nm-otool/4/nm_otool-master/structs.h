/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:02:28 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:39:20 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_file
{
	int				fd;
	uint8_t			is_valid;
	uint8_t			is_archive;
	uint8_t			is_small_endian;
	uint32_t		file_magic;
	uint64_t		archive_magic;
	unsigned int	size;
	void			*data;
}					t_file;

typedef struct		s_mach_header
{
	uint32_t		magic;
	uint32_t		cputype;
	uint32_t		cpusubtype;
	uint32_t		filetype;
	uint32_t		ncmds;
	uint32_t		sizeofcmds;
	uint32_t		flags;
}					t_mach_header;

typedef struct		s_mach_sym
{
	uint32_t		cmdtype;
	uint32_t		cmdsize;
	uint32_t		symoff;
	uint32_t		nsyms;
	uint32_t		stroff;
	uint32_t		strsize;
}					t_mach_sym;

typedef struct		s_flags
{
	uint8_t			print_file_name;
	uint8_t			global_only;
	uint8_t			undef_only;
	uint8_t			addr_sort;
	uint8_t			no_sort;
	uint8_t			rev_sort;
	char			*file_name;
}					t_flags;

typedef struct		s_otool_flags
{
	uint8_t			text_sec;
	uint8_t			data_sec;
	uint8_t			fat_head;
	uint8_t			arch_head;
	uint8_t			mach_head;
	char			*file_name;
}					t_otool_flags;

typedef struct		s_mach_file
{
	void			*file_data;
	void			*mach_data;
	void			*cmd_data;
	uint8_t			is_rev;
	uint8_t			is_64;
	uint32_t		magic;
	t_mach_header	*header;
	t_mach_sym		*sym_tab;
	t_flags			*flags;
}					t_mach_file;

typedef struct		s_nlist
{
	uint32_t		str_index;
	uint8_t			n_type;
	uint8_t			n_sect;
	uint16_t		n_desc;
	uint32_t		n_value;
}					t_nlist;

typedef struct		s_fat_header
{
	uint32_t		magic;
	uint32_t		nfat_arch;
}					t_fat_header;

typedef struct		s_fat_arch
{
	uint32_t		cputype;
	uint32_t		cpusubtype;
	uint32_t		offset;
	uint32_t		size;
	uint32_t		align;
}					t_fat_arch;

typedef struct		s_sym
{
	t_nlist			*nlist;
	char			*name;
	char			type;
}					t_sym;

typedef struct		s_mach_cmd
{
	uint32_t		cmd;
	uint32_t		cmdsize;
	char			segname[16];
	uint32_t		vmaddr;
	uint32_t		vmsize;
	uint32_t		fileoff;
	uint32_t		filesize;
	uint32_t		maxprot;
	uint32_t		initprot;
	uint32_t		nsects;
	uint32_t		flags;
}					t_mach_cmd;

typedef struct		s_mach_cmd_64
{
	uint32_t		cmd;
	uint32_t		cmdsize;
	char			segname[16];
	uint64_t		vmaddr;
	uint64_t		vmsize;
	uint64_t		fileoff;
	uint64_t		filesize;
	uint32_t		maxprot;
	uint32_t		initprot;
	uint32_t		nsects;
	uint32_t		flags;
}					t_mach_cmd_64;

typedef struct		s_section
{
	char			sectname[16];
	char			segname[16];
	uint32_t		addr;
	uint32_t		size;
	uint32_t		offset;
	uint32_t		align;
	uint32_t		reloff;
	uint32_t		nreloc;
	uint32_t		flags;
	uint32_t		reserved1;
	uint32_t		reserved2;
}					t_mach_section;

typedef struct		s_section_64 {
	char			sectname[16];
	char			segname[16];
	uint64_t		addr;
	uint64_t		size;
	uint32_t		offset;
	uint32_t		align;
	uint32_t		reloff;
	uint32_t		nreloc;
	uint32_t		flags;
	uint32_t		reserved1;
	uint32_t		reserved2;
	uint32_t		reserved3;
}					t_mach_section_64;

typedef struct		s_arch_header
{
	char			file_iden[16];
	char			file_mod[12];
	char			owner[6];
	char			group[6];
	char			file_mode[8];
	char			file_size[10];
	char			end[2];
}					t_arch_header;

uint8_t				is_reverse_endian(uint32_t magic_num);
uint8_t				is_64_bit(uint32_t magic_num);
uint8_t				is_mach_o_file(uint32_t magic_num);
void				rev_bytes(void *data, size_t size);

#endif

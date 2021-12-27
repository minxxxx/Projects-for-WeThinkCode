/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:36:42 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:24:36 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

static void	print_head(cpu_type_t cputype, const char *filename)
{
	if (cputype == CPU_TYPE_I386)
		ft_printf("%s (architecture i386):\n", filename);
	if (cputype == CPU_TYPE_X86_64)
		ft_printf("%s (architecture X86_64):\n", filename);
	if (cputype == CPU_TYPE_POWERPC)
		ft_printf("%s (architecture ppc):\n", filename);
}

static void	handle_fat_arch_32(t_data *data, struct fat_arch *arch, int p)
{
	if (ft_strnequ((char*)data->binary + arch->offset, ARMAG, SARMAG))
	{
		data->end = arch->offset + arch->size;
		ft_printf("Archive : %s\n", data->av);
		handle_static_lib(data, arch->offset);
	}
	else
	{
		if (p)
			ft_printf("%s:\n", data->av);
		handle_32(data, arch->offset);
	}
}

static void	handle_fat_arch(t_data *data, struct fat_arch *arch, int p)
{
	if (arch->offset > data->size)
		return (set_error_and_return(data));
	data->magic = *(uint32_t*)(data->binary + arch->offset);
	if (arch->cputype == CPU_TYPE_I386)
		handle_fat_arch_32(data, arch, p);
	else if (arch->cputype == CPU_TYPE_X86_64)
	{
		if (ft_strnequ((char*)data->binary + arch->offset, ARMAG, SARMAG))
		{
			data->end = arch->offset + arch->size;
			ft_printf("Archive : %s\n", data->av);
			handle_static_lib(data, arch->offset);
		}
		else
		{
			p ? ft_printf("%s:\n", data->av) : 0;
			handle_64(data, arch->offset);
		}
	}
	else if (arch->cputype == CPU_TYPE_POWERPC)
	{
		p ? ft_printf("%s:\n", data->av) : 0;
		data->endiancast = 1;
		handle_32(data, arch->offset);
	}
}

static int	print_all_arches(t_data *data, size_t nbr, void *data_cigam)
{
	size_t			i;
	struct fat_arch	*arch;

	i = 0;
	while (i < nbr)
	{
		arch = (struct fat_arch*)data_cigam + i;
		print_head(arch->cputype, data->av);
		data->endiancast = 0;
		handle_fat_arch(data, arch, 0);
		if (data->error)
			return (0);
		i++;
	}
	return (1);
}

void		handle_fat(t_data *data)
{
	void				*data_cigam;
	struct fat_header	*header;
	struct fat_arch		*arch;
	size_t				i;
	size_t				nbr;

	data_cigam = convert_chunk_alloc(data->binary, sizeof(struct fat_header));
	fat_fln(&i, &header, data_cigam);
	nbr = header->nfat_arch;
	free(data_cigam);
	data_cigam = convert_chunk_alloc(data->binary + sizeof(struct fat_header),
			nbr * sizeof(struct fat_arch));
	while (i < nbr)
	{
		arch = (struct fat_arch*)data_cigam + i;
		if ((void*)arch > data_cigam + data->size)
			return (set_error_and_return(data));
		if (arch->cputype == CPUTYPE)
		{
			handle_fat_arch(data, arch, 1);
			return (free(data_cigam));
		}
		i++;
	}
	print_all_arches(data, nbr, data_cigam);
}

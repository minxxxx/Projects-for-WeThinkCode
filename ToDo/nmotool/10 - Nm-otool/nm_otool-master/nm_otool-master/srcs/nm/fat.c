/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:35:52 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 14:16:58 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void	print_head(cpu_type_t cputype, const char *filename)
{
	if (cputype == CPU_TYPE_I386)
		ft_printf("\n%s (for architecture i386):\n", filename);
	if (cputype == CPU_TYPE_X86_64)
		ft_printf("\n%s (for architecture X86_64):\n", filename);
	if (cputype == CPU_TYPE_POWERPC)
		ft_printf("\n%s (for architecture ppc):\n", filename);
}

int		print_arches(t_data *data, t_opt opt, size_t nbr, void *data_cigam)
{
	size_t			i;
	struct fat_arch	*arch;

	i = 0;
	while (i < nbr)
	{
		arch = (struct fat_arch*)data_cigam + i;
		if ((void*)arch > data_cigam + data->size)
			return (0);
		if (arch->cputype == CPU_TYPE_I386 || arch->cputype == CPU_TYPE_X86_64
				|| arch->cputype == CPU_TYPE_POWERPC)
		{
			print_head(arch->cputype, data->av);
			data->endiancast = 0;
			handle_fat_arch(data, arch, i, opt);
			if (data->error)
				return (0);
			print_list(data, data->list, opt);
			delete_list(data->list);
			data->list = NULL;
		}
		i++;
	}
	return (1);
}

void	print_all_arches(t_data *data, t_opt opt, size_t nbr)
{
	void	*data_cigam;

	if (data->binary + sizeof(struct fat_header) > data->tend)
	{
		data->error = 1;
		return ;
	}
	data_cigam = convert_chunk_alloc(data->binary + sizeof(struct fat_header),
			nbr * sizeof(struct fat_arch));
	if (print_arches(data, opt, nbr, data_cigam) == 0)
	{
		data->error = 1;
		free(data_cigam);
		return ;
	}
	free(data_cigam);
}

int		find_good_arch(t_data *data, t_opt opt, void *data_cigam, size_t nbr)
{
	size_t				i;
	struct fat_arch		*arch;

	i = 0;
	while (i < nbr)
	{
		arch = (struct fat_arch*)data_cigam + i;
		if ((void*)arch > data_cigam + data->size)
		{
			data->error = 1;
			return (1);
		}
		if (arch->cputype == CPUTYPE)
		{
			if (!handle_fat_arch(data, arch, i, opt))
				data->error = 1;
			free(data_cigam);
			return (1);
		}
		i++;
	}
	return (0);
}

void	handle_fat_cigam(t_data *data, t_opt opt)
{
	void				*data_cigam;
	struct fat_header	*header;
	size_t				nbr;

	data_cigam = convert_chunk_alloc(data->binary, sizeof(struct fat_header));
	header = (struct fat_header*)data_cigam;
	nbr = header->nfat_arch;
	free(data_cigam);
	data_cigam = convert_chunk_alloc(data->binary + sizeof(struct fat_header),
			nbr * sizeof(struct fat_arch));
	if (find_good_arch(data, opt, data_cigam, nbr))
		return ;
	print_all_arches(data, opt, nbr);
}

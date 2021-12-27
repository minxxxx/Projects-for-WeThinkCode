/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 02:54:02 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 13:47:56 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	single_flags_t(char *str, t_otool_flags *flags, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		if (str[i] == 'a')
			flags->arch_head = 1;
		else if (str[i] == 'f')
			flags->fat_head = 1;
		else if (str[i] == 'h')
			flags->mach_head = 1;
		else if (str[i] == 't')
			flags->text_sec = 1;
		else if (str[i] == 'd')
			flags->data_sec = 1;
	}
}

int		did_get_flag(t_otool_flags *flags)
{
	if (flags->arch_head)
		return (1);
	if (flags->fat_head)
		return (1);
	if (flags->mach_head)
		return (1);
	if (flags->data_sec)
		return (1);
	if (flags->text_sec)
		return (1);
	return (0);
}

int		get_otool_flags(int ac, char **av, t_otool_flags *flags)
{
	int		i;

	i = 0;
	flags->arch_head = 0;
	flags->data_sec = 0;
	flags->fat_head = 0;
	flags->mach_head = 0;
	flags->text_sec = 0;
	flags->file_name = NULL;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			single_flags_t(av[i], flags, ft_strlen(av[i]));
	}
	return (did_get_flag(flags));
}

int		get_otool_files(int ac, char **av, t_otool_flags *flags)
{
	int		i;
	int		ret;
	t_file	file;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-')
		{
			flags->file_name = av[i];
			ret = open_file(&file, av[i]);
			if (ret == 0 && file.is_valid)
				process_otool_file(&file, flags, 0);
			else
				error_file("ft_otool", ret, av[i]);
		}
	}
	if (flags->file_name == NULL)
		return (0);
	return (1);
}

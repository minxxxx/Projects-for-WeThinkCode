/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 06:35:50 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 13:46:21 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	single_flags(char *str, t_flags *flags)
{
	size_t		i;

	i = -1;
	while (++i < ft_strlen(str))
	{
		if (str[i] == 'A' || str[i] == 'o')
			flags->print_file_name = 1;
		else if (str[i] == 'g')
			flags->global_only = 1;
		else if (str[i] == 'n' || str[i] == 'v')
			flags->addr_sort = 1;
		else if (str[i] == 'p')
			flags->no_sort = 1;
		else if (str[i] == 'r')
			flags->rev_sort = 1;
		else if (str[i] == 'u')
			flags->undef_only = 1;
	}
}

void	word_flags(char *str, t_flags *flags)
{
	if (!ft_strcmp(str, "--print-file-name"))
		flags->print_file_name = 1;
	else if (!ft_strcmp(str, "--extern-only"))
		flags->global_only = 1;
	else if (!ft_strcmp(str, "--numeric-sort"))
		flags->addr_sort = 1;
	else if (!ft_strcmp(str, "--no-sort"))
		flags->no_sort = 1;
	else if (!ft_strcmp(str, "--reverse-sort"))
		flags->rev_sort = 1;
	else if (!ft_strcmp(str, "--undefined-only"))
		flags->undef_only = 1;
}

void	get_flags(int ac, char **av, t_flags *flags)
{
	int		i;

	i = 0;
	flags->print_file_name = 0;
	flags->global_only = 0;
	flags->undef_only = 0;
	flags->addr_sort = 0;
	flags->no_sort = 0;
	flags->rev_sort = 0;
	flags->file_name = NULL;
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] != '\0' && av[i][1] != '-')
			single_flags(&av[i][1], flags);
		else if (av[i][0] == '-' && av[i][1] != '\0' && av[i][1] == '-')
			word_flags(av[i], flags);
	}
}

void	error_file(char *prog, int ret, char *file_name)
{
	ft_putstr(prog);
	ft_putstr(": ");
	ft_putstr(file_name);
	if (ret == -1)
		ft_putendl(": No such file or directory");
	else if (ret == 1)
		ft_putendl(": Error reading file or directory");
	else
		ft_putendl(": The file was not recognized as a valid object file");
}

int		get_files(int ac, char **av, t_flags *flags)
{
	int			i;
	int			multiple;
	int			ret;
	t_file		file;

	i = 0;
	multiple = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-')
		{
			multiple = (i + 1 < ac) ? 1 : multiple;
			flags->file_name = av[i];
			ret = open_file(&file, av[i]);
			if (ret == 0 && file.is_valid)
				process_file(&file, flags, 0, multiple);
			else
				error_file("ft_nm", ret, av[i]);
		}
	}
	if (flags->file_name == NULL)
		return (0);
	return (1);
}

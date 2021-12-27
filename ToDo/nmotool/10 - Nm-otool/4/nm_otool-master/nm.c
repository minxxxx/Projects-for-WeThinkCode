/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:03:30 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:16:33 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	ft_nm(int ac, char **av)
{
	t_flags		flags;
	t_file		file;
	int			ret;

	get_flags(ac, av, &flags);
	if (!get_files(ac, av, &flags))
	{
		ret = open_file(&file, "a.out");
		if (ret == 0 && file.is_valid)
			process_file(&file, &flags, 0, 0);
		else
			error_file("ft_nm", ret, "a.out");
	}
}

void	otool_usgae_error(void)
{
	ft_putendl("error: usage: ./ft_otool [-flags] <object file>");
	ft_putendl("     -f print the fat headers");
	ft_putendl("     -a print the archive header");
	ft_putendl("     -h print the mach header");
	ft_putendl("     -t print the text section");
	ft_putendl("     -d print the data section");
}

void	ft_otool(int ac, char **av)
{
	t_otool_flags	flags;

	if (!get_otool_flags(ac, av, &flags))
	{
		otool_usgae_error();
		return ;
	}
	if (!get_otool_files(ac, av, &flags))
	{
		otool_usgae_error();
		return ;
	}
}

int		main(int ac, char **av)
{
	if (!ft_strcmp(&av[0][2], "ft_nm"))
		ft_nm(ac, av);
	else if (!ft_strcmp(&av[0][2], "ft_otool"))
		ft_otool(ac, av);
	return (0);
}

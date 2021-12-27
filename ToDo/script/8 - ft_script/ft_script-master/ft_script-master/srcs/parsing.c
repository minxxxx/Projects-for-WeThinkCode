/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:44:38 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:44:42 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

static void	apply_simple_option(char option, t_opt *opt)
{
	if (option == 'a')
		opt->open_flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		opt->options |= (get_bit_for_option(option));
}

static int	apply_parametrized_option(t_m_args *m_args, int *i,
	t_opt *opt, int j)
{
	if (m_args->av[*i][j + 1] != '\0')
		opt->flush_interval = ft_atoi(m_args->av[*i] + j + 1);
	else if (m_args->av[*i + 1] == NULL)
	{
		ft_putstr_fd("Option requires an argument: ", 2);
		ft_putchar_fd(m_args->av[*i][j], 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	else
	{
		(*i)++;
		opt->flush_interval = ft_atoi(m_args->av[*i]);
	}
	if (opt->flush_interval < 0)
	{
		ft_putstr_fd("Invalid flush time.", 2);
		return (0);
	}
	return (1);
}

static int	parse_argument(t_m_args *m_args, int *i, t_opt *opt)
{
	int	j;

	j = 1;
	while (m_args->av[*i][j])
	{
		if (!is_option(m_args->av[*i][j]))
		{
			ft_putstr_fd("Illegal option: ", 2);
			ft_putchar_fd(m_args->av[*i][j], 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
		if (is_parametrized_option(m_args->av[*i][j]))
			return (apply_parametrized_option(m_args, i, opt, j));
		else
			apply_simple_option(m_args->av[*i][j], opt);
		j++;
	}
	return (1);
}

static int	finish_parsing(t_m_args *m_args, int i, t_opt *opt)
{
	if (m_args->av[i] == NULL)
		return (1);
	else
		opt->output_file = m_args->av[i];
	i++;
	if (m_args->av[i])
		opt->argv = m_args->av + i;
	return (1);
}

int			parse(int ac, char **av, char **envp, t_opt *opt)
{
	int	i;

	init_opt(opt, ac, av, envp);
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (ft_strequ(av[i], "--"))
				return (finish_parsing(&(opt->default_args), i + 1, opt));
			else
			{
				if (!parse_argument(&(opt->default_args), &i, opt))
					return (0);
			}
		}
		else
			return (finish_parsing(&(opt->default_args), i, opt));
		i++;
	}
	return (1);
}

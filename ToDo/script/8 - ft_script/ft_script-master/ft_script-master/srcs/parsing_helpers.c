/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:43:34 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:43:35 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

int8_t	is_option(char c)
{
	if (c == 'a' || c == 'd' || c == 'F' || c == 'k' || c == 'p' || c == 'q'
		|| c == 'r' || c == 't')
		return (1);
	return (0);
}

int8_t	is_parametrized_option(char c)
{
	if (c == 't')
		return (1);
	return (0);
}

int		get_bit_for_option(char c)
{
	if (c == 'd')
		return (D_OPT);
	if (c == 'F')
		return (F_OPT);
	if (c == 'k')
		return (K_OPT);
	if (c == 'p')
		return (P_OPT);
	if (c == 'q')
		return (Q_OPT);
	if (c == 'r')
		return (R_OPT);
	return (0);
}

void	init_opt(t_opt *opt, int ac, char **av, char **envp)
{
	opt->options = 0;
	opt->output_file = "typescript";
	opt->open_flags = O_WRONLY | O_CREAT | O_TRUNC;
	opt->flush_interval = 30;
	opt->argv = NULL;
	ft_memcpy(&opt->default_args, &(t_m_args){ac, av, envp},
		sizeof(opt->default_args));
}

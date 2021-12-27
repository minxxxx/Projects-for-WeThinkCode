/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_set_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:41 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:42 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int			set_opt_flags(char option, t_opt *opt)
{
	if ((option >= 'p' && option <= 's') || option == 'e' || option == 'd'
		|| option == 'i' || option == 'o' || option == 'v'
		|| option == 'a' || option == 'k')
	{
		if (option >= 'p' && option <= 's')
			opt->flags |= 1 << (option - 'p');
		else if (option == 'd')
			opt->flags |= D_OPT;
		else if (option == 'e')
			opt->flags |= E_OPT;
		else if (option == 'i')
			opt->flags |= I_OPT;
		else if (option == 'o')
			opt->flags |= O_OPT;
		else if (option == 'v')
			opt->flags |= V_OPT;
		else if (option == 'a')
			opt->flags |= A_OPT;
		else if (option == 'k')
			opt->flags |= K_OPT;
		return (1);
	}
	return (print_str_and_ret("Illegal option: ", option));
}

static int	set_opt_skv(t_opt *opt, int (*fun) (t_opt*), char *option, int i)
{
	if (opt->flags & S_OPT && opt->s_option == NULL && has_argument('s', fun))
	{
		opt->s_option = option[i + 1] == '\0' ? NULL : option + i + 1;
		return (1);
	}
	if (opt->flags & K_OPT && opt->k_option == NULL && has_argument('k', fun))
	{
		opt->k_option = option[i + 1] == '\0' ? NULL : option + i + 1;
		return (1);
	}
	if (opt->flags & V_OPT && opt->v_option == NULL && has_argument('v', fun))
	{
		opt->v_option = option[i + 1] == '\0' ? NULL : option + i + 1;
		return (1);
	}
	return (0);
}

int			set_opt_contents(t_opt *opt, int (*fun) (t_opt*),
	char *option, int i)
{
	if (opt->flags & I_OPT && opt->i_option == NULL && has_argument('i', fun))
	{
		opt->i_option = option[i + 1] == '\0' ? NULL : option + i + 1;
		return (1);
	}
	if (opt->flags & O_OPT && opt->o_option == NULL && has_argument('o', fun))
	{
		opt->o_option = option[i + 1] == '\0' ? NULL : option + i + 1;
		return (1);
	}
	if (opt->flags & P_OPT && opt->p_option == NULL && has_argument('p', fun))
	{
		opt->p_option = option[i + 1] == '\0' ? NULL : option + i + 1;
		return (1);
	}
	return (set_opt_skv(opt, fun, option, i));
}

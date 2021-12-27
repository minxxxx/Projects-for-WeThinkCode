/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parametrized_opt.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:38 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:38 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static int	handle_s_opt(t_opt *opt, int (*fun)(t_opt*), char **av, int *i)
{
	if (!opt->content)
	{
		if (!av[*i + 1])
			return (0);
		opt->content = av[*i + 1];
		(*i)++;
	}
	fun(opt);
	opt->flags &= ~S_OPT;
	return (1);
}

static int	handle_i_o_p(t_opt *opt, char *str, int *i)
{
	if ((opt->flags & I_OPT) && opt->i_option == NULL)
	{
		if (!str)
			return (0);
		opt->i_option = str;
		(*i)++;
	}
	else if ((opt->flags & O_OPT) && opt->o_option == NULL)
	{
		if (!str)
			return (0);
		opt->o_option = str;
		(*i)++;
	}
	else if ((opt->flags & P_OPT) && opt->p_option == NULL)
	{
		if (!str)
			return (0);
		opt->p_option = str;
		(*i)++;
	}
	return (1);
}

static int	handle_k_v(t_opt *opt, char *str, int *i)
{
	if ((opt->flags & K_OPT) && opt->k_option == NULL)
	{
		if (!str)
			return (0);
		opt->k_option = str;
		(*i)++;
	}
	else if ((opt->flags & V_OPT) && opt->v_option == NULL)
	{
		if (!str)
			return (0);
		opt->v_option = str;
		(*i)++;
	}
	return (1);
}

int			handle_parametrized_opt(char **av, int *i, t_opt *opt,
	int (*fun)(t_opt*))
{
	char *str;

	str = av[*i + 1];
	if (!handle_i_o_p(opt, str, i))
		return (0);
	else if (!handle_k_v(opt, str, i))
		return (0);
	else if ((opt->flags & S_OPT))
	{
		if (fun == main_md5 || fun == main_256)
			return (handle_s_opt(opt, fun, av, i));
		if (has_argument('s', fun) && opt->s_option == NULL)
		{
			if (!str)
				return (0);
			opt->s_option = str;
			(*i)++;
		}
	}
	return (1);
}

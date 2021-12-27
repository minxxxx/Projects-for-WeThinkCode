/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:36 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:37 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int				has_argument(char c, int (*fun) (t_opt*))
{
	if (fun == main_des_ecb || fun == main_des_cbc)
	{
		if (c == 'i' || c == 'k' || c == 'o' || c == 'p' || c == 's'
			|| c == 'v')
			return (1);
		else
			return (0);
	}
	else if (fun == main_sha1)
	{
		if (c == 'i' || c == 'o')
			return (1);
		else
			return (0);
	}
	else if (fun == main_hmac_sha1)
	{
		if (c == 'i' || c == 'o' || c == 'k')
			return (1);
		else
			return (0);
	}
	else if (c == 's' || c == 'i' || c == 'o')
		return (1);
	return (0);
}

static int		get_option(char *option, t_opt *opt, int (*fun) (t_opt*))
{
	int	i;

	i = 1;
	while (option[i])
	{
		if (!set_opt_flags(option[i], opt))
			return (0);
		if (opt->flags & S_OPT && (fun == main_md5 || fun == main_256))
		{
			opt->content = option[i + 1] == '\0' ? NULL : option + i + 1;
			return (1);
		}
		if (opt->flags & P_OPT && !has_argument('p', fun))
		{
			opt->content = NULL;
			fun(opt);
			opt->flags &= ~P_OPT;
		}
		if (set_opt_contents(opt, fun, option, i))
			return (1);
		i++;
	}
	return (1);
}

static int8_t	handle_opts(char **av, t_opt *opt, int (*fun) (t_opt*))
{
	int	i;
	int	ignore;

	i = 2;
	ignore = 0;
	while (av[i])
	{
		if (av[i][0] == '-' && !ignore)
		{
			if (!get_option(av[i], opt, fun))
				return (0);
			if (!handle_parametrized_opt(av, &i, opt, fun))
				return (0);
		}
		else if (fun == main_256 || fun == main_md5)
		{
			opt->content = av[i];
			fun(opt);
			ignore = 1;
		}
		else
			opt->content = av[i];
		i++;
	}
	return (1);
}

static int		do_parsing(char **av, t_opt *opt, int (*fun) (t_opt*))
{
	if (!handle_opts(av, opt, fun))
		return (0);
	if ((fun == main_256 || fun == main_md5) && opt->content == NULL
		&& !(av[2] && !av[3] && ft_strequ("-p", av[2])))
		fun(opt);
	else if (fun != main_256 && fun != main_md5)
		fun(opt);
	return (1);
}

int				parse_options(int ac, char **av, t_opt *opt)
{
	int (*fun) (t_opt*);

	if (ac < 2)
		return (0);
	ft_bzero(opt, sizeof(t_opt));
	if (ft_strequ(av[1], "md5"))
		fun = main_md5;
	else if (ft_strequ(av[1], "sha256"))
		fun = main_256;
	else if (ft_strequ(av[1], "base64"))
		fun = main_base64;
	else if (ft_strequ(av[1], "des-ecb"))
		fun = main_des_ecb;
	else if (ft_strequ(av[1], "des") || ft_strequ(av[1], "des-cbc"))
		fun = main_des_cbc;
	else if (ft_strequ(av[1], "sha1"))
		fun = main_sha1;
	else if (ft_strequ(av[1], "hmac-sha1"))
		fun = main_hmac_sha1;
	else
		return (print_error_and_help(av[1]));
	if (!do_parsing(av, opt, fun))
		return (0);
	return (1);
}

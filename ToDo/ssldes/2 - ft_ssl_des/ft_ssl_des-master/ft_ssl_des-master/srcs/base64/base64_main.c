/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:30:55 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:30:56 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static int	handle_i_opt(t_opt *opt, int *in_fd)
{
	if ((*in_fd = open(opt->i_option, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Couldn't open file ", 2);
		ft_putstr_fd(opt->i_option, 2);
		ft_putstr_fd(" for reading.\n", 2);
		return (0);
	}
	return (1);
}

static int	b64_handle_o_opt(t_opt *opt, int *out_fd)
{
	if ((*out_fd = open(opt->o_option, O_WRONLY | O_CREAT, 0666)) == -1)
	{
		ft_putstr_fd("Couldn't open file ", 2);
		ft_putstr_fd(opt->o_option, 2);
		ft_putstr_fd(" for writing.\n", 2);
		return (0);
	}
	return (1);
}

int			main_base64(t_opt *opt)
{
	int	in_fd;
	int	out_fd;

	if (opt->flags & D_OPT && opt->flags & E_OPT)
	{
		ft_putstr_fd("Error : You must specify one of", 2);
		ft_putstr_fd(" -d (decode) and -e (encode).\n", 2);
		return (0);
	}
	if (!(opt->flags & D_OPT) && !(opt->flags & E_OPT))
		opt->flags |= E_OPT;
	in_fd = 0;
	out_fd = 1;
	if (opt->flags & I_OPT)
		if (!handle_i_opt(opt, &in_fd))
			return (0);
	if (opt->flags & O_OPT)
		if (!b64_handle_o_opt(opt, &out_fd))
			return (0);
	if (opt->flags & E_OPT)
		base64_encode_from_fd(in_fd, out_fd);
	else if (opt->flags & D_OPT)
		base64_decode_from_fd(in_fd, out_fd);
	return (1);
}

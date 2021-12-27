/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:13 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:14 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int	handle_v_e_d_opt(t_des *des, t_opt *opt)
{
	if (opt->flags & V_OPT)
	{
		if (!opt->v_option || !hex_string_to_bytes(opt->v_option, des->iv, 8))
		{
			ft_putendl_fd("Error : Problem while parsing the iv", 2);
			return (0);
		}
		des->ived = 1;
	}
	if (opt->flags & E_OPT && opt->flags & S_OPT)
	{
		ft_putendl_fd("Error : You must only specify one of -e or -d", 2);
		return (0);
	}
	if (!(opt->flags & E_OPT) && !(opt->flags & D_OPT))
		opt->flags |= E_OPT;
	if (opt->flags & E_OPT)
		des->encode = 1;
	else if (opt->flags & D_OPT)
		des->encode = 0;
	return (1);
}

int	handle_o_opt(t_des *des, t_opt *opt)
{
	if (opt->flags & O_OPT)
	{
		if (!opt->o_option)
		{
			ft_putendl_fd("Error : Syntax error on -o option", 2);
			return (0);
		}
		if ((des->out_fd = open(opt->o_option, O_WRONLY | O_CREAT
			| O_TRUNC, 0644)) == -1)
		{
			ft_putstr_fd("Error : Could not open output file for writing", 2);
			return (0);
		}
	}
	else
		des->out_fd = 1;
	return (1);
}

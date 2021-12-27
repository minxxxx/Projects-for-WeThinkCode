/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_handle_k_opt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:05 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:33:37 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include <sys/stat.h>

static int	prepare_decode(t_des *des)
{
	if (ft_strncmp((char*)des->decoded_input_data, "Salted__", 8))
		return (0);
	if (des->decoded_input_data_size < 16)
		return (0);
	ft_memcpy(des->salt, des->decoded_input_data + 8, 8);
	des->offset_input_data = des->decoded_input_data + 16;
	des->offset_input_data_size = des->decoded_input_data_size - 16;
	return (1);
}

static int	prepare_encode(t_des *des, t_opt *opt)
{
	if (opt->flags & S_OPT && opt->s_option)
	{
		if (!hex_string_to_bytes(opt->s_option, des->salt, 8))
		{
			ft_putendl_fd("Error : Problem while parsing the salt.", 2);
			return (0);
		}
	}
	else
	{
		if (getentropy(des->salt, 8) == -1)
		{
			ft_putendl_fd("Error while trying to generate a random salt.", 2);
			return (0);
		}
	}
	des->offset_input_data = des->decoded_input_data;
	des->offset_input_data_size = des->decoded_input_data_size;
	return (1);
}

static int	get_password(t_opt *opt)
{
	opt->flags &= P_OPT;
	opt->p_option = ft_strdup(getpass("Please enter a password :"));
	if (!opt->p_option)
	{
		ft_putendl_fd("Error : Problem while getting the password.", 2);
		return (0);
	}
	return (1);
}

static int	generate_key(t_des *des, t_opt *opt)
{
	if (!(opt->flags & P_OPT) || !opt->p_option)
	{
		if (!get_password(opt))
			return (0);
	}
	if (des->encode == 1)
	{
		if (!prepare_encode(des, opt))
			return (0);
	}
	else
	{
		if (!prepare_decode(des))
			return (0);
	}
	return (compute_key(des, opt));
}

int			handle_k_opt(t_des *des, t_opt *opt)
{
	if (opt->flags & K_OPT && opt->k_option)
	{
		if (!hex_string_to_bytes(opt->k_option, des->key, 8))
		{
			ft_putendl_fd("Error : Problem while parsing the key", 2);
			return (0);
		}
		des->offset_input_data = des->decoded_input_data;
		des->offset_input_data_size = des->decoded_input_data_size;
		return (1);
	}
	else
		return (generate_key(des, opt));
}

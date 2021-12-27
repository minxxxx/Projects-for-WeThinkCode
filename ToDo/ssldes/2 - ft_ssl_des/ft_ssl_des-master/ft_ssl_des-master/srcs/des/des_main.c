/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:18 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static int	compute_des_struct(t_des *des, t_opt *opt, int *in_fd)
{
	ft_bzero(des, sizeof(t_des));
	if (opt->flags & A_OPT)
		des->to_base64 = 1;
	else
		des->to_base64 = 0;
	if (!handle_v_e_d_opt(des, opt))
		return (0);
	if (!handle_i_a_opt(des, opt, in_fd))
		return (0);
	if (!handle_k_opt(des, opt))
		return (0);
	if (!handle_o_opt(des, opt))
		return (0);
	return (1);
}

int			main_des_ecb(t_opt *opt)
{
	t_des	des;
	int		fd;

	if (!(compute_des_struct(&des, opt, &fd)))
		return (0);
	des_encode(&des, des.offset_input_data, des.offset_input_data_size, ecb);
	if (des.decoded_input_data != des.input_data)
		free(des.decoded_input_data);
	free(des.input_data);
	return (1);
}

int			main_des_cbc(t_opt *opt)
{
	t_des	des;
	int		fd;

	if (!(compute_des_struct(&des, opt, &fd)))
		return (0);
	if (!des.ived)
	{
		ft_putstr_fd("Error : An IV must be specified", 2);
		ft_putendl_fd(" for the cbc mode to work.", 2);
		return (0);
	}
	des_encode(&des, des.offset_input_data, des.offset_input_data_size, cbc);
	if (des.out_fd != 0)
		close(des.out_fd);
	if (des.decoded_input_data != des.input_data)
		free(des.decoded_input_data);
	free(des.input_data);
	return (1);
}

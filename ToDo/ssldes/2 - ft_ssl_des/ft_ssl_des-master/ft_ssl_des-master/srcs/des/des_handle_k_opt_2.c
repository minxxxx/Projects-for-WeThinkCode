/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_handle_k_opt_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:33:42 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:33:44 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int	compute_key(t_des *des, t_opt *opt)
{
	t_btk_md5_params	params;

	params.salt = des->salt;
	params.data = (void*)opt->p_option;
	params.data_len = ft_strlen(opt->p_option);
	params.key = des->key;
	params.key_len = 8;
	params.iv = des->iv;
	if (des->ived == 0)
		params.iv_len = 8;
	else
		params.iv_len = 0;
	if (!bytes_to_key_md5(&params))
	{
		ft_putstr_fd("Error while trying to generate", 2);
		ft_putendl_fd(" a key from the password.", 2);
		return (0);
	}
	des->salted = 1;
	des->ived = 1;
	return (1);
}

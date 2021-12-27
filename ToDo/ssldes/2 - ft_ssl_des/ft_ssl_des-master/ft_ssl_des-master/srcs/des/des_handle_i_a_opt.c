/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_handle_i_a_opt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:04 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:05 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static int	i_opt_present(t_des *des, t_opt *opt, int *in_fd)
{
	struct stat	s_buf;

	if (!opt->i_option)
	{
		if (des->out_fd != 1)
			close(des->out_fd);
		ft_putendl_fd("Error !\n", 2);
		return (0);
	}
	if ((*in_fd = open(opt->i_option, O_RDONLY)) == -1)
	{
		if (des->out_fd != 1)
			close(des->out_fd);
		ft_putendl_fd("Error while trying to open file for reading.", 2);
		return (0);
	}
	if (fstat(*in_fd, &s_buf) == -1 || (S_ISDIR(s_buf.st_mode)))
	{
		if (des->out_fd != 1)
			close(des->out_fd);
		ft_putstr_fd("Can't stat input file, or the ", 2);
		ft_putendl_fd("input file is a folder.", 2);
		return (0);
	}
	return (1);
}

static int	handle_a_opt(t_des *des, int *in_fd)
{
	lseek(*in_fd, 0, SEEK_SET);
	des->decoded_input_data = (void*)base64_dec_to_buff_from_fd(*in_fd, NULL,
		&(des->decoded_input_data_size));
	if (!des->decoded_input_data)
	{
		free(des->input_data);
		return (0);
	}
	return (1);
}

int			handle_i_a_opt(t_des *des, t_opt *opt, int *in_fd)
{
	if (opt->flags & I_OPT)
	{
		if (!i_opt_present(des, opt, in_fd))
			return (0);
	}
	else
		*in_fd = 0;
	des->input_data = (void*)get_file(*in_fd, &(des->input_data_size));
	if (!des->input_data)
	{
		ft_putendl_fd("Error : Memory error.", 2);
		return (0);
	}
	if (opt->flags & A_OPT && !des->encode)
		return (handle_a_opt(des, in_fd));
	else
	{
		des->decoded_input_data = des->input_data;
		des->decoded_input_data_size = des->input_data_size;
		return (1);
	}
}

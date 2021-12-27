/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:34:35 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:33 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int	main_md5(t_opt *opt)
{
	if (opt->flags & S_OPT)
		compute_from_string_md5(opt->content, opt);
	else
		read_file(opt->content, opt);
	return (1);
}

int	ft_md5(uint8_t *in, size_t in_len, uint8_t *out)
{
	t_params_md5	p;
	void			*buffer;
	size_t			end_len;

	initialize_buffer(p.buffer);
	initialize_t(p.t);
	if (!(buffer = malloc((in_len + 64) * sizeof(char))))
		return (0);
	ft_memcpy(buffer, in, in_len);
	end_len = padd_buffer(0, in_len, buffer);
	hash_buffer_md5(end_len, &p, buffer);
	ft_memcpy(out, p.buffer, 16);
	free(buffer);
	return (1);
}

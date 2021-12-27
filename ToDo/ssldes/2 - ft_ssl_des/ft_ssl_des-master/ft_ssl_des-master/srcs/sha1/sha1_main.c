/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:46 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:47 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void		do_sha1(int in_fd, int out_fd, char *in_filename)
{
	char		*file;
	int			in_size;
	uint32_t	*out;
	char		b[41];

	file = get_file(in_fd, &in_size);
	out = sha1_encode(file, in_size);
	bytes_to_char(out, b, 20);
	ft_putstr_fd(in_filename, out_fd);
	ft_putstr_fd("= ", out_fd);
	ft_putendl_fd(b, out_fd);
	free(out);
	free(file);
}

static int	handle_i_opt(t_opt *opt)
{
	int	in_fd;

	if (!opt->i_option)
		return (0);
	in_fd = open(opt->i_option, O_RDONLY);
	if (in_fd == -1)
		return (-1);
	return (in_fd);
}

int			main_sha1(t_opt *opt)
{
	int	in_fd;
	int	out_fd;

	if (opt->flags & I_OPT)
	{
		if ((in_fd = handle_i_opt(opt)) == -1)
			return (0);
	}
	else
		in_fd = 0;
	if (opt->flags & O_OPT)
	{
		if (!opt->o_option)
			return (0);
		out_fd = open(opt->o_option, O_RDONLY);
		if (out_fd == -1)
			return (0);
	}
	else
		out_fd = 1;
	do_sha1(in_fd, out_fd, (opt->flags & I_OPT && opt->i_option != NULL ?
		opt->i_option : "(stdin)"));
	return (1);
}

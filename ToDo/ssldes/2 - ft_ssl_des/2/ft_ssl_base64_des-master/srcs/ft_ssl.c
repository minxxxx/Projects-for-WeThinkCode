/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:44:07 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/29 14:17:58 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

t_hash			g_hash[] =
{hash_md5, hash_sha256, hash_base64, hash_des, hash_des};

void	handle_stdin(t_opt *opt)
{
	t_mem *message;

	message = NULL;
	message = read_fd(0);
	if (opt->p)
		ft_putstr((char *)message->data);
	g_hash[opt->hash](message, opt);
}

void	hash(t_opt *opt, t_mem *message)
{
	g_hash[opt->hash](message, opt);
}

void	handle_string(t_opt *opt)
{
	t_mem *message;

	message = (t_mem*)malloc(sizeof(t_mem));
	message->data = (unsigned char*)ft_strdup(opt->arg->str);
	opt->arg->is_string = 1;
	message->len = ft_strlen((char *)message->data);
	hash(opt, message);
}

void	handle_args(t_opt *opt)
{
	t_mem	*message;
	int		fd;

	message = NULL;
	while (opt->arg)
	{
		if (!opt->arg->is_string && (fd = open(opt->arg->str, O_RDONLY)) != -1)
		{
			message = read_fd(fd);
			hash(opt, message);
		}
		else
		{
			if (opt->arg->is_string)
				handle_string(opt);
			else
				(!opt->q) ? (write_file_error(opt->arg->str, opt)) : 0;
		}
		opt->arg = opt->arg->next;
	}
}

int		main(int argc, char **argv)
{
	t_opt	*opt;

	opt = NULL;
	if (argc < 2)
		return (print_usage(argv[0]));
	opt = check_opt(opt, argv);
	if (opt->output)
		open_fd(opt);
	if (opt->p || !opt->arg)
		handle_stdin(opt);
	opt->stdin = 0;
	if (argc >= 3)
		handle_args(opt);
	return (0);
}

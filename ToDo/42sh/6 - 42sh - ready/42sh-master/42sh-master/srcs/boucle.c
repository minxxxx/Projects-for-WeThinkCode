/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/03 23:26:33 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	unit_test(t_data *data, t_env **env)
{
	char	*str;
	int		r;

	if (!isatty(0))
	{
		str = mallocp(1001);
		data->in_env_i = 0;
		if ((r = read(0, str, 1000)))
		{
			str[r] = '\0';
			free(data->cmd);
			data->cmd = str;
			create_history(data, env);
			data->env = *env;
			get_index_min_win(data);
			singleton_data(data, 1);
		}
		exit(3);
	}
}

static void	handle_buf(t_data *data, char *buf, int *flag, t_env **env)
{
	if (is_add_or_del_char(data, buf))
	{
	}
	else if (is_boucle_move(data, buf))
	{
	}
	else if (is_boucle_mode_copy(data, buf))
	{
	}
	else if (is_boucle_move_history(data, buf, flag, *env))
	{
	}
	else if (is_boucle_ctrl_d_and_l(data, buf, env))
	{
	}
	else if (buf[0] == 10 && buf[1] == 0 && !data->mode_copy)
		create_history(data, env);
	else if (buf[0] == 9 && buf[1] == 0)
		if (!data->c && !data->mode_copy)
			ft_autocomplete(data);
}

void		boucle(t_env *env, t_data *data)
{
	char	buf[11];
	int		r;
	int		flag;

	unit_test(data, &env);
	flag = 0;
	ft_bzero(buf, 11);
	while ((r = read(0, buf, 10)))
	{
		data->in_env_i = 0;
		handle_buf(data, buf, &flag, &env);
		data->env = env;
		get_index_min_win(data);
		singleton_data(data, 1);
		ft_bzero(buf, 11);
	}
}

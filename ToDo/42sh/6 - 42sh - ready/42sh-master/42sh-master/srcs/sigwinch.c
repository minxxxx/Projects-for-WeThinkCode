/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigwinch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/02 16:04:50 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	get_winsize(t_data *data)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	data->win_y = w.ws_row;
	data->win_x = w.ws_col;
	if (isatty(0))
		data->after_prompt = (data->len_prompt + 1) % data->win_x;
}

void	get_index_min_win(t_data *data)
{
	int		max_cursor;

	if (isatty(0))
		max_cursor = ((data->len_prompt + (int)ft_strlen(data->cmd))
			% data->win_x);
	else
		max_cursor = 0;
	if (max_cursor == 0)
	{
		data->index_min_win = (int)ft_strlen(data->cmd) -
			(data->win_y * data->win_x);
		return ;
	}
	petit_rectangle(data);
}

void	print_command_mod(t_data *data)
{
	int	i;

	i = 0;
	if (data->mode_copy)
		while (data->cmd[i])
		{
			chose_putchar_or_vi_char(data, i);
			i++;
		}
	else
		ft_putstr(data->cmd);
}

void	chose_putchar_or_vi_char(t_data *data, int i)
{
	if (i >= data->index_min_copy && i <= data->index_max_copy)
		vi_char(data->cmd[i]);
	else
		ft_putchar(data->cmd[i]);
}

void	sigwinch(int sig)
{
	t_data	*data;
	int		old_index;

	if (!isatty(0))
		return ;
	data = singleton_data(NULL, 0);
	sig = 0;
	(void)sig;
	get_winsize(data);
	get_index_min_win(data);
	if (((data->len_prompt + (int)ft_strlen(data->cmd)) - (data->win_x)) >= 0)
	{
		data->mode_copy = 0;
		exec_tcap("cl");
		ft_putstr("\e[38;5;208m");
		ft_putstr(data->prompt);
		ft_putstr("\e[39m");
		print_command_mod(data);
		old_index = data->index;
		data->index = (int)ft_strlen(data->cmd);
		while (old_index < data->index)
			move_left_without_mod(data);
	}
}

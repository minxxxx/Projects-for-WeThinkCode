/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:08:08 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 19:26:19 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

static int		is_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] >= 65 && key[2] <= 68)
		return (1);
	return (0);
}

static int		is_delete(char *key)
{
	if (key[0] == 127 || key[0] == 8)
		return (1);
	else
		return (0);
}

static int		is_enter(char *key)
{
	if (key[0] == 10 && key[1] == 0 && key[2] == 0)
		return (1);
	else
		return (0);
}

static void		is_special_action(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 72)
		go_to_start();
	else if (key[0] == 27 && key[1] == 91 && key[2] == 70)
		go_to_end();
	else if (key[0] == 21 && key[1] == 0 && key[2] == 0)
		cut_entire_line();
	else if (key[0] == 11 && key[1] == 0 && key[2] == 0)
		cut_end_of_line();
	else if (key[0] == 16 && key[2] == 0 && key[2] == 0)
		paste();
	else if (key[0] == 12 && key[1] == 0 && key[2] == 0)
		clear();
	else if (key[0] == 3 && key[1] == 0 && key[2] == 0)
		handle_ctrl_c();
	else if (key[0] == 2 && key[1] == 0 && key[2] == 0)
		move_back_word();
	else if (key[0] == 14 && key[1] == 0 && key[2] == 0)
		move_next_word();
	else if (key[0] == 27 && key[1] == 91 && key[2] == 53)
		go_up();
	else if (key[0] == 27 && key[1] == 91 && key[2] == 54)
		go_down();
}

int				get_key(t_env *env_list, t_cmd_path *cmds,
		t_hist *history, char *key)
{
	t_hist		*tmp;
	int			i;

	i = 0;
	while (read(0, key, 15))
	{
		if (is_arrow(key))
			i = press_arrow(key[2], history, &tmp, i);
		else if (is_enter(key))
		{
			history = press_enter(env_list, history);
			tmp = history->next;
			i = 0;
		}
		else if (is_delete(key))
			press_delete();
		else if (key[0] > 30)
			print_letter(key);
		else if (key[0] == 9 && key[1] == 0 && key[2] == 0)
			autocomplete(cmds);
		else
			is_special_action(key);
		ft_bzero(key, 15);
	}
	return (0);
}

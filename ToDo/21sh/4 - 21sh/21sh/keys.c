/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 21:57:20 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:39:33 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_single_ascii(t_term **sh)
{
	int		ret;

	ret = 0;
	if ((*sh)->buf[0] >= 32 && (*sh)->buf[0] <= 126)
		ft_add_to_line(&(*sh));
	else if ((*sh)->buf[0] == 127)
		ft_remove_from_line(&(*sh));
	else if ((*sh)->buf[0] == ENTER)
		ret = ft_enter_key(&(*sh), (*sh)->my_h, 0);
	else if ((*sh)->buf[0] == 18)
		ft_clear_screen(&(*sh));
	return (ret);
}

int		ft_combine_ascii(t_term **sh)
{
	int		ret;

	ret = 0;
	if ((*sh)->buf[2] == UP)
		ft_up_key(&(*sh));
	else if ((*sh)->buf[2] == DOWN)
		ft_down_key(&(*sh));
	else if ((*sh)->buf[2] == LEFT)
		ft_left_key(&(*sh));
	else if ((*sh)->buf[2] == RIGHT)
		ft_right_key(&(*sh));
	else if ((*sh)->buf[2] == HOME)
		ft_home_key(&(*sh));
	else if ((*sh)->buf[2] == END)
		ft_end_key(&(*sh));
	else if ((*sh)->buf[2] == 49)
		ret = ft_special_key(&(*sh));
	return (0);
}

int		ft_special_key(t_term **sh)
{
	int	ret;

	ret = 0;
	ft_memset((*sh)->buf, 0, 3);
	read(0, (*sh)->buf, 3);
	if ((*sh)->buf[1] == 53)
		ret = ft_ctrl_key(&(*sh));
	return (ret);
}

int		ft_ctrl_key(t_term **sh)
{
	int		ret;

	ret = 0;
	if ((*sh)->buf[2] == HOME)
		ft_ctrl_home_key(&(*sh), (*sh)->line, 0, 0);
	else if ((*sh)->buf[2] == END)
		ft_ctrl_end_key(&(*sh), (*sh)->line);
	else if ((*sh)->buf[2] == 108)
		ft_clear_screen(&(*sh));
	return (ret);
}

void	ft_clear_screen(t_term **sh)
{
	tputs(tgetstr("cl", 0), 0, ft_shell_putchar);
	ft_putstr((*sh)->prt);
	tputs(tgetstr("sc", 0), 0, ft_shell_putchar);
	tputs((*sh)->line, 0, ft_shell_putchar);
	(*sh)->std_cur = (ft_strlen((*sh)->prt) + (*sh)->len) % tgetnum("co");
	(*sh)->my_cur = (*sh)->len;
}

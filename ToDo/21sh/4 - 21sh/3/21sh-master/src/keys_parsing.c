/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:59:14 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/25 19:47:27 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		parse_keys1(t_shell *shell, char *buf)
{
	if (buf[1] == 91)
	{
		if (buf[2] == 68)
			move_left(shell);
		else if (buf[2] == 67)
			move_right(shell);
		else if (buf[2] == 72)
			move_line_start(shell);
		else if (buf[2] == 70)
			move_line_end(shell);
		else if (buf[2] == 65)
			history_prev(shell);
		else if (buf[2] == 66)
			history_next(shell);
	}
	return (0);
}

int		parse_keys2(t_shell *shell, char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 &&
		buf[2] == 49 && buf[3] == 59 && buf[4] == 50)
	{
		if (buf[5] == 68)
			move_left_word(shell);
		else if (buf[5] == 67)
			move_right_word(shell);
		else if (buf[5] == 65)
			move_line_up(shell);
		else if (buf[5] == 66)
			move_line_down(shell);
	}
	return (0);
}

int		parse_keys3(t_shell *shell, char *buf, size_t buf_len)
{
	int	ret;

	ret = 0;
	if (buf_len == 1 && buf[0] == 10)
		return ((ret = handle_input(shell)) > 0) ? ret : 1;
	else if (buf_len == 1 && buf[0] == 4 && !shell->input && !shell->input_save)
		ft_exit(NULL);
	else if (buf_len == 1 && buf[0] == 127)
		backspace(shell);
	else if (buf_len == 4 && buf[0] == 27 && buf[1] == 91
			&& buf[2] == 51 && buf[3] == 126)
		del(shell);
	else if (buf_len == 2 && buf[0] == -61 && buf[1] == -89)
		cut_all(shell);
	else if (buf_len == 2 && buf[0] == -61 && buf[1] == -97)
		copy_eol(shell);
	else if (buf_len == 3 && buf[0] == -30 && buf[1] == -120 && buf[2] == -126)
		copy_all(shell);
	else if (buf_len == 3 && buf[0] == -30 && buf[1] == -119 && buf[2] == -120)
		cut_eol(shell);
	else if (buf_len == 3 && buf[0] == -30 && buf[1] == -120 && buf[2] == -102)
		paste_buffer(shell);
	return (0);
}

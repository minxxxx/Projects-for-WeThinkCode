/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 18:52:16 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/22 19:24:07 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	check_termcaps(void)
{
	if (!(tgetstr("do", NULL)))
		return (-1);
	if (!(tgetstr("up", NULL)))
		return (-1);
	if (!(tgetstr("le", NULL)))
		return (-1);
	if (!(tgetstr("nd", NULL)))
		return (-1);
	if (!(tgetstr("cd", NULL)))
		return (-1);
	if (!(tgetstr("mr", NULL)))
		return (-1);
	if (!(tgetstr("me", NULL)))
		return (-1);
	return (0);
}

void		init_term(t_shell *shell)
{
	int				ret;
	char			*term_name;
	struct winsize	w;

	if (!(term_name = getenv("TERM")))
	{
		ft_putstr_fd("21sh: unable to get the terminal name\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if ((ret = tgetent(NULL, term_name)) <= 0)
		ret == 0 ? quit_error(2) : quit_error(3);
	if ((tcgetattr(STDIN_FILENO, &(shell->term_save))) == -1)
		quit_error(4);
	if ((tcgetattr(STDIN_FILENO, &(shell->termios))) == -1)
		quit_error(4);
	shell->termios.c_lflag &= ~(ICANON | ECHO);
	shell->termios.c_cc[VMIN] = 1;
	shell->termios.c_cc[VTIME] = 0;
	if ((tcsetattr(STDIN_FILENO, TCSADRAIN, &(shell->termios))) == -1)
		quit_error(5);
	if ((ioctl(STDIN_FILENO, TIOCGWINSZ, &w)) < 0)
		quit_error(10);
	shell->col = w.ws_col;
	if (check_termcaps() == -1)
		quit_error(8);
}

void		reload_term(t_shell *shell)
{
	struct winsize	w;

	if ((tcsetattr(STDIN_FILENO, TCSADRAIN, &(shell->termios))) == -1)
		quit_error(5);
	if ((ioctl(STDIN_FILENO, TIOCGWINSZ, &w)) < 0)
		quit_error(10);
	shell->col = w.ws_col;
}

void		restore_term(t_shell *shell)
{
	if ((tcsetattr(STDIN_FILENO, TCSADRAIN, &(shell->term_save))) == -1)
		quit_error(5);
}

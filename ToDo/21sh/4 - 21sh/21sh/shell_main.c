/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 21:41:25 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:39:48 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "env.h"

struct termios	ft_echo_off(int fd)
{
	struct termios	new;
	struct termios	old;

	tcgetattr(fd, &old);
	tcgetattr(fd, &new);
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fd, TCSANOW, &new);
	return (old);
}

t_term			*ft_init_shell(void)
{
	t_term	*sh;

	ft_echo_off(0);
	if ((sh = (t_term *)malloc(sizeof(t_term))) == NULL)
		exit(write(2, "error: failed to malloc struct s_term *sh\n", 42));
	sh->nb_lines = 0;
	sh->std_cur = ft_strlen(USER);
	sh->my_cur = 0;
	sh->my_h = 0;
	sh->std_usr = 0;
	sh->save = NULL;
	sh->prt = ft_strdup(USER);
	ft_memset(sh->buf, 0, 3);
	sh->line = ft_strnew(MAX_LEN);
	if (sh->line == NULL)
		exit(write(1, "error: failed to malloc line for shell\n", 39));
	sh->len = 0;
	ft_putstr(USER);
	return (sh);
}

int				ft_read_entry(t_term **sh)
{
	int	chk;
	int	ret;

	chk = 0;
	ft_memset((*sh)->buf, 0, 3);
	ret = read(0, (*sh)->buf, 3);
	if (ret > 0)
		chk = ft_buf_input(&(*sh));
	return (chk);
}

int				ft_buf_input(t_term **sh)
{
	int	ret;

	ret = 0;
	if (ft_strlen((*sh)->buf) < 2)
		ret = ft_single_ascii(&(*sh));
	else
		ret = ft_combine_ascii(&(*sh));
	return (ret);
}

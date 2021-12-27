/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:10:16 by sfranc            #+#    #+#             */
/*   Updated: 2017/10/06 14:37:29 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static char	*ft_get_user(void)
{
	struct passwd *ret_pwd;

	if (!(ret_pwd = getpwuid(getuid())))
		return (NULL);
	return (ft_strdup(ret_pwd->pw_name));
}

static void	ft_prompt_ret_cmd(void)
{
	if (g_shell->ret_cmd == EXIT_SUCCESS)
		ft_putstr(BGREEN" $> "RESET);
	else
		ft_putstr(BRED" $> "RESET);
}

int			ft_put_prompt_sigint(void)
{
	int len;

	ft_raw_term();
	tputs(tgetstr("cr", NULL), 1, &ft_intputchar);
	tputs(tgetstr("ce", NULL), 1, &ft_intputchar);
	len = ft_display_prompt();
	ft_canonic_term();
	return (len);
}

int			ft_display_prompt(void)
{
	char	*user;
	char	*cwd;
	int		len;

	len = 6;
	ft_putstr(BWHITE);
	if ((user = ft_get_user()))
	{
		ft_putstr(user);
		ft_putstr(": "BLUE);
		len += ft_strlen(user);
	}
	else
	{
		ft_putstr("21sh: "BLUE);
		len += 4;
	}
	free(user);
	if ((cwd = getcwd(NULL, 0)))
	{
		ft_putstr(cwd);
		len += ft_strlen(cwd);
	}
	free(cwd);
	ft_prompt_ret_cmd();
	return (len);
}

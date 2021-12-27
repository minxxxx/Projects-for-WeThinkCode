/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:09:09 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:32 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

int			prompt(t_env *env_list, char *current_line)
{
	char	*user;
	char	*pwd;
	char	*home_dir;
	int		size;

	size = 0;
	home_dir = search_in_env("HOME", env_list);
	user = search_in_env("USER", env_list);
	pwd = search_in_env("PWD", env_list);
	if (user && pwd && home_dir)
	{
		pwd = ft_str_replace(pwd, home_dir, "~");
		ft_putcolor(user, "cyan");
		ft_putstr(" in ");
		ft_putcolor(pwd, "light yellow");
		ft_putchar('\n');
	}
	ft_putstr(PROMPT);
	if (current_line)
		ft_putstr(current_line);
	if (env_list != NULL)
		size = ft_strlen(user) + ft_strlen(pwd) + 4;
	return (size);
}

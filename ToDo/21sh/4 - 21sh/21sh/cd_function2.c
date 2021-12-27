/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 12:53:17 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:11:08 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "env.h"

void	ft_update_cd_env(char **new, char **old, char **pwd, t_parser **hq)
{
	(*hq)->env = ft_update_myenv((*hq)->env, "OLDPWD", *pwd);
	(*hq)->env = ft_update_myenv((*hq)->env, "PWD", *new);
	ft_memdel((void **)&(*new));
	ft_memdel((void **)&(*old));
	ft_memdel((void **)&(*pwd));
}

int		ft_change_dir_to_home(t_parser **hq)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;
	char	*new;

	home = ft_get_line_myenv((*hq)->env, "HOME");
	pwd = ft_get_line_myenv((*hq)->env, "PWD");
	oldpwd = ft_get_line_myenv((*hq)->env, "OLDPWD");
	new = ft_strdup(home);
	chdir(new);
	ft_memdel((void **)&home);
	ft_update_cd_env(&new, &oldpwd, &pwd, &(*hq));
	return (0);
}

int		ft_change_dir3(char **s, t_parser **hq)
{
	char	*new;
	char	*pwd;
	char	*old;

	old = NULL;
	if (ft_strlen(s[1]) == 2 && s[1][1] == '-')
		return (ft_change_dir_to_home(&(*hq)));
	if (ft_strlen(s[1]) > 2)
		return (ft_change_dir2(s, &(*hq)));
	new = ft_get_line_myenv((*hq)->env, "OLDPWD");
	pwd = ft_get_line_myenv((*hq)->env, "PWD");
	chdir(new);
	ft_update_cd_env(&new, &old, &pwd, &(*hq));
	return (0);
}

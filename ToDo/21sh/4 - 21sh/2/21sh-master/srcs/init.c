/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:20:21 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/14 11:24:56 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static void	ft_increase_shlvl(char ***env)
{
	char	*shlvl;
	char	*temp;
	char	*newlvl;
	int		lvl;

	if ((shlvl = ft_get_env_variable(*env, "SHLVL")))
	{
		lvl = ft_atoi(shlvl) + 1;
		newlvl = ft_itoa(lvl);
		temp = shlvl;
		shlvl = ft_strjoin("SHLVL=", newlvl);
		free(temp);
		free(newlvl);
		ft_modify_variable(env, shlvl);
		free(shlvl);
	}
	else
		ft_addtotab(env, "SHLVL=1");
}

static void	ft_update_pwd(char ***env)
{
	char	*cwd;
	char	*pwd;
	char	*temp;

	if (!(cwd = getcwd(NULL, 0)))
		return ;
	if ((pwd = ft_get_env_variable(*env, "PWD")))
	{
		temp = cwd;
		cwd = ft_strjoin("PWD=", cwd);
		free(temp);
		ft_modify_variable(env, cwd);
		free(pwd);
		free(cwd);
	}
	else
	{
		pwd = ft_strjoin("PWD=", cwd);
		ft_addtotab(env, pwd);
		free(pwd);
		free(cwd);
	}
}

t_shell		*ft_init(char **environ)
{
	t_shell	*shell;

	shell = ft_memalloc(sizeof(t_shell));
	shell->env = ft_tabdup(environ);
	ft_increase_shlvl(&(shell->env));
	ft_update_pwd(&shell->env);
	return (shell);
}

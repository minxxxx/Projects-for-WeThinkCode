/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:15:50 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/21 17:57:36 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define EXIT_ERROR		255

# define CMD_CD			"cd"
# define CMD_ECHO		"echo"
# define CMD_ENV		"env"
# define CMD_HIST		"history"
# define CMD_SETENV		"setenv"
# define CMD_UNSETENV	"unsetenv"
# define CMD_EXIT		"exit"
# define STR_NUM		"numeric argument required"
# define STR_NAME		"Variable name must contain alphanumeric characters."
# define STR_TOO_MANY	"too many arguments"
# define STR_HOME		"HOME not set"
# define STR_OLDPWD		"OLDPWD not set"
# define STR_HIST_EMPTY	"21sh: history is empty"

int		ft_is_builtin(char *cmd);
int		ft_builtin_echo(char **cmd);
int		ft_builtin_env(char **cmd);
int		ft_builtin_setenv(char **cmd);
int		ft_builtin_unsetenv(char **cmd);
int		ft_builtin_cd(char **cmd);
void	ft_builtin_exit(char **cmd);
int		ft_builtin_history(char **cmd);

/*
** ENV
*/
char	*ft_get_env_variable(char **env, char *var);
void	ft_modify_variable(char ***env, char *new_var);

#endif

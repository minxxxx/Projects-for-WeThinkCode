/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 09:02:24 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:57:46 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define FREE_ARRAY if(a->array[0]!=NULL)ft_delarray(a->array);a->array = NULL
#define DEL_STR ft_strdel(&new);ft_strdel(&old)
#define DEL_ARR ft_delarray(a->oldpwd);ft_delarray(a->pwd)
#define FREE DEL_STR;DEL_ARR
#define INI i=0;j=0
#define P ft_delarray(a->new);ft_strdel(&a->c)

/*
 ** Changes pwd in the enviroment when changing directories
*/

void	chpwd(char *path, t_all *a)
{
	int			i;
	int			j;
	char		*new;
	char		*old;

	INI;
	while (ft_strncmp(a->new[i], "PWD=", 4) != 0)
		i++;
	while (ft_strncmp(a->new[j], "OLDPWD=", 7) != 0)
		j++;
	a->oldpwd = ft_strsplit(a->new[j], '=');
	a->pwd = ft_strsplit(a->new[i], '=');
	ft_strdel(&a->oldpwd[1]);
	a->oldpwd[1] = ft_strdup(a->pwd[1]);
	ft_strdel(&a->pwd[1]);
	a->pwd[1] = ft_strdup(path);
	new = ft_strjoin("PWD=", a->pwd[1]);
	old = ft_strjoin("OLDPWD=", a->oldpwd[1]);
	ft_strdel(&a->new[i]);
	ft_strdel(&a->new[j]);
	a->position = i;
	a->new[i] = ft_strdup(new);
	a->new[j] = ft_strdup(old);
	FREE;
}

/*
 ** Checks what builtin it is
*/

void	ft_chkchk(t_all *a)
{
	if (ft_strcmp(a->array[0], "<<") == 0)
		ft_heredoc_no_cmd(a->array, a);
	else if (ft_strncmp(a->array[0], "history", 7) == 0)
		ft_list_history(a->array[0], a);
	else if (ft_strncmp(a->array[0], "cd", 2) == 0)
		ft_cd(a);
	else if ((ft_strcmp(a->array[0], "env") == 0)
			|| ft_strcmp(a->array[0], "setenv") == 0
			|| ft_strcmp(a->array[0], "unsetenv") == 0)
	{
		a->yes = 1;
		ft_env(a);
	}
	else if (ft_strcmp(a->array[0], "clear") == 0)
	{
		a->yes = 1;
		ft_putstr(CLEAR);
	}
	else if (ft_strcmp(a->array[0], "exit") == 0
			|| ft_strcmp(a->array[0], "EXIT") == 0)
	{
		ft_putendl(GREEN"\n[ terminated succesfully ]\n"RESET);
		P;
		exit(25);
	}
}

/*
 ** Checks if it's a builtin
*/

void	ft_checks(t_all *a, struct termios *term)
{
	a->yes = 0;
	ft_chkchk(a);
	if (a->yes == 0)
		path(a, term);
}

/*
 ** This will check what echo to run
*/

void	ft_check_echo(char *str, t_all *a)
{
	if (ft_strnstr(str, "echo $((", 8) != NULL)
		ft_echo_calc(str, a);
	else
		ft_echo_new(str, a);
}

/*
 ** This will loop and get commands
*/

void	ft_sequence(char *str, t_all *a, struct termios *term)
{
	char	*temp;

	if (ft_pipecheck(str, a) != 1 && a->piped == 0)
	{
		if (ft_strnstr(str, "echo", 4) == NULL)
		{
			temp = ft_strdup_notab(str);
			if (ft_strchr(temp, 32) != NULL)
				a->array = ft_strsplit(temp, 32);
			else
			{
				a->array = (char **)malloc(sizeof(char *) * 2);
				a->array[0] = ft_strdup(temp);
				a->array[1] = NULL;
			}
			if (a->array[0] != NULL)
			{
				ft_checks(a, term);
				FREE_ARRAY;
			}
			ft_strdel(&temp);
		}
		else
			ft_check_echo(str, a);
	}
}

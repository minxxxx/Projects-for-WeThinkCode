/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:58:04 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 03:34:30 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define VAR char dir[4096];char **path;char	*temp;int i;int	n;int ret;

char	*ft_strnew_two(size_t size, t_all *a)
{
	char	*set;

	ft_strdel(&a->c);
	if (!(set = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(set, '\0', size + 1);
	return (set);
}

int		ft_get_dir(void)
{
	VAR;
	i = 0;
	getcwd(dir, sizeof(dir));
	temp = NULL;
	n = 0;
	ret = 0;
	if (dir[1] != '\0')
	{
		n = ft_strlen(dir);
		if (n > 1)
		{
			path = ft_strsplit(dir, '/');
			i = ft_arraylen(path) - 1;
			temp = ft_strdup(path[i]);
			ft_delarray(path);
			ret = ft_strlen(temp) + 3;
			ft_strdel(&temp);
			return (ret);
		}
	}
	return (4);
}

/*
 ** Will check if it needs to run a script or a shell depending on input.
*/

int		main(int ac, char **av, char **env)
{
	ft_putstr(CLEAR);
	if (ac == 2)
		ft_run_script(av[1], env);
	else if (ac == 1)
		ft_loop(env);
	return (0);
}

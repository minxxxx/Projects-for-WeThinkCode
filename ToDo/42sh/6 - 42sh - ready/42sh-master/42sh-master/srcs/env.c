/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/02 16:45:54 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static t_env		*parse_line(t_env *ret, char *env)
{
	char	*ptr;
	char	*s1;
	char	*s2;

	ptr = ft_strchr(env, '=');
	if (!ptr)
		return (ret);
	s1 = ft_strsub(env, 0, ptr - env);
	s2 = ft_strsub(ptr, 1, ft_strlen(ptr) - 1);
	if (!s2)
		s2 = ft_strdup("");
	ret = add_elem_end(ret, s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

static char			*get_path(void)
{
	char	path[255];
	int		r;
	int		fd;

	r = 0;
	if ((fd = open("/etc/paths", O_RDONLY)) == -1)
		return (NULL);
	r = read(fd, path, 255);
	close(fd);
	path[r - 1] = '\0';
	r = 0;
	while (path[r])
	{
		if (path[r] == '\n')
			path[r] = ':';
		r++;
	}
	return (ft_strdup(path));
}

static int			var_exist(char **env, char *check)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strnstr(env[i], check, ft_strlen(check)))
			return (1);
		i++;
	}
	return (0);
}

static t_env		*init_list_no_env(char **env)
{
	t_env	*ret;
	char	*tmp;

	ret = NULL;
	if (!var_exist(env, "PATH="))
	{
		tmp = get_path();
		ret = add_elem_end(NULL, "PATH", tmp);
		free(tmp);
	}
	if (!var_exist(env, "PWD=") || !var_exist(env, "OLDPWD="))
	{
		tmp = getcwd(NULL, 0);
		ret = add_elem_end(ret, "PWD", tmp);
		ret = add_elem_end(ret, "OLDPWD", tmp);
		free(tmp);
	}
	if (!var_exist(env, "HOME="))
		ret = add_elem_end(ret, "HOME", "/");
	if (!var_exist(env, "SHLVL="))
		ret = add_elem_end(ret, "SHLVL", "0");
	if (!var_exist(env, "TERM="))
		ret = add_elem_end(ret, "TERM", "xterm-256color");
	return (ret);
}

t_env				*ft_parse_env(char **env)
{
	int		i;
	t_env	*ret;
	char	*tmp;
	char	*tmp2;

	i = 0;
	ret = init_list_no_env(env);
	while (env[i] != NULL)
	{
		ret = parse_line(ret, env[i]);
		i++;
	}
	if (isset_arg(ret, "SHLVL"))
	{
		tmp = find_arg(ret, "SHLVL");
		tmp2 = ft_itoa_base(ft_atoi(tmp) + 1, 10);
		change_arg(ret, "SHLVL", tmp2);
		free(tmp);
		free(tmp2);
	}
	return (ret);
}

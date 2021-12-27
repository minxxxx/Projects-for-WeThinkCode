/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dw31 <dw31@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 22:05:25 by dw31              #+#    #+#             */
/*   Updated: 2015/10/25 15:00:47 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

static char		*give_shellname(t_env *env)
{
	const char		*def_shellname = "/bin/bash";
	int				i;

	i = -1;
	while (ENVIRON_SAVE[++i])
	{
		if (ft_strnequ("SHELL", ENVIRON_SAVE[i], 5))
			return (&ENVIRON_SAVE[i][6]);
	}
	return ((char*)def_shellname);
}

void			init_env(t_env *env)
{
	extern char		**environ;
	const char		*def_filename = "typescript";

	ft_bzero(env, sizeof(t_env));
	OPT_T_VALUE = 30;
	ENVIRON_SAVE = environ;
	SHELLNAME = give_shellname(env);
	FILENAME = (char*)def_filename;
}

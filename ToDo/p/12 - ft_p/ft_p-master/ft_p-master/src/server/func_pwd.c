/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:24 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:26 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	func_pwd(t_data *data)
{
	char			cwd[MAXPATHLEN + 1];

	if (!data->logged_in)
		return (setret(data, 530, ERROR_NOT_LOGGED, 1));
	if (getcwd(cwd, MAXPATHLEN) == 0)
		cwd[0] = '\0';
	data->return_code = 257;
	data->free_commentaire = 1;
	data->commentaire = " \"";
	data->commentaire = ft_strjoin(data->commentaire, cwd);
	data->commentaire = ft_strjoinaf1(data->commentaire,
		"\" is the current directory");
	return ;
}

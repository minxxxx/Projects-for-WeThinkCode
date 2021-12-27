/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 11:16:29 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 21:20:03 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <libft.h>

# define EOF -1

typedef struct		s_env
{
	int				proto_nb;
	char			*addr;
	char			*port;
	int				sock;
	char			**cmd;
}					t_env;

void				init_env(t_env *env, char **av);
void				create_client(t_env *env);
void				client_shell(t_env *env);
int					is_cmd_valid(t_env *env);
void				send_pwd(t_env *env, char *pwd);

#endif

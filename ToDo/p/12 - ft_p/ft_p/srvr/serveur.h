/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 11:16:29 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 23:22:31 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <libft.h>

# define EOF -1
# define SEND_EOF(x) ft_putchar_fd(EOF, x)

typedef struct		s_env
{
	int				proto_nb;
	char			*port;
	int				sock;
	char			*pwd_init;
	char			*pwd_cur;
	char			*pwd_clnt;
}					t_env;

void				init_env(t_env *env, char *port);
void				create_server(t_env *env);
void				manage_client(t_env *env);
void				send_resp_to_clnt(char *errmsg, int clnt);
void				send_errno_to_clnt(int clnt);
void				transform_path(t_env *env, char **cmd, t_bool isls);
t_bool				is_path_valid_ls(t_env *env, char **cmd, int clnt);
t_bool				cpy_file(int srcfd, int dstfd, int clnt);
void				exec_get(t_env *env, char **cmd, int clnt);
void				exec_put(t_env *env, char **cmd, int clnt);
void				exec_cd(t_env *env, char **cmd, int clnt);
void				exec_pwd(t_env *env, char **cmd, int clnt);
void				exec_ls(t_env *env, char **cmd, int clnt);
void				exec_mkdir(t_env *env, char **cmd, int clnt);
void				exec_rmdir(t_env *env, char **cmd, int clnt);
void				exec_unlink(t_env *env, char **cmd, int clnt);

#endif

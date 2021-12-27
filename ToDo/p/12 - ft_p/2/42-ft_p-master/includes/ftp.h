/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:21:22 by jtranchi          #+#    #+#             */
/*   Updated: 2018/05/12 15:21:23 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# include <sys/socket.h>
# include <netdb.h>
# include <stdio.h>
# include <arpa/inet.h>
# include "../libft/includes/libft.h"
# include <sys/stat.h>
# include "errno.h"
# define BUFFER 1024

typedef struct		s_mem
{
	char			*data;
	int				len;
}					t_mem;

int					exec_ls(char **tabl, int fd);
int					exec_pwd(int fd);
int					exec_get(char **tabl, int fd);
int					exec_cd(t_mem *mem, char *wd, int fd);
void				exec_lls(t_mem **mem, char **tabl);
void				exec_lpwd(t_mem **mem);
int					exec_lcd(t_mem *mem, char *wd);
int					exec_mkdir(char **tabl, int fd);
int					exec_rmdir(char **tabl, int fd);
int					exec_unlink(char **tabl, int fd);
int					check_put(t_mem **mem);
int					check_if_contains(char *wd, char *newwd);
void				ft_chdir(char *wd, char *cmd, int fd);
t_mem				*prompt();
void				remove_back(t_mem *mem);
void				print_usage(void);
int					write_error(char *cmd, char *err, int fd);
void				write_success(char *cmd, int fd);
t_mem				*read_fd(int fd);
void				write_fd(int fd, t_mem *buf);
t_mem				*ft_memjoin(t_mem *dest, t_mem *src);
int					check_if_data(t_mem *mem);
int					check_put_data(t_mem *mem, int socket);
int					ft_create_client(char *addr, int port);
char				*get_address(char *addr);
int					write_error(char *cmd, char *err, int fd);
void				ft_free_tabl(char **tabl);
void				ft_free_mem(t_mem *mem);

#endif

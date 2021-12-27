/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:11:24 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:11:49 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <libft.h>
# include <ft_printf.h>
# include <sys/socket.h>
# include <stdio.h>
# include <netdb.h>
# include <unistd.h>
# include <sys/param.h>
# include <arpa/inet.h>
# include <dirent.h>
# include <sys/stat.h>

# define SYSTEM_NAME_AN " UNIX Type: L8"

# define ERROR_NOT_LOGGED " Please login with USER and PASS"
# define WARNING_NO_PASS_FILE_1 "The password file doesn't exist or can't be"
# define WARNING_NO_PASS_FILE_2 " opened. There won't be any credential"
# define WARNING_NO_PASS_FILE_3 " checking.\n"
# define WARNING_NO_PASS_FILE_4 WARNING_NO_PASS_FILE_1 WARNING_NO_PASS_FILE_2
# define WARNING_NO_PASS_FILE WARNING_NO_PASS_FILE_4 WARNING_NO_PASS_FILE_3

# define TYPE_ASCII		0
# define TYPE_BINARY	1

# define BUFF_SIZE_2 1024

# define NAME_USER "USER"
# define NAME_PASS "PASS"
# define NAME_SYST "SYST"
# define NAME_FEAT "FEAT"
# define NAME_CWD  "CWD"
# define NAME_PWD  "PWD"
# define NAME_CDUP "CDUP"
# define NAME_PASV "PASV"
# define NAME_LIST "LIST"
# define NAME_TYPE "TYPE"
# define NAME_SIZE "SIZE"
# define NAME_MDTM "MDTM"
# define NAME_RETR "RETR"
# define NAME_STOR "STOR"
# define NAME_QUIT "QUIT"

# define VALUE_USER 0
# define VALUE_PASS 1
# define VALUE_SYST 2
# define VALUE_FEAT 3
# define VALUE_CWD  4
# define VALUE_PWD  5
# define VALUE_CDUP 6
# define VALUE_PASV 7
# define VALUE_LIST 8
# define VALUE_TYPE 9
# define VALUE_SIZE 10
# define VALUE_MDTM 11
# define VALUE_RETR 12
# define VALUE_STOR 13
# define VALUE_QUIT 14

typedef struct	s_command {
	char				*str_commande;
	int					nbr_commande;
	char				*argument;
}				t_command;

typedef struct	s_data {
	char				*av;
	int					return_code;
	char				*commentaire;
	int					free_commentaire;
	void				(**tab)(struct s_data *);
	char				*str;
	int					logged_in;
	char				*usr;
	int					error;
	t_command			*cmd;
	int					pass_fd;
	int					serv_data_port;
	int					client_data_port;
	int					data_connection_on;
	int					data_connection_socket;
	int					pi_port;
	int					pi_socket;
	struct in_addr		local_addr;
	int					type;
	char				*exec_path;
}				t_data;

typedef void	(*t_command_func)(t_data*);

void			print_error_message(char *filename, char *message);
int				pemr(char *filename, char *message);
void			handle_connection(int cs, t_data *data);
void			command_user(t_data *data);
t_command		parse_cmd(char *str, t_data *data);
char			*get_pass(char *username, t_data *data);
void			remove_cr(char *str);
void			send_data_list(t_data *data, char *str);
void			close_data_connection(t_data	*data);
int				init_accept(t_data *data);
void			setret(t_data *data, int ret, char *com, int error);
void			handle_sigchld(int p);
int				open_wrapper(t_data *data, const char *path, int oflag,
		int mode);
char			*get_current_dir(void);
int				free_and_ret(void *a, void *b, void *c, int ret);
DIR				*opendir_wrapper(t_data *data, const char *path);
int				can_be_oppenedir(const char *path, const char *exec_path);

void			func_user(t_data *data);
void			func_pass(t_data *data);
void			func_syst(t_data *data);
void			func_feat(t_data *data);
void			func_cwd(t_data *data);
void			func_pwd(t_data *data);
void			func_cdup(t_data *data);
void			func_pasv(t_data *data);

void			func_list(t_data *data);
void			get_rights(char *ret, mode_t mode);

void			func_type(t_data *data);
void			func_size(t_data *data);
void			func_mdtm(t_data *data);
void			func_retr(t_data *data);
void			func_stor(t_data *data);
void			func_quit(t_data *data);
#endif

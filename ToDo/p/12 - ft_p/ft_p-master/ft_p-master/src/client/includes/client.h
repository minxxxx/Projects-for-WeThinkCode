/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:30:31 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:33:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

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

# define NAME_RFC_USER "USER"
# define NAME_RFC_PASS "PASS"
# define NAME_RFC_SYST "SYST"
# define NAME_RFC_FEAT "FEAT"
# define NAME_RFC_CWD  "CWD"
# define NAME_RFC_PWD  "PWD"
# define NAME_RFC_CDUP "CDUP"
# define NAME_RFC_PASSIVE "PASV"
# define NAME_RFC_LS "LIST"
# define NAME_RFC_TYPE "TYPE"
# define NAME_RFC_SIZE "SIZE"
# define NAME_RFC_MDTM "MDTM"
# define NAME_RFC_GET "RETR"
# define NAME_RFC_PUT "STOR"
# define NAME_RFC_QUIT "QUIT"

# define VALUE_RFC_USER 0
# define VALUE_RFC_PASS 1
# define VALUE_RFC_SYST 2
# define VALUE_RFC_FEAT 3
# define VALUE_RFC_CWD  4
# define VALUE_RFC_PWD  5
# define VALUE_RFC_CDUP 6
# define VALUE_RFC_PASSIVE 7
# define VALUE_RFC_LS 8
# define VALUE_RFC_TYPE 9
# define VALUE_RFC_SIZE 10
# define VALUE_RFC_MDTM 11
# define VALUE_RFC_RETR 12
# define VALUE_RFC_STOR 13
# define VALUE_RFC_QUIT 14

# define NAME_LOGIN "login"
# define NAME_PWD "pwd"
# define NAME_CD "cd"
# define NAME_TYPE "type"
# define NAME_LS "ls"
# define NAME_GET "get"
# define NAME_PUT "put"
# define NAME_QUIT "quit"
# define NAME_SIZE "size"

# define VALUE_LOGIN 0
# define VALUE_PWD 1
# define VALUE_CD 2
# define VALUE_TYPE 3
# define VALUE_LS 4
# define VALUE_GET 5
# define VALUE_PUT 6
# define VALUE_QUIT 7
# define VALUE_SIZE 8

typedef struct termios	t_termios;

typedef struct			s_cmd {
	int		cmd_nbr;
	char	**cmd_tab;
}						t_cmd;

typedef struct			s_data {
	char	*prompt;
	char	*cmd_str;
	t_cmd	cmd;
	char	*machine;
	int		port;
	int		socket;
	void	(**tab)(struct s_data *);
	int		error;
}						t_data;

typedef struct			s_answer {
	int		code;
	char	*commentaire;
	int		error;
	char	*str;
}						t_answer;

typedef void			(*t_command_func)(t_data*);

char					**ft_special_split(char const *s);
int						parse_cmd(t_data *data, char *str);
void					pem(char *filename, char *message);
int						pemr(char *filename, char *message);
void					remove_cr(char *str);
t_answer				get_answer(t_data *data);
char					*build_request(const char *prefix, const char *suffix);
int						set_passive_mode(t_data *data);
void					free_double_tab(char **tab);
void					redirect_data(int data_fd, int redir_fd);
t_data					*singleton_data(t_data *data);
void					sigint(int sig);
void					error_connection(t_data *data);
void					print_prompt(t_data *data, int print_prompt);
void					free_cmd(t_cmd cmd);
void					free_answer(t_answer answer);
void					reinit_data(t_data *data);
void					set_error_and_ret(t_data *data,
	char *filename, char *message);
int						create_socket(int port, char *av, char *s_addr);
void					print_prompt(t_data *data, int print_prompt);
void					handle_line(t_data *data, char *cmd);
void					init_tab(t_command_func *tab);

void					func_login(t_data *data);
void					func_pwd(t_data *data);
void					func_cd(t_data *data);
void					func_type(t_data *data);
void					func_ls(t_data *data);
void					func_get(t_data *data);
void					func_put(t_data *data);
void					func_quit(t_data *data);
void					func_size(t_data *data);

#endif

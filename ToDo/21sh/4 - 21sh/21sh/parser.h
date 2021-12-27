/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 02:05:43 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:03:41 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# define BUILT_IN "cd setenv unsetenv pwd exit"
# define ERROR_CLOSE "2>&-"

typedef	struct		s_fd
{
	int				in;
	int				out;
	int				err;
}					t_fd;

typedef	struct		s_cmd
{
	t_fd			fds;
	int				ret;
	int				pos;
	int				err;
	char			*line;
	char			*exec_name;
	char			*path;
	char			**argv;
	struct s_cmd	*next;
}					t_cmd;

typedef	struct		s_parser
{
	t_fd			fds;
	t_cmd			*cmds;
	int				pipe[2];
	int				pipe_in;
	int				nb_pipes;
	int				done_pipes;
	char			*line;
	char			**infile;
	char			**outfile;
	char			**env;
}					t_parser;

/*
*** parser functions
*/
t_parser			*ft_init_parser_hq(char *line);
void				ft_parser_control_tower(char *line);
void				ft_deploy_parser(t_parser **hq);
int					ft_get_command_line(char *str, char **line);
char				**ft_load_argv(char *line, int i, int j, int kill);

/*
*** pipe functions
*/
int					ft_pipe_control_tower(char *line, char *rule);
int					ft_count_pipes(char *line);

/*
*** my builtin functions
*/
int					ft_my_builtins_check(t_cmd **cmd);
void				ft_my_builtins(t_cmd **cmd, char **env, t_parser **hq);
void				ft_builtin_pwd(char **argv, char **env);
void				ft_builtin_setenv(char **argv, t_parser **hq);
void				ft_builtin_unsetenv(char **argv, t_parser **hq);

/*
*** command functions
*/
int					ft_upload_commands(t_parser **hq);
int					ft_upload_simple_command(t_cmd **cmds, char *line, \
		int pos, char **env);
char				*ft_upload_simple_command_path(char *exec, char **env, int i);
void				ft_deploy_commands(t_parser **hq, t_cmd **cmds);
void				ft_deploy_simple_command(t_cmd **cmd, char **outfile, \
		int tmpout, t_parser **hq);
void				ft_final_deploy(t_cmd **cmd, char **myenv, t_parser **hq);
void				ft_deploy_good_command(t_parser **hq, t_cmd **cmd, \
		int tmpin, int tmpout);

/*
*** redirection function
*/
int					ft_get_redirection_infile(t_parser **hq);
int					ft_get_redirection_outfile(t_parser **hq);
int					ft_open_infile(char *file);
int					ft_redirection_error(int err, char *file, int fd);
int					ft_deploy_in_redirection(char **file, int i);
void				ft_redirect_out(char **s, int i);

#endif

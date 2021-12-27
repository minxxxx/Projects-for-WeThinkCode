/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:28:24 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/25 15:12:53 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define PATH_OK			0
# define REDIR_OK			0
# define REDIR_ERROR		1
# define CMD_NOT_FOUND		127
# define NO_FILE 			127
# define IS_DIR 			126
# define PERM_DENIED 		126

# define STR_FORK_ERROR		"21sh: fork failed"
# define STR_EXECVE_ERROR	"21sh: execve failed"
# define STR_CMD_NOT_FOUND	"command not found"
# define STR_NO_FILE 		"No such file or directory"
# define STR_IS_DIR 		"is a directory"
# define STR_NOT_DIR 		"Not a directory"
# define STR_PERM_DENIED 	"Permission denied"
# define STR_BAD_FD 		"Bad file descriptor"
# define STR_AMB_REDIR		"ambiguous redirection"
# define STR_OPEN_ERROR		"open error"
# define STR_DUP_ERROR 		"dup error"
# define STR_PIPE_ERROR 	"pipe failed"
# define STR_SEGFAULT		"Segmentation Fault: 11"
# define STR_FLOATING		"Floating point exception: 8"
# define STR_BUS_ERROR		"Bus error: 10"
# define STR_SIGABORT		"Abort: 6"

/*
** EXECUTION
*/
int		ft_execute(t_ast *ast);
int		ft_launch_builtin(char **cmd);
int		ft_launch_simple_cmd(t_ast *ast);
int		ft_launch_pipeline(t_ast *node_left, t_ast *node_right);
int		ft_init_launch(int save[3], t_ast *ast);
char	**ft_cmd_into_tab(t_ast *ast);
int		ft_fork(char *path, char **cmd);
int		ft_exit_status(int ret);

/*
** EXPANSION AND QUOTES
*/
void	ft_expand(t_token *token);
void	ft_remove_quoting(t_token *token);
void	ft_heredoc_expand_remove_quoting(t_token *token);
int		ft_is_valid_expand(char *str);
void	ft_var_expansion(char **str, char *dollar);
/*
** REDIRECTION
*/
void	ft_save_std_fd(int save[3]);
void	ft_restore_std_fd(t_ast *ast, int save[3]);
int		ft_init_redirection(t_ast *ast);
int		ft_agreg_files(t_token *redir);
int		ft_heredoc_pipe(t_token *redir);
int		ft_make_dup2(char *dest_name, int fd_dest, int fd_src);
int		ft_open_error(int fd, int err, char *file_name);
int		ft_open_file(t_token *file);

/*
** PATH
*/
int		ft_get_path(char *cmd, char **path);
void	ft_put_cmd_error(char *cmd, char *error);

#endif

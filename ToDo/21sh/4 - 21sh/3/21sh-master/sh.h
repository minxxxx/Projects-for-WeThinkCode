/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:07:09 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/22 19:22:30 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <libft.h>
# include <ft_printf.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# define CMD 1
# define SEM 2
# define PIP 3
# define REDIR 1
# define DREDIR 2
# define BREDIR 3
# define HEREDOC 4

typedef struct			s_redir
{
	int					type;
	char				*s;
	struct s_redir		*next;
}						t_redir;

typedef struct			s_env
{
	char				*var;
	char				*val;
	struct s_env		*next;
}						t_env;

typedef struct			s_input
{
	char				c;
	struct s_input		*prev;
	struct s_input		*next;
}						t_input;

typedef	struct			s_hist
{
	struct s_input		*input;
	struct s_hist		*prev;
	struct s_hist		*next;
}						t_hist;

typedef struct			s_btree
{
	int					type;
	char				*str;
	struct s_redir		*redir;
	struct s_btree		*left;
	struct s_btree		*right;
}						t_btree;

typedef struct			s_shell
{
	int					fd[4];
	size_t				col;
	size_t				input_len;
	size_t				p_len;
	t_env				*env_lst;
	t_hist				*hist;
	int					hist_end;
	t_input				*input;
	t_input				*input_save;
	t_input				*buffer;
	t_input				*curs_pos;
	char				*input_buf;
	t_btree				*tree;
	struct termios		termios;
	struct termios		term_save;
}						t_shell;

void					quit_error(int errnum);
int						exec_error(int errnum, char *arg);
int						cmd_error(int errnum, char c, char *s);
int						cd_error(int errnum, char *arg);
int						env_error(int errnum, int flag);
void					env_var_error(int errnum, char *cmd, char *arg);
int						exit_error(int errnum, char *arg);

void					free_input_list(t_input **input, size_t *nb_elem);
void					free_tmp_inputs(t_shell *shell, int reset_save);
void					free_env_var(t_env *env_var);
void					free_env_lst(t_env **env_lst);
void					free_redirs(t_redir **redirs);
void					free_btree(t_btree *tree);

void					init_shell(t_shell *shell);
void					init_term(t_shell *shell);
void					restore_term(t_shell *shell);
void					reload_term(t_shell *shell);
void					sig_handler(int signum);
void					sig_handler1(int signum);
void					sig_handler_heredoc(int signum);
void					set_sig_handler(void);
t_shell					*get_struct(t_shell *struc);

int						putchar(int c);
int						strrchr_outside_quotes(char *s, char c, char quote);
int						strchr_redir(t_btree *link);
int						is_str_quoted(char *s);
char					*strdup_remove_quotes(char *s);
char					*str_replace_var(char *s, int start);
char					**strsplit_args(char const *s);
char					**str_subsplit_arg(char const *s);
size_t					lst_len(t_input *lst);
char					*lst_to_str(t_input *lst);
t_input					*lst_rchr(t_input *input, char c);
t_input					*lst_rchr_eol(t_input *input);
t_input					*get_last_elem(t_input *lst);
int						is_builtin(char *cmd);

void					store_environ(t_shell *shell, char **environ);
int						store_env_var(t_env **env_lst, char *var, char *val);
int						del_env_var(t_env **env_lst, char *var);
int						dup_env_lst(t_env *env_lst, t_env **env_lst_cpy);
t_env					*get_env_ptr(t_env *env_lst, char *var);
char					**env_lst_to_array(t_env *env_lst);

int						check_env_var(char *env_var, char *cmd);
char					*env_var_to_value(char *var);
int						set_new_pwd(t_env *env_lst);

char					*get_prompt(t_env *env_lst);
char					*get_special_prompt(char c);
void					print_prompt(t_shell *shell, int special_prompt);

void					read_input(t_shell *shell);
void					read_multi_lines_input(t_shell *shell, char *prompt);
void					print_input(t_shell *shell, t_input *curs_pos,
						size_t p_len);
int						parse_input(t_shell *shell, char *buf,
						size_t buf_len, size_t p_len);
void					store_input(t_shell *shell, char c);
void					delete_input(t_input **lst, t_input *input,
						t_shell *shell, int back);
void					clear_input(t_shell *shell);

int						parse_keys1(t_shell *shell, char *buf);
int						parse_keys2(t_shell *shell, char *buf);
int						parse_keys3(t_shell *shell, char *buf, size_t buf_len);

int						move_left(t_shell *shell);
int						move_left_word(t_shell *shell);
int						move_right(t_shell *shell);
int						move_right_word(t_shell *shell);
int						move_line_start(t_shell *shell);
int						move_line_end(t_shell *shell);
int						move_line_up(t_shell *shell);
int						move_line_down(t_shell *shell);
int						backspace(t_shell *shell);
int						del(t_shell *shell);
int						cut_eol(t_shell *shell);
int						cut_all(t_shell *shell);
int						copy_eol(t_shell *shell);
int						copy_all(t_shell *shell);
void					store_buffer(t_input **buf, char c);
int						paste_buffer(t_shell *shell);

int						history_prev(t_shell *shell);
int						history_next(t_shell *shell);
t_hist					*store_hist(t_shell *shell);

void					replace_cursor(t_shell *shell, int print, int back);
size_t					get_cursor_x_pos(t_input *input,
						t_input *pos, size_t p_len);

int						handle_input(t_shell *shell);
int						check_pipes(t_input *cmd, int reverse);
char					valid_input(t_input *input, char c);
char					**parse_cmd(t_btree *cmd);
t_btree					*store_cmd(char *str);
char					*interpret_cmd_arg(char *cmd_arg);
char					*remove_cmd_redir(char *cmd, t_redir *redir);
int						handle_btree(t_shell *shell, t_btree *tree);
int						handle_cmd(t_shell *shell, t_btree *link,
						int already_forked);
pid_t					redir_fork(char **cmd, t_shell *shell);
pid_t					exec_fork(char **cmd, char **env_array, t_env *env_lst);
pid_t					pipe_fork_father(t_shell *shell,
						t_btree *link);
pid_t					pipe_fork_child(t_shell *shell, t_btree *link);
int						handle_redirs(t_shell *shell, t_btree *link,
						char **cmd);
int						exec_redir_cmd(t_shell *shell, char **cmd);
int						fill_heredoc(char *delimiter, int *fd);

int						builtins_cmd(char **cmd, t_env *env_lst);
int						ft_exit(char **cmd);
int						ft_cd(char **cmd, t_env *env_lst);
int						ft_echo(char **cmd);
int						ft_env(char **cmd, t_env *env_lst, int i);
int						ft_setenv(char **cmd, t_env **env_lst, int flag);
int						ft_unsetenv(char **cmd, t_env **env_lst);

int						binary_cmd(char **cmd, char **env_array,
						t_env *env_lst);
char					*get_bin_path(char *cmd, t_env *env_lst);
int						check_bin_path(char *bin_path, char *cmd);
int						exec_bin(char *bin_path, char **argv, char **env);

int						dup_std_fd(int *fd);
void					close_and_reset_fd(int *fd);

#endif

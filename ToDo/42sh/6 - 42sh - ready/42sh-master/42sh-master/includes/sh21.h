/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:47:59 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/03 23:25:57 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H
# include <libft.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <term.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <sys/time.h>
# define NONE (char)0
# define POINT_VIRGULE ';'
# define ETET (char)1
# define OUOU (char)2
# define ERR_GETOLDWD "Error: Get OLDPWD\n"
# define ERR_GETCWD "Error: Get PWD\n"
# define BUF_CWD 1024
# define BUF_CWD_MAX BUF_CWD * 1024
# define BUF_CWD_ERR "Error in Get CWD\n"

# undef tab

typedef struct dirent	t_dirent;
typedef struct termios	t_termios;

typedef struct			s_env {
	char				*name;
	char				*arg;
	struct s_env		*next;
}						t_env;

typedef struct			s_var {
	char				*name;
	char				*arg;
	struct s_var		*next;
}						t_var;

typedef struct			s_fd {
	int					fd;
	int					fd_pointe;
	struct s_fd			*next;
}						t_fd;

typedef	struct			s_cmd {
	char				**av;
	int					sep;
	struct s_cmd		*next;
	int					is_valid;
	t_fd				*fd_in;
	t_fd				*fd_out;
	t_fd				*fd_err;
	int					p_error;
	int					error;
	int					ret;
}						t_cmd;

typedef struct			s_aggr {
	int					avant;
	int					apres;
	int					chevron;
}						t_aggr;

typedef struct			s_hc {
	struct s_hc			*next;
	char				*content;
}						t_hc;

typedef struct			s_redir {
	char				*quote;
	int					fd;
	int					fd_file;
	int					redir_type;
	t_cmd				*cmd;
	t_hc				**heredocs;
}						t_redir;

typedef struct			s_history {
	char				*line;
	int					time;
	int					get_from_file;
	struct s_history	*next;
	struct s_history	*prec;

}						t_history;

typedef struct			s_auto {
	char				*str;
	struct s_auto		*next;
}						t_auto;

typedef struct			s_data {
	char				*prompt;
	int					len_prompt;
	char				*cmd;
	char				c;
	int					index;
	int					old_index;
	int					quote_old_index;
	int					real_len_cmd;
	t_history			*history;
	t_history			*history_en_cours;
	int					history_fd;
	int					history_flag[8];

	char				*key_here;
	size_t				end_hd;
	t_hc				*heredocs;
	char				*cmd_tmp;
	int					quote_or_hd;
	int					first_line_of_hd;
	char				*heredocs_tmp;
	char				*command_save;

	t_cmd				*command;
	char				*first;
	int					first_search;
	t_env				*env;
	t_var				*var;
	int					win_y;
	int					win_x;
	int					after_prompt;
	int					in_env_i;
	int					index_min_win;
	int					mode_copy;
	int					index_min_copy;
	int					index_max_copy;
	char				*clipboard;
	int					flag_enter;
	t_auto				*list_auto;
	char				*cmd_before_auto;
	int					index_before_auto;
	int					index_in_word_before_auto;
	char				*absolute_cmd_before_auto;
	int					index_before_move;
	int					absolute_index_before_move;
	char				*absolute_cmd_before_cmd_before_move;
	int					ret;
	int					cd_ret;

	char				**new_elem;
	char				**tmp_var_env;
	int					i;
	t_cmd				*orig_cmd;
	t_cmd				*cd_cmd;
	size_t				subs_index;
	int					subs_flag;
	size_t				var_index_begin;
	size_t				var_length;
	int					parse_count;
	size_t				parse_old_i;
	t_hc				**parse_heredocs;
	int					subs_for_first_char;
}						t_data;

t_env					*ft_parse_env(char **env);
t_env					*add_elem_end(t_env *list, char *name, char *arg);
char					**ft_special_split(char const *s);
int						is_builtin(char *cmd);
int						exec_builtin(t_cmd *cmd, t_env **env, t_data *data);
void					change_arg(t_env *list, char *name, char *new_arg);
char					*find_arg(t_env *list, char *name);
int						ft_cd(char **scmd, t_env **env, t_data *data);
int						isset_arg(t_env *list, char *name);
void					delete_elem(t_env **list, char *name);
void					delete_list(t_env *list);
int						exec_file(t_cmd *cmd, t_env *list, int in_env_i,
		t_data *data);
char					**make_env_char(t_env *list);
int						ft_source(char **scmd, t_env **env);
void					exec_cmd(t_env **env, t_cmd *command, t_data *data);
void					handle_line(char *line, t_env **env);
void					free_char_tab(char **tab);
t_termios				*singleton_termios(t_termios *termios, int i);
t_termios				*init_term(t_data *data);
void					boucle(t_env *env, t_data *data);
int						my_putchar(int c);
void					exec_tcap(char *tcap);
char					*insert_char(char *str, int index, char c);
char					*delete_char(char *str, int index);
char					*print_prompt(t_env *env, t_data *data);
void					move_left(t_data *data);
void					move_left_simple(t_data *data);
void					move_right(t_data *data);
void					move_right_simple(t_data *data);
int						is_special(char *str, int quote);
int						is_quote(char car);
int						is_quote_open(char car);
int						is_quote_close(char car, char open);
int						is_quote_end(t_data *data);
int						ft_isspace2(char car);
void					prompt_quote(t_data *data);
t_history				*add_history_elem(t_history *list, t_history *elem);
t_history				*create_history_elem(char *content);
t_cmd					*create_cmd_elem(char *str, int count, t_hc **heredocs);
t_cmd					*add_cmd_elem(t_cmd *list, t_cmd *elem);
char					*pos_quote_end(char en_cours, char *str);
void					print_list(t_cmd *lst);
t_cmd					*parse(char	*str, t_hc *heredocs, t_env **env,
		t_data *data);
void					join_inside_quote(size_t *i, char **str);
int						is_aggr(size_t *i, char *str, int jump);
char					*is_redir(size_t *i, char *str, int jump, t_cmd *cmd);
char					*skip_quotes(char **str, size_t *i, t_cmd *cmd);
int						is_sep(size_t *i, char *str, int jump, t_cmd *cmd);
t_fd					*add_fd_elem(t_fd *list, t_fd *elem);
t_fd					*create_fd(int fd, int fd_pointe);
int						split_cmd(int count, char **str, t_cmd *cmd,
		t_hc **heredocs);
char					*skip_quotes_nb_arg(char *str, size_t *i, t_cmd *cmd);
int						is_empty(char *str, size_t *i);
int						handle_redir(size_t *i, char **str, t_cmd *cmd,
		t_hc **heredocs);
t_fd					*copy_list_fd(t_fd *list);
t_fd					*copy_fd(t_fd *list);
int						handle_aggr(size_t *i, char *str, int jump, t_cmd *cmd);
void					print_fd(t_fd *list);
int						def_sep(char *str);
int						is_key(t_data *data);
t_hc					*create_hc_elem(char *content);
t_hc					*add_hc_elem(t_hc *list, t_hc *elem);
void					display_heredoc (t_hc *elem);
void					free_heredoc(t_data *data, t_hc *list);
char					*find_exec(char *scmd, t_data *data, t_env *env);
int						fork_pipes(t_cmd *cmd, t_env *env, t_data *data);
int						is_empty_border(char *str, size_t beg, size_t end);
void					get_pos_after_quote(size_t *i, char *str);
void					close_fd_cmd(t_cmd *cmd);
void					close_fd(t_fd *fd);
void					multi_redir_cmd_out(t_cmd	*cmd);
void					sigint(int sig);
t_data					*singleton_data(t_data *termios, int i);
void					invert_term(void);
void					sigwinch(int sig);
void					get_winsize(t_data *data);
int						get_actual_line(t_data *data);
int						get_actual_cursor(t_data *data);
int						get_prompt_line(t_data *data);
int						can_move_down(t_data *data);
int						can_move_up(t_data	*data);
int						get_line_max(t_data *data);
void					move_r2l(t_data *data);
void					insert_mode(t_data *data, char c);
int						get_actual_cursor(t_data *data);
void					delete_mode(t_data *data);
int						ft_echo(char **scmd, t_cmd *cmd);
void					get_index_min_win(t_data *data);
int						get_actual_cursor_2(t_data *data);
void					page_up(t_data *data);
void					page_down(t_data *data);
void					vi_char(char c);
void					vi_str(char *s);
void					vi_str_free(char *s);
void					move_left_without_mod(t_data *data);
void					move_right_without_mod(t_data *data);
void					move_r2l(t_data *data);
void					move_l2r(t_data *data);
void					previous_word(t_data *data);
void					next_word(t_data *data);
void					init_history(t_data *data);
int						ft_history(char **scmd, t_data *data, t_cmd *cmd);
int						get_history_flag(t_data *data, char **scmd, int *j,
		t_cmd *cmd);
int						get_history_command_part(char *line);
int						get_history_path(t_data *data, char **path);
int						get_history_fd(t_data *data);
int						history_flag_none(t_data *data, char **scmd,
		t_cmd *cmd);
void					print_line_info(t_history *list, int i, int flg,
		t_cmd *cmd);
int						history_flag_c(t_data *data);
int						history_flag_d(t_data *data, char **scmd, t_cmd *cmd);
int						get_history_path_anrw(t_data *data, char **path,
		char *scmd);
int						history_flag_a(t_data *data, char *scmd);
int						history_flag_w(t_data *data, char *scmd);
int						history_flag_r(t_data *data, char *scmd, t_cmd *cmd);
int						history_flag_n(t_data *data, char *scmd, t_cmd *cmd);
void					delete_last_history(t_data *data);
char					*get_history_substutition(t_data *data, char *scmd);
int						history_flag_p(char **scmd, t_cmd *cmd);
int						history_flag_s(t_data *data, char **scmd);
char					*history_subsitution_nb_arg(t_data *data,
		char *command);
int						is_substitution(char *str, size_t *i, t_cmd *cmd,
		t_data *data);
void					history_exit(t_data *data);
void					ft_autocomplete(t_data *data);
int						true_var_and_subs(t_data *data, char **str);
int						ft_setvar(char **scmd, t_data *data, t_cmd *cmd);
char					*find_var_env(t_data *data, char *name, t_env *env);
int						is_escaped_char(char *str, int index);
int						is_pipe_error(char *str);
void					putstr_builtin(t_cmd *cmd, char *str, int fd);
void					putendl_builtin(t_cmd *cmd, char *str, int fd);
void					putchar_builtin(t_cmd *cmd, char car, int fd);
void					putnbr_builtin(t_cmd *cmd, int nb, int fd);
int						isset_var(t_var *list, char *name);
int						ft_unset(char **scmd, t_env **env, t_cmd *cmd,
		t_data *data);
int						ft_export(char **scmd, t_env **env, t_cmd *cmd);
int						get_ret(int status, t_data *data);
void					signal_handler(void);
int						is_wrong_pipe(char *str, int index);

int						ft_exit_bi(char **scmd, t_env *env, t_data *data);
void					exit_ctrl_d(t_env *env, t_data *data);

int						env_tmp_exc(t_env **env, t_data *d, char **scmd,
		t_cmd *cmd);
int						print_env(t_env *new, t_cmd *cmd);
t_env					*copy_env(t_env *env);
t_env					*create_tmp_env(t_data *data, t_env *env,
		char **scmd, int i);

void					delete_list_fd(t_fd *list);
void					delete_list_command(t_cmd *list);
void					delete_list_history(t_history *list);
void					delete_list_fd(t_fd *list);
void					delete_list_command(t_cmd *list);
void					delete_list_history(t_history *list);
void					delete_heredocs(t_data *data);
void					delete_list_auto(t_auto *list);
void					delete_list_env_and_var(t_data *data);
void					delete_data(t_data *data);
void					delete_list_var(t_var *list);
void					reinit_list_auto(t_data *data);

t_auto					*create_auto_elem(char *content);
t_auto					*add_auto_elem(t_auto *list, t_auto *elem);
int						is_auto_arg(char *cmd, char **ptr, size_t i,
		int first_word);
int						is_empty_border_in_actual_cmd(char *str, size_t i);
void					jump_all_quote_for_arg(char *str, size_t *i);
void					init_autocomplete(t_data *data, char **split,
		char *str_to_equ, char *prefix);
char					*find_ptr(char *cmd);
void					reinitialise_heredoc(t_data *data, int flag);

void					chose_putchar_or_vi_char(t_data *data, int i);

void					petit_rectangle(t_data *data);

int						is_subs_and_replace(t_data *d, char **str,
		size_t *index, int flag);
int						subs_for_last_command(t_data *data, char **arg,
		size_t *length);
int						subs_for_command_number(t_data *data, char **arg,
		char **str, size_t *length);
int						subs_default(t_data *data, char **arg, char **str,
		size_t *length);
void					delete_subs_and_replace(char **str,
		size_t index, size_t length, char *arg);
void					is_var_and_replace(t_data *data, char **str,
		size_t *index);
int						delete_var_and_replace(char **str,
		size_t index, size_t length, char *arg);
int						is_tilde_and_replace(t_data *data, char **str,
		size_t *index);
int						is_escaped_char(char *str, int index);
int						is_quote_true_open(char car, char *str, int prec);
int						is_quote_true_close(char car, char open, char *str,
		int prec);
char					*find_subs_in_parsing(t_data *data, char *str,
		size_t length);
int						print_error_fd_file(t_redir redir, t_cmd *cmd);
int						error_open_file(t_redir *redir, t_cmd *cmd);
int						error_handling_heredoc(t_redir *redir, t_cmd *cmd);

int						cd(char **command, t_env **env, t_data *data,
		t_cmd *cmd);
int						is_legal_options(char **str, t_cmd *cmd, t_data *data);
int						is_goto_home(char **command);
void					go_to_home_directory(t_env **env, t_data *data);
int						is_logical_goto_oldpwd(char **str);
void					go_to_old_pwd(t_data *data, t_env **env, int p);
void					change_dir(char *path, t_env **env, t_data *data,
		int p);
int						is_physical_goto_oldpwd(char **str);
size_t					ft_nstrlen(const char *s);
int						ft_count_string(char *str, char c);
char					**ft_lz_strsplit(char *str, char c);
char					*triple_join(char *s1, char *s2, char *s3);
void					ft_str2del(char **array);
char					*strdup_skip(char *str);
void					ft_str2defrag(char **array, size_t origin_size);
size_t					ft_str2len(char **array);
char					*join_slash(char **s);
int						is_minus(char *str);
int						is_physical(char *str);
int						is_logical(char *str);
void					display_not_such(char *who, char *where, t_cmd *cmd,
		t_data *data);
void					display_cd_permission(char *path, t_cmd *cmd,
		t_data *data);
void					display_cd_invalid_option(char *opt, t_cmd *cmd,
		t_data *data);
char					*troncate_dots(char *path);
char					*concat_chdir(char *path, t_env **env, t_data *data,
		int i);
void					ft_remove_endchar(char *str, char c);
char					*remove_duplicate_slash(char *path);
void					cd_symblink(char *path, t_env **env, t_data *data);
void					cd_physical(char *path, t_env **env, t_data *data,
		t_cmd *cmd);
int						operate_legal_opts(char **str, t_cmd *cmd,
		t_data *data);

void					move_index(t_data *data);

void					move_up_history(t_data *data, t_env *env);
void					move_down_history(t_data *data, t_env *env);
int						create_history(t_data *data, t_env **env);
int						is_add_or_del_char(t_data *data, char buf[11]);
int						is_boucle_move(t_data *data, char *buf);
int						is_boucle_mode_copy(t_data *data, char buf[11]);
int						is_boucle_ctrl_d_and_l(t_data *data, char buf[11],
		t_env **env);
void					boucle_home(t_data *data);
void					boucle_end(t_data *data);
void					init_or_end_mode_copy(t_data *data);
int						is_boucle_move_history(t_data *data, char buf[11],
		int *flag, t_env *env);
void					do_get_pb(t_data *data);

int						add_command(t_data *data, char *str, size_t *i,
		t_env **env);
int						nb_arg(size_t *i, char *str, t_cmd *cmd);
int						print_pipe_error(void);
int						verif_wrong_sep(int *pipe_last, int *first_char);
int						verif_first_pipe_error(char *str, size_t *i,
		int *pipe_last,
		int first_char);
void					find_list_auto(t_data *data);
int						find_if_is_redir(char *str, size_t *tmp, int *fd,
		int *redir_type);

int						spawn_proc(t_cmd *cmd, t_env *env, t_data *data,
		int fd);
t_cmd					*cmd_not_found(t_cmd *command, t_data *data,
		t_env *env);
void					print_cmd_not_found(char *scmd);
void					exec_builtin_pipe(t_cmd *cmd, t_env **env,
		t_data *data);
int						is_boucle_h_e_pu_pd(t_data *data, char *buf);
int						is_boucle_h_e_pu_pd(t_data *data, char *buf);
void					real_page_up(t_data *data);
void					real_page_down(t_data *data);

#endif

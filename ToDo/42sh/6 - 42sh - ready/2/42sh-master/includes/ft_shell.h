/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mineshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 09:02:21 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 01:53:45 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHELL_H
# define FT_SHELL_H

# define LSH_RL_BUFSIZE 	1024
# define LSH_TOK_BUFSIZE 	64
# define LSH_TOK_DELIM		" \t\r\n\a"

# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include "libft.h"
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>
# include <dirent.h>

typedef struct		s_subsh
{
	int				i;
	int				pos;
	char			*c;
}					t_subsh;

typedef struct		s_exe
{
	char			**cmds;
}					t_exe;

typedef struct		s_dqoute
{
	int				a;
	char			*c;
	char			**array;
}					t_dqoute;

typedef struct		s_bin
{
	char			**path;
	char			**find;
	char			*file;
	char			*check;
	int				i;
	int				n;
	int				arraylen;
	int				on;
}					t_bin;

typedef	struct		s_all
{
	int				piped;
	int				cmdrun;
	int				histnum;
	int				position;
	int				onoff;
	int				yes;
	char			**history;
	int				histpos;
	char			**array;
	char			**new;
	char			**pwd;
	char			**oldpwd;
	char			*c;
	int				i;
	int				pos;
}					t_all;

typedef struct		s_setenv
{
	char			**newenv;
	int				len;
	int				i;
	char			**str;
}					t_setenv;

typedef	struct		s_unset
{
	char			**newenv;
	int				i;
	int				len;
	int				n;
	int				j;
}					t_unset;

typedef struct		s_heredoc
{
	char			**heredocarr;
	int				loop;
}					t_heredoc;

typedef struct		s_value
{
	int				i;
	char			*name;
	char			**s;
}					t_value;

typedef struct		s_execvp
{
	char			**cmds;
	int				exitstatus;
	pid_t			father;
}					t_execvp;

typedef struct		s_pipeloop
{
	int				p[2];
	int				fd_in;
	pid_t			father;
}					t_pipeloop;

typedef struct		s_reverse_direct
{
	char			**cmds;
	int				fd;
	int				i;
}					t_reverse_direct;

typedef struct		s_red
{
	char			**cmds;
	int				fd;
	int				i;
}					t_red;

typedef struct		s_dir
{
	char			**names;
	char			*curr_dir;
	DIR				*dp;
	struct dirent	*dptr;
	t_list			*list;
}					t_dir;

typedef struct		s_autoc
{
	char			*curr_dir;
	DIR				*dp;
	struct dirent	*dptr;
	char			**names;
}					t_autoc;

/*
 ** The following are in: MAIN.C
*/

void				ft_freeshl(char **str);
void				ft_shlvl(t_all *a);
void				ft_print_dir(void);
void				ft_loop(char **env);

/*
 ** The following are in: MINISHELL.C
*/

void				chpwd(char *path, t_all *a);
void				ft_chkchk(t_all *a);
void				ft_checks(t_all *a, struct termios *term);
void				ft_sequence(char *str, t_all *a, struct termios *term);

/*
 ** The following are in: FT_EXECCMDS.C
*/

void				ft_execpath(char *path, t_all *a);
void				ft_execcurr(t_all *a, struct termios *term);

/*
 ** The following are in: FT_CD.C
*/

void				ft_cd(t_all *a);
void				ft_dir(t_all *a);
void				ft_null(t_all *a);
void				ft_dots(t_all *a);
void				ft_dash(t_all *a);

/*
 ** The following are in: FT_ECHO.C
*/

void				ft_echo(char *str, t_all *a);
void				ft_echoenv(char *str, t_all *a);
void				ft_dqoute(void);
void				ft_dq(int count, char *array[2048]);
void				ft_print(char *str);

/*
 ** The following are in: FT_ENV.C
*/

void				ft_env(t_all *a);
void				ft_printenv(t_all *a);
char				**ft_value(t_all *a, char **str);
char				**ft_unsetenv(t_all *a);

/*
 ** The following are in: FT_MULTIPIPE.C
*/

void				ft_loop_pipe(char **cmds, t_all *a);
void				ft_execvp(char *cmd, t_all *a);
char				*ft_add_path(char *cmd, t_all *a);

/*
 ** The following are in: FT_REDIRECT.C
*/

void				ft_redirect_in(char	**holder, t_all *a);
void				ft_redirect_in_append(char	**holder, t_all *a);
void				ft_createfile(char *str, t_all *a);

/*
 ** The following are in: GET_PATH.C
*/

char				*ft_splitname(t_all *a);
int					ft_ptsplit(t_bin *bin);
void				path_part_two(t_all *a, t_bin *bin, struct termios *term);
void				path(t_all *a, struct termios *term);

/*
 ** The following are in: FT_SETENV.C
*/

char				*ft_equal(char *str);
int					ft_chkenv(t_all *a, char *b);
void				ft_makecap(t_all *a);
void				ft_setenv(t_all *a);

/*
 ** The following are in: FT_MULTIPLE.C
*/

int					ft_multiple(char *str, t_all *a);

/*
 ** The following are in: FT_PIPECHK.C
*/

int					ft_pipecheck(char *str, t_all *a);
void				ft_l_arrow(char *str, t_all *a);
void				ft_r_arrow(char *str, t_all *a);
void				ft_line(char *str, t_all *a);

/*
 ** The following are in: SIGNAL.C
*/

void				signal_sigint(int sig);
void				signal_sigint_main(int sig);
void				fork_signal_handler(int sig);
void				signal_sigkill(int sig);
void				signal_sigkill_main(int sig);
void				signal_sigsegv(int sig);
void				handle_signals(t_all *a);

/*
 ** LIST UTIL
*/

t_list				*frontaddlink(t_list *list, char *str);
void				addlink(t_list **head, char *str);
void				freelist(t_list **list);
size_t				sizeoflist(t_list *list);
void				printlist(t_list *list);

/*
 ** Globbing Util
*/

int					hasglob(char **array);
int					implementg(t_all *a);
int					isglob(const char *s);
int					rangeisvalid(const char *let);
int					ft_isalnumextended(char c);
int					starglob(const char *name, char *str);
int					quesglob(const char *name, char *str);
int					bracglob(const char *name, char *str);
int					globfunction(const char *name, char *str);
int					brackets(const char *str, char c);
char				**listtoarray(t_list **list);
int					globinit(char *argv, t_all *a);
int					curlyglob(const char *name, char *str);
int					globinit_two(char *argv, t_exe *b);
int					implementg_two(t_exe *b);

/*
 ** RANDOM
*/

void				ft_logical_or(char **cmds, t_all *a);
int					ft_logical_and(char **cmds, t_all *a);
int					ft_and(char *str, t_all *a);
void				ft_reverse_direct(char **holder, t_all *a);
void				ft_heredoc(char **holder, t_all *a);
void				ft_unset_norm(t_all *a);
void				ft_echo_calc(char *str, t_all *a);
void				ft_and_2(char *str, t_all *a);
void				ft_print_echo(char *s, char c);
void				ft_print_dqoute(char **arr, char sym);
void				ft_echo_new(char *s, t_all *a);
void				ft_print_no_qoutes(char *s);
void				ft_heredoc_no_cmd(char **arr, t_all *a);
char				**ft_set_heredoc_arr(void);
void				ft_direct_heredoc(char **arr, char *cmd, t_all *a);
void				ft_run_script(char *c, char **env);
int					ft_logical_and(char **cmds, t_all *a);
char				**ft_strsplit_colon(char const *s, char c);
void				ft_stderr(char **holder, t_all *a);
void				ft_std_everything(char	**holder, t_all *a);
char				*remove_two(char *str);
void				ft_std_everything_append(char **holder, t_all *a);
void				ft_root(t_all *a);
void				ft_home(t_all *a);
void				ft_chdir(t_all *a);
void				ft_createhistory(t_all *a);
void				ft_add_to_hist(char *str, t_all *a);
char				*ft_exec_history(char *hist, t_all *a);
void				ft_echo_cmds(char *str, t_all *a);
void				ft_subshell(char *cmd, t_all *a, int count,
														struct termios *term);
void				ft_list_history(char *str, t_all *a);
int					non_canonical(struct termios *term, char *status);
int					keyhook(t_all *a);
int					keyhook_sub(t_subsh *s);
void				ft_ud_history(char read_in[8], t_all *a);
char				*findfile(char *tofind);
void				ft_echo_exe_cmd(char *str, t_all *a);
void				ft_tabbing(t_all *a);
int					ft_get_dir(void);
void				ft_right(t_all *a);
void				ft_left(t_all *a);
void				ft_backspace(t_all *a);
int					non_canonical(struct termios *term, char *status);
int					ft_save(int i);
char				*ft_strnew_two(size_t size, t_all *a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 16:14:04 by wide-aze          #+#    #+#             */
/*   Updated: 2015/11/08 15:22:59 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include <libft.h>
# include <sys/time.h>
# include <termios.h>

# define DEBUG_MODE env->debug_mode
# define OPT_A env->opt_a
# define OPT_K env->opt_k
# define OPT_Q env->opt_q
# define OPT_S_ENABLED env->opt_s_enabled
# define OPT_M_ENABLED env->opt_m_enabled
# define OPT_M_TIME env->opt_m_time
# define OPT_M_VALUE env->opt_m_value
# define OPT_T_VALUE env->opt_t_value
# define SHELLNAME env->shellname
# define FILENAME env->filename
# define ENVIRON_SAVE env->environ_save
# define CMD_TAB env->cmd
# define CMD(x) env->cmd[x]
# define NB_CMD env->nb_cmd
# define LAST_FLUSHTIME env->last_flushtime
# define OUTFILE_FD env->outfile_fd
# define START_AND_STOP_DIRECTLY ((OPT_T_VALUE > 100000000) ? TRUE : FALSE)
# define PTM env->ptm
# define PTS env->pts
# define CMDSTR env->cmdstr
# define READBUF env->readbuf
# define FLUSHBUF env->flushbuf
# define TERM_ATTR env->term_attr
# define BUFSIZE 2048

typedef struct		s_env
{
	t_bool			debug_mode;
	t_bool			opt_a;
	t_bool			opt_k;
	t_bool			opt_q;
	t_bool			opt_s_enabled;
	t_bool			opt_m_enabled;
	int				opt_m_time;
	int				opt_m_value;
	int				opt_t_value;
	char			*filename;
	int				nb_cmd;
	char			*cmdstr;
	char			**cmd;
	char			**environ_save;
	char			*shellname;
	time_t			last_flushtime;
	int				outfile_fd;
	int				ptm;
	int				pts;
	char			*readbuf;
	char			*flushbuf;
	struct termios	term_attr;
}					t_env;

void				init_env(t_env *env);
int					filename_found(t_env *env, int ac, char **av);
char				**s_opt_found(t_env *env, char *arg, int *ac, char **av);
char				**m_opt_found(t_env *env, char *arg, int *ac, char **av);
t_bool				is_zero(char *arg);
int					analyze_av_ac(t_env *env, int ac, char **av);
void				print_debug(t_env *env);
int					ft_tcattr(int fd, struct termios *t, t_bool isget);
void				ft_cfmakeraw(struct termios *t);
int					ft_grantpt_unlockpt(int fd);
int					open_outfile(t_env *env);
t_bool				ft_openpt(t_env *env);
time_t				get_time(void);
char				*get_strtime(void);
void				ft_flush(t_env *env);
void				handle_flush(t_env *env);
int					launch_scripted_shell(t_env *env, const char *cstr);
int					im_master(t_env *env);
void				im_slave(t_env *env, char **cmdtab);
void				close_outfile(t_env *env);

#endif

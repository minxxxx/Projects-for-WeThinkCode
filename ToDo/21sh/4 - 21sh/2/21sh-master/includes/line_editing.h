/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 14:55:24 by sfranc            #+#    #+#             */
/*   Updated: 2017/10/03 16:16:57 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# include <term.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>

# define INPUTSIZE		4096
# define BUFFSIZE		6
# define DEFAULT_TERM	"xterm-256color"
# define HISTO_PROMPT	"search_history> "

typedef struct	s_input
{
	char	*line;
	char	*tmp;
	int		width;
	int		len;
	int		x;
	int		y;
	int		prompt;
	int		origin_prompt;
}				t_input;

enum			e_mode
{
	DEFAULT,
	QUOTES,
	LIST = 1,
	HEREDOC,
	HISTORY
};

/*
** READLINE
*/
void			ft_read_line(char **line, int len_prompt, int mode);

/*
** TERM
** ft_interpret mode :
** 0 == regular prompt
** 1 == parser prompt waiting for the end of input list or quote.
** 2 == heredoc
** 3 == historic search
*/
void			ft_init_input_struct(t_input *input, int len_prompt);
void			ft_raw_term(void);
void			ft_canonic_term(void);
int				ft_interpret(char *buff, t_input *input, int mode);
int				ft_intputchar(int c);

/*
** CURSOR MOVES
*/
void			ft_move_left(t_input *input);
void			ft_move_right(t_input *input);
void			ft_move_up(t_input *input);
void			ft_move_down(t_input *input);

/*
** MOVE COMMANDS
*/
void			ft_beginning_of_line(t_input *input);
void			ft_end_of_line(t_input *input);
void			ft_jumpword_forward(t_input *input);
void			ft_jumpword_backward(t_input *input);

/*
** MOVES NOT LINKED TO USER COMMANDS
*/
void			ft_goto_begin(t_input *input);
void			ft_goto_prompt(t_input *input);
void			ft_goto_newpos(t_input *input, int cur_y);
void			ft_goto_lastpos(t_input *input);

/*
** BUFFER
*/
int				ft_insertchar(char *buff, t_input *input);
void			ft_back_deletechar(t_input *input);
void			ft_deletechar(t_input *input);
void			ft_accept_line(t_input *input);

/*
** COPY N CUT
*/
void			ft_copy(t_input *input);
void			ft_cut(t_input *input);

/*
** SCREEN
*/
void			ft_clear(t_input *input);
void			ft_clear_screen(t_input *input);

/*
** PROMPT
*/
int				ft_put_prompt_sigint(void);
int				ft_display_prompt(void);

/*
** HISTORY
*/
void			ft_history_back(t_input *input);
void			ft_history_forth(t_input *input);
void			ft_history_search(t_input *input);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance4.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:09:16 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:59:46 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUISSANCE4_H

# define FT_PUISSANCE4_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include "libft.h"

# define J1 'O'
# define J2 'X'
# define VOIDCASE '.'
# define FULL "Draw"
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct	s_grid
{
	char		**grid;
	int			height;
	int			width;
	int			graphique;
}				t_grid;

typedef struct	s_player
{
	int			level;
	int			(*f)(t_grid *, int);
}				t_player;

void			ft_addtab(int *tab, int value);
int				ft_ai(t_grid *grid, int player, int iter);
int				ft_ai1(t_grid *grid, int player);
int				ft_ai2(t_grid *grid, int player);
int				ft_ai3(t_grid *grid, int player);
int				ft_ai4(t_grid *grid, int player);
int				ft_checkfull(t_grid *grid);
int				ft_checkwin(t_grid *grid, int player);
int				ft_count(t_grid *grid, int col, int player);
int				ft_counthor(t_grid *grid, int col, char c);
int				ft_countldiag(t_grid *grid, int col, char c);
int				ft_countrdiag(t_grid *grid, int col, char c);
int				ft_countvert(t_grid *grid, int col, char c);
void			ft_delcoup(t_grid *grid, int col);
void			ft_error_args(char *name);
void			ft_error_size(char *height, char *width);
void			ft_fillgrid(int player, int ans, t_grid *grid);
int				ft_getplayer(void);
int				ft_gettabsize(void);
int				ft_human(t_grid *grid, int player);
int				ft_playcol(t_grid *grid, int col);
int				ft_playerbegin(void);
void			ft_printgraphique(t_grid *grid);
void			ft_printgrid(t_grid *grid);
void			ft_printwing(int fin, int player);
void			ft_simufill(t_grid *grid, int col, int player);
int				ft_tabsize(int *tab);

extern t_player	g_playertab[];

#endif

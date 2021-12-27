/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:11:05 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/05 14:22:15 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define E_ZOOM env->position->zoom
# define E_OFF_X env->position->offset_x
# define E_OFF_Y env->position->offset_y
# define ZOOM_CHECK_IN {E_ZOOM*=1.5;E_OFF_X+=1/E_ZOOM;E_OFF_Y+=1/E_ZOOM;}
# define ZOOM_CHECK_OUT {E_ZOOM/=1.5;E_OFF_X-=1/E_ZOOM;E_OFF_Y-=1/E_ZOOM;}

# define F_ERROR "incorrect formula.\nFormat: f=aZb[op: +]cCd.a,cx10-5"
# define EXTRACT_NUM num = 0;while(ft_isdigit(s[++k]))num=(num*10)+s[k]-'0'
# define F_CHECK(x, y) if(s[k]!=x&&s[k]!=y)error_quit(F_ERROR)
# define POW_CHECK if(num>50)error_quit(F_ERROR)
# define OP_CHECK if(s[k]!='+'&&s[k]!='-'&&s[k]!='*')error_quit(F_ERROR)

# include "complex.h"
# include "coord.h"
# include "env.h"

int			burningship(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot);
void		draw(t_env *env);
void		env_init(t_env *env, char *type);
void		error_quit(char *error_message);
int			expose_hook(void *param);
int			key_hook(int key, void *param);
int			mouse_hook(int x, int y, void *param);
int			julia(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot);
int			mandelbrot(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot);
void		pixel_put(t_env *env, int x, int y, unsigned int colour);
int			close_window(t_env *env);
int			mouse_hook2(int key, int x, int y, void *param);

int			init_formula(t_env *env, char *formula);
int			formula(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot);
void		rotate_colour(int key, t_env *env);

#endif

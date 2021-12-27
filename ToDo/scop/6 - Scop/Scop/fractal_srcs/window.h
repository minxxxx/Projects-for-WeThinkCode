/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:39:24 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:39:26 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct			s_window
{
	void				*mlx_window;
	void				*mlx;
	void				*img;
	char				*data;
	int					width;
	int					height;
	int					bpp;
	int					endian;
}						t_window;

#endif

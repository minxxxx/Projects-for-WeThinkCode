/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_conf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 10:33:54 by ngoguey           #+#    #+#             */
/*   Updated: 2015/12/23 13:22:49 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_CONF_H
# define SCOP_CONF_H

# include "libft.h"
# include "ftmath.h"
# include "configuration/cog_enums.h"

# define SHD_PATH(FILENAME) ("srcs/shaders/" FILENAME)
# define VSHD_PATH(FILENAME) (SHD_PATH("vshaders/" FILENAME))
# define FSHD_PATH(FILENAME) (SHD_PATH("fshaders/" FILENAME))
# define GSHD_PATH(FILENAME) (SHD_PATH("gshaders/" FILENAME))
# define TCSHD_PATH(FILENAME) (SHD_PATH("tcshaders/" FILENAME))
# define TESHD_PATH(FILENAME) (SHD_PATH("teshaders/" FILENAME))

/*
** RESSOURCES
*/
# define RESSOURCES_PATH "res/"
# define TEXTURE_PATH(FILENAME) (RESSOURCES_PATH FILENAME)

/*
** CONFIG MACROES
** ************************************************************************** **
** Land Generation Doc
** ************************************************************************** **
** /------------------------------------------------------------------\       **
** |  /=\             /-\             /=\             /-\             |       **
** |  |0|  8  (5)  8  |2|  8  (5)  8  |0|  8  (5)  8  |2|  8  (5)  8  |       **
** |  \=/             \-/             \=/             \-/             |       **
** |   9   7   9   7   9   7   9   7   9   7   9   7   9   7   9   7  |       **
** |                                                                  |       **
** |  (6)  8  (4)  8  (6)  8  (4)  8  (6)  8  (4)  8  (6)  8  (4)  8  |       **
** |                                                                  |       **
** |   9   7   9   7   9   7   9   7   9   7   9   7   9   7   9   7  |       **
** |  /-\             /-\             /-\             /-\             |       **
** |  |3|  8  (5)  8  |1|  8  (5)  8  |3|  8  (5)  8  |1|  8  (5)  8  |       **
** |  \-/             \-/             \-/             \-/             |       **
** |   9   7   9   7   9   7   9   7   9   7   9   7   9   7   9   7  |       **
** |                                                                  |       **
** |  (6)  8  (4)  8  (6)  8  (4)  8  (6)  8  (4)  8  (6)  8  (4)  8  |       **
** |                                                                  |       **
** |   9   7   9   7   9   7   9   7   9   7   9   7   9   7   9   7  |       **
** |  /=\             /-\             /=\             /-\             |       **
** |  |0|  8  (5)  8  |2|  8  (5)  8  |0|  8  (5)  8  |2|  8  (5)  8  |       **
** |  \=/             \-/             \=/             \-/             |       **
** |   9   7   9   7   9   7   9   7   9   7   9   7   9   7   9   7  |       **
** |                                                                  |       **
** |  (6)  8  (4)  8  (6)  8  (4)  8  (6)  8  (4)  8  (6)  8  (4)  8  |       **
** |                                                                  |       **
** |   9   7   9   7   9   7   9   7   9   7   9   7   9   7   9   7  |       **
** |  /-\             /-\             /-\             /-\             |       **
** |  |3|  8  (5)  8  |1|  8  (5)  8  |3|  8  (5)  8  |1|  8  (5)  8  |       **
** |  \-/             \-/             \-/             \-/             |       **
** |   9   7   9   7   9   7   9   7   9   7   9   7   9   7   9   7  |       **
** |                                                                  |       **
** |  (6)  8  (4)  8  (6)  8  (4)  8  (6)  8  (4)  8  (6)  8  (4)  8  |       **
** |                                                                  |       **
** |   9   7   9   7   9   7   9   7   9   7   9   7   9   7   9   7  |       **
** \------------------------------------------------------------------/       **
** phase 0 -> 4  values, no samples                                           **
** phase 1 -> 4  values, samples on 0                                         **
** phase 2 -> 4  values, samples on 01                                        **
** phase 3 -> 4  values, samples on 01                                        **
** phase 4 -> 16 values, samples on 0123                                      **
** phase 5 -> 16 values, samples on 01234                                     **
** phase 6 -> 16 values, samples on 01234                                     **
** phase 7 -> 64 values, samples on 0123456                                   **
** phase 8 -> 64 values, samples on 01234567                                  **
** phase 9 -> 64 values, samples on 01234567                                  **
**                                                                            **
** phase  0     -> level 0                                                    **
** phases 1,2,3 -> level 1                                                    **
** phases 4,5,6 -> level 2                                                    **
** phases 7,8,9 -> level 3                                                    **
** ************************************************************************** **
** LAND_NDEPTHLOOPSI		-> num loops after pass 0
**	pass0					-> 4points				* 1 phase, mandatory
**	loop1					-> (4) points			* 3 phases
**	loop2					-> (4 * 4) points		* 3 phases
**	loop3					-> (4 * 4 * 4) points	* 3 phases
**	loop4					-> ...
** ************************************************************************** **
** num levels				= LAND_NDEPTHLOOPSI + 1
** grid_npoints				= 4 ^ (LAND_NDEPTHLOOPSI + 1)
** grid_width(height too)	= 2 ^ (LAND_NDEPTHLOOPSI + 1)
** **
** level_npoints(0)			= 4
** level_npoints(1+)		= 4 ^ level * 3
** **
** level_nphases(0)			= 1 (custom; glFinish)
** level_nphases(1+)		= 3 (diagonal*1; glFinish; horizontal*2; glFinish)
** **
** level_stride(0)				= grid_width / 2
** phase_startoffset_row(0)		= 0
** phase_startoffset_col(0)		= 0
** level_stride(1+)				= 2 ^ (LAND_NDEPTHLOOPSI - level + 1)
** phase_startoffset_row(1+)(1)	= level_stride / 2
** phase_startoffset_col(1+)(1)	= level_stride / 2
** phase_startoffset_row(1+)(2)	= level_stride / 2
** phase_startoffset_col(1+)(2)	= 0
** phase_startoffset_row(1+)(3)	= 0
** phase_startoffset_col(1+)(3)	= level_stride / 2
*/

# define WIN_WIDTHI 1375
# define WIN_RATIOF (4.f / 3.f)
# define WIN_FOVF 45.f
# define WIN_NEARF 0.2f
# define WIN_FARF 2000.f

/* # define LAND_COLORRAND 0.05f */
# define LAND_WIDTHF 10.f
# define LAND_RANGEDECAYF 0.47
# define LAND_NDEPTHLOOPSCPI 6
# define LAND_NDEPTHLOOPSI 10 //no more than 4 diff

# define LAND_RANGEF (LAND_WIDTHF * 0.4f)
# define LAND_YF (-LAND_RANGEF / 2.f)

# define LAND_MAGNITUDECORRECTION (LAND_RANGEF * 0.57f)
# define LAND_MINYF (LAND_YF - LAND_RANGEF + LAND_MAGNITUDECORRECTION)
# define LAND_MAGNITUDEYF (LAND_RANGEF * 2 - LAND_MAGNITUDECORRECTION * 2)
# define LAND_COORDFACT ATOV3(LAND_WIDTHF, 1.f, -LAND_WIDTHF)


# define MOUSE_SENSITIVITYF 0.005f
# define MOVEMENT_SPEEDF 10.f

# define DEFAULT_CPOS_V3 ATOV3(-2.65, 1.23, 1.91)
# define DEFAULT_CANGLES (float[2]){-1.04, -0.34}
# define D_MAINOBPOS_V3 ATOV3(0.f, 0.f, 0.f)
# define D_MAINOBANGLES_V3 ATOV3(0.f, 0.f, 0.f)

# define PLANES_CENTER_V3 ATOV3(0.f, 250.f, 0.f)

# define FPS_NSAMPLESI 10

# define SUN_ROTSPEED 3.f

/*
** CALCULATED MACROES
*/
# define WIN_WIDTHF ((float)WIN_WIDTHI)
# define WIN_HALFWIDTHF (WIN_WIDTHF / 2.f)
# define WIN_HEIGHTF (WIN_WIDTHF / WIN_RATIOF)
# define WIN_HEIGHTI ROUND_FTOI(WIN_HEIGHTF)
# define WIN_HALFHEIGHTF (WIN_HEIGHTF / 2.f)


# define CAMERA_POSBOUNDF (M_PI / 2 * 0.98)
# define SUN_THETABOUNDF (M_PI / 2 * 0.98)
# define SUN_RBOUNDF (0.1f)
# define SUN_RSPEED (45.f)
# define SUN_ASPEED (3.f)

# define LAND_SIDEHALFF (LAND_SIDEF / 2.f)

# define FPS_NSAMPLESF ((float)FPS_NSAMPLESI)

#endif

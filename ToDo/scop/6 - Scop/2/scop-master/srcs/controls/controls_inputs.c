/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 11:47:48 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 18:15:20 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "scop.h"
#define CONV(...) (t_keyevents){__VA_ARGS__}
#define NORM_AT_42_IS_WTF ke->fun

static int const		g_keystates[] =
{
	GLFW_KEY_W,
	GLFW_KEY_S,
	GLFW_KEY_A,
	GLFW_KEY_D,
	GLFW_KEY_SPACE,
	GLFW_KEY_C,
	GLFW_KEY_UP,
	GLFW_KEY_DOWN,
	GLFW_KEY_LEFT,
	GLFW_KEY_RIGHT,
	GLFW_KEY_SEMICOLON,
	GLFW_KEY_P,
	GLFW_KEY_L,
	GLFW_KEY_APOSTROPHE,
	GLFW_KEY_EQUAL,
	GLFW_KEY_MINUS,
	GLFW_KEY_I,
	GLFW_KEY_O,
};

#define ALL_MOD (sp_shift_held | sp_control_held | sp_alt_held | sp_super_held)
#define HELD_AND_SHIFT (sp_is_held | sp_shift_held)
#define HELD_AND_CONTROL (sp_is_held | sp_control_held)
#define HELD_AND_ALT (sp_is_held | sp_alt_held)

static t_keyevents const	g_keyevents[] =
{
	CONV(&sp_mainme_scroll_objfile, -1, GLFW_KEY_F1, sp_is_held, 0),
	CONV(&sp_mainme_scroll_objfile, +1, GLFW_KEY_F2, sp_is_held, 0),
	CONV(&sp_mainme_toggle_recenter, 42, GLFW_KEY_F3, sp_is_held, 0),
	CONV(&sp_mainme_scroll_ebogrouping, -1, GLFW_KEY_F5, sp_is_held, 0),
	CONV(&sp_mainme_scroll_ebogrouping, +1, GLFW_KEY_F6, sp_is_held, 0),
	CONV(&sp_mainme_toggle_ebogroupingbefore, 42, GLFW_KEY_F7, sp_is_held, 0),
	CONV(&sp_mainme_scroll_texwrapping, -1, GLFW_KEY_F9, sp_is_held, 0),
	CONV(&sp_mainme_scroll_texwrapping, +1, GLFW_KEY_F10, sp_is_held, 0),
	CONV(&sp_mainme_change_texscale, -1, GLFW_KEY_F11, sp_is_held, 0),
	CONV(&sp_mainme_change_texscale, +1, GLFW_KEY_F12, sp_is_held, 0),
	CONV(&sp_kevent_toggle_mouse_state, 42, GLFW_KEY_TAB, sp_is_held, 0),
	CONV(&sp_kevent_reset_campos, 42, GLFW_KEY_R, sp_is_held, sp_control_held),
	CONV(&sp_mainob_resetpos, 42, GLFW_KEY_R, sp_is_held | sp_control_held, 0),
	CONV(&sp_kevent_mix_item, +1, GLFW_KEY_PAGE_UP, sp_is_held, 0),
	CONV(&sp_kevent_mix_item, -1, GLFW_KEY_PAGE_DOWN, sp_is_held, 0),

	CONV(&sp_sunskin_tessout, 0x7, GLFW_KEY_0, sp_is_held, ALL_MOD),
	CONV(&sp_sunskin_tessout, 0x7 | 0x8, GLFW_KEY_9, sp_is_held, ALL_MOD),
	CONV(&sp_sunskin_tessout, 0x1, GLFW_KEY_0, HELD_AND_SHIFT, 0),
	CONV(&sp_sunskin_tessout, 0x1 | 0x8, GLFW_KEY_9, HELD_AND_SHIFT, 0),
	CONV(&sp_sunskin_tessout, 0x2, GLFW_KEY_0, HELD_AND_CONTROL, 0),
	CONV(&sp_sunskin_tessout, 0x2 | 0x8, GLFW_KEY_9, HELD_AND_CONTROL, 0),
	CONV(&sp_sunskin_tessout, 0x4, GLFW_KEY_0, HELD_AND_ALT, 0),
	CONV(&sp_sunskin_tessout, 0x4 | 0x8, GLFW_KEY_9, HELD_AND_ALT, 0),
	CONV(&sp_sunskin_tessin, 1, GLFW_KEY_8, sp_is_held, 0),
	CONV(&sp_sunskin_tessin, -1, GLFW_KEY_7, sp_is_held, 0),
	CONV(&sp_sunskin_toggle_autotess, 42, GLFW_KEY_6, sp_is_held, 0),
	CONV(&sp_sunskin_scoll_colormode, 42, GLFW_KEY_K, sp_is_held, 0),
};

void		sp_keyevent(t_env *e, int a, t_keystate ks)
{
	t_keyevents const			*ke;
	t_keyevents const *const	end = END_ARRAY(g_keyevents);

	ke = g_keyevents;
	while (ke < end)
	{
		if (ke->key == a
			&& !(ks & ke->noheld) && ((ks & ke->held) == ke->held))
		{
			NORM_AT_42_IS_WTF(e, ke->dat);
			return ;
		}
		ke++;
	}
	return ;
}

void		sp_keymodrelease(t_env *e, t_keystate a)
{
	int		i;

	if (a != 0)
	{
		a = ~a;
		i = 0;
		while (i < sp_num_keys)
			e->keystates[i++] &= a;
	}
	return ;
}

void		sp_keystate(t_env *e, int a, t_keystate newstate)
{
	int		i;

	i = 0;
	while (i < sp_num_keys)
	{
		if (g_keystates[i] == a)
		{
			e->keystates[i] = newstate;
			return ;
		}
		i++;
	}
	return ;
}

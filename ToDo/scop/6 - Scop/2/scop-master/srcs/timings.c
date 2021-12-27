/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:34:08 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:34:22 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "scop.h"
#include <time.h>
#include <unistd.h>

void			sp_timings_init(t_env *e)
{
	e->time_start = glfwGetTime();
	e->time_cur = e->time_start;
	bzero(e->fps_samples, sizeof(e->fps_samples));
	e->fps_sample_index = 0;
	return ;
}

void			sp_timings_update(t_env *e)
{
	double const		last_time = e->time_cur;

	e->time_cur = glfwGetTime();
	e->fps = FPS_NSAMPLESF
		/ (e->time_cur - e->fps_samples[e->fps_sample_index]);
	e->fps_samples[e->fps_sample_index] = e->time_cur;
	e->fps_sample_index = (e->fps_sample_index + 1) % FPS_NSAMPLESI;
	e->time_el = e->time_cur - last_time;
	return ;
}

void			sp_timings_handle_nofocus(t_env *e)
{
	double		sleep_time;

	if (e->states[sp_window_focused_state] == 0)
	{
		sleep_time = 0.5f - (glfwGetTime() - e->time_cur);
		if (sleep_time > 0.f && sleep_time < 0.5)
			usleep(sleep_time * 1000000.);
	}
	return ;
}

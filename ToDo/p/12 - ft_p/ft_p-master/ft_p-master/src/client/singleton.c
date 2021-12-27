/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:16:41 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:16:41 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

t_data	*singleton_data(t_data *data)
{
	static t_data	*ret = NULL;

	if (!ret)
		ret = data;
	return (ret);
}

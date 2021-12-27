/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_fln.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 18:25:15 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:25:16 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

void	fat_fln(size_t *i, struct fat_header **header, void *data_cigam)
{
	*i = 0;
	*header = (struct fat_header*)data_cigam;
}

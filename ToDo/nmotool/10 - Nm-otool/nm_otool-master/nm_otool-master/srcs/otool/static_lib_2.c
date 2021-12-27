/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_lib_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 18:42:32 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:42:33 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

void	init_sl(uint32_t *min, uint32_t *max, struct ranlib **start,
	struct ranlib *symtab)
{
	*min = 0;
	*max = 0;
	*start = symtab;
}

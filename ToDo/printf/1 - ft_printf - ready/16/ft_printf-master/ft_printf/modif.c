/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:32:58 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:33:00 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	modif(char *p, char *modifier)
{
	if (*p == 'h' && *(p + 1) != 'h')
		(*modifier) = (*modifier) | (1 << 0);
	else if (*p == 'h' && *(p + 1) == 'h')
		(*modifier) = (*modifier) | (1 << 1);
	else if (*p == 'l' && *(p + 1) != 'l')
		(*modifier) = (*modifier) | (1 << 2);
	else if (*p == 'l' && *(p + 1) == 'l')
		(*modifier) = (*modifier) | (1 << 3);
	else if (*p == 'L')
		(*modifier) = (*modifier) | (1 << 4);
	else if (*p == 'j')
		(*modifier) = (*modifier) | (1 << 5);
	else if (*p == 'z')
		(*modifier) = (*modifier) | (1 << 6);
}

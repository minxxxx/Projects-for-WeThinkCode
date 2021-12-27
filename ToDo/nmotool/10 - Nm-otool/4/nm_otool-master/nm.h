/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:04:22 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:17:01 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include "mach.h"
# include "otool.h"

void	process_file(t_file *file, t_flags *flags, uint32_t off, int multiple);
void	get_flags(int ac, char **av, t_flags *flags);
int		get_files(int ac, char **av, t_flags *flags);
void	error_file(char *prog, int ret, char *file_name);

#endif

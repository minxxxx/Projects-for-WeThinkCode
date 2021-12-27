/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbinary.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:42:52 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:48:05 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBINARY_H
# define LIBBINARY_H

# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>

char		*map_binary(const char *file, off_t *size);
int			unmap_binary(void *addr, off_t size);
void		*convert_chunk_alloc(void *binary, size_t size);
int64_t		convert_chunk(void *binary);
uint64_t	convert_chunk_u(void *binary);

#endif

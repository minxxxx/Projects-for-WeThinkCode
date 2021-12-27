/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:16:17 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 23:07:58 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include "../libft/includes/libft.h"

void					otool(void *ptr);
void					print_addr(unsigned long long n, int boo);
void					print_output_64(struct segment_command_64 *seg,
struct mach_header_64 *header);
void					print_output_32(struct segment_command *seg,
struct mach_header *header);
void					print_byte_to_hex(char byte);
int						print_usage(char **argv);
int						error(char *file, char *str);
int						print_usage(char **argv);
void					find_fat_32(void *ptr);
void					find_fat_64(void *ptr);
void					handle_64(struct mach_header_64 *header);
void					handle_32(struct mach_header *header);

#endif

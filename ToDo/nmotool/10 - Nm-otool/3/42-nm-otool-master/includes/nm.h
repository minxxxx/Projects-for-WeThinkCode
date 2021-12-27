/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:25:24 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 22:52:37 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <mach-o/fat.h>
# include "../libft/includes/libft.h"

typedef struct			s_lt
{
	unsigned long long	value;
	char				*str;
	uint8_t				type;
	uint8_t				sect;
	struct s_lt			*next;
}						t_lt;

void					nm(void *ptr);
void					print_output_32(struct symtab_command *sym,
	void *ptr, char **tab);
void					print_output_64(struct symtab_command *sym,
	void *ptr, char **tab);
void					add_list_32(t_lt **lt, char *str, struct nlist array);
void					add_list_64(t_lt **lt, char *str,
	struct nlist_64 array);
void					find_fat_32(void *ptr);
void					find_fat_64(void *ptr);
void					print_addr(unsigned long long n, int boo);
void					print_letter(t_lt *lt, char **tab);
char					**get_tab_64(char **tabl,
	struct segment_command_64 *seg);
char					**get_tab_32(char **tabl,
	struct segment_command *seg);
int						reverse_endian(int x);
int						error(char *file, char *str);
int						print_usage(char **argv);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 11:08:41 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/28 18:20:42 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define F(b, c, d) ((b & c) | (~b & d))
# define G(b, c, d) ((b & d) | (c & ~d))
# define H(b, c, d) (b ^ c ^ d)
# define I(b, c, d) (c ^ (b | ~d))
# define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
# define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SHR(x, n) ((x) >> n)
# define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
# define A(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
# define B(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
# define C(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
# define D(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))
# define HASH (const char*[7]){"md5","sha256","base64","des-ecb","des-cbc",NULL}
# define DEBUG 1
# define BUFFER 1024
# include <stdint.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include <errno.h>
# include <string.h>

typedef struct		s_mem
{
	unsigned char	*data;
	unsigned int	h[8];
	int				len;
}					t_mem;

typedef struct		s_arg
{
	char			*str;
	int				is_string;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_opt
{
	int				hash;
	struct s_arg	*arg;
	long			key;
	long			vector;
	long			pass;
	long			salt;
	char			*output;
	int				stdin;
	int				p;
	int				d;
	int				i;
	int				o;
	int				q;
	int				r;
	int				a;
	int				s;
	int				k;
	int				v;
	int				fd;
}					t_opt;

typedef struct		s_i
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	t;
	unsigned int	t2;
}					t_i;

typedef void		(*t_hash)(t_mem *mem, t_opt *opt);

int					genrsa(t_opt *opt);
void				ft_free_mem(t_mem *mem);
t_mem				*ft_memjoin(t_mem *dest, t_mem *src);
t_mem				*read_fd(int fd);
void				write_fd(int fd, t_mem *mem);
int					print_usage(char *str);
void				print_output_md5(t_mem *mem, t_opt *opt);
void				print_output_sha256(t_mem *mem, t_opt *opt);
void				write_file_error(char *file, t_opt *opt);
void				write_prefix(t_opt *opt, t_arg *arg);
void				write_suffix(t_arg *arg);
t_opt				*add_arg(t_opt *opt, char *str);
t_opt				*check_options(t_opt *opt, char *str);
t_opt				*check_opt(t_opt *opt, char **argv);
t_mem				*padding_md5(t_mem *mem);
void				md5_process(t_i *m, uint32_t *w, int i);
void				hash_md5(t_mem *mem, t_opt *opt);
void				hash_des(t_mem *mem, t_opt *opt);
t_mem				*padding_sha256(t_mem *mem);
void				hash_sha256(t_mem *mem, t_opt *opt);
void				init_mem(t_mem *mem);
uint64_t			swap_uint64(uint64_t val);
void				print_output_base64(t_mem *mem);
t_mem				*padding_base64(t_mem *mem);
void				hash_base64(t_mem *mem, t_opt *opt);
void				opt_init(t_opt *opt);
void				set_flags(t_opt *opt, char c);
void				open_fd(t_opt *opt);
void				print_base64_encode(t_opt *opt, int value, int which);
t_mem				*print_base64_decode(t_mem *mem, int i, int which);
void				base64_encode(t_mem *mem, t_opt *opt);
t_mem				*base64_decode(t_mem *mem);
char				*padding_key(char *str);
int					get_hash_index(char *hash);
void				create_subkeys(t_opt *opt);
long				ft_function_s(long xor);
long				ft_msg_to_long(char *data, int len);
long				permute(long to_permute, int32_t *tab, int length);
long				generate_subkeys(long message, t_opt *opt);
void				generate_key(t_opt *opt);
t_mem				*create_message(long ret);
long				do_subkey(long right, int i);
void				push_arg_list(t_opt *opt, t_arg *arg);
t_mem				*des_encode_boucle(t_opt *opt, t_mem *mem);
#endif

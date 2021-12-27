/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:38:20 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 09:38:21 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_DES_H
# define FT_SSL_DES_H
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# define UL unsigned long
# define UC unsigned char
# define DES_E 0
# define DES_D 1
# define BUFFR 1024
# define BASE64_LINE 64

/*
** ****************************************************************************
** ************************ struct for func pointers **************************
** ****************************************************************************
*/

typedef struct	s_ssl_mngr
{
	char		conver[10];
	void		(*mngr)(int, char**, int);
}				t_ssl_mngr;

/*
** ****************************************************************************
** **************************** struct for data *******************************
** ****************************************************************************
*/

typedef struct	s_ssl
{
	int		enc;
	int		dec;
	int		b64;
	int		print;
	UL		master_key;
	UL		master_iv;
	char	*key;
	char	*iv;
	char	*inp;
	char	*out;
	UL		des3_key1;
	UL		des3_key2;
	UL		des3_key3;
}				t_ssl;

/*
** ****************************************************************************
** ***************************** manageflags.c ********************************
** ****************************************************************************
*/

void			error_flags(char *str);
void			print_error(char **argv);
void			exit_error(int err, void *memory);
void			flag_parser(int argc, char **argv, int i, int flag);
void			read_input(t_ssl *opt, UC **inp, size_t *size);

/*
** ****************************************************************************
** ***************************** managetypes.c ********************************
** ****************************************************************************
*/

void			create_data(t_ssl *data);
void			handle_flags(int i, int argc, char **argv, t_ssl *data);
void			start_base64(int argc, char **argv, int i);
void			start_ecb(int argc, char **argv, int i);
void			start_cbc(int argc, char **argv, int i);

/*
** ****************************************************************************
** ***************************** base64_core.c ********************************
** ****************************************************************************
*/

unsigned char	b64manage(UC c, UC *inp, UC *out);
size_t			b64decode(UC *inp, UC *out, size_t size);
unsigned char	*base64decode(UC *inp, size_t *size);
void			b64encode(UC *inp, UC *out, size_t size);
unsigned char	*base64encode(UC *inp, size_t *size);

/*
** ****************************************************************************
** ***************************** base64_func.c ********************************
** ****************************************************************************
*/

unsigned char	*b64_insert_newlines(UC *inp, size_t *size);
unsigned char	*b64_remove_newlines(UC *inp, size_t *size);

/*
** ****************************************************************************
** ***************************** reader_file.c ********************************
** ****************************************************************************
*/

ssize_t			allocsize(char *file);
void			*readoutfile(char *file, size_t *size);
void			printinfile(char *file, UC *str, size_t size);

/*
** ****************************************************************************
** ***************************** supportfunc.c ********************************
** ****************************************************************************
*/

unsigned char	*input_read(size_t *a);
unsigned char	*input_read_line(size_t *a);
int				check_hex(unsigned char *str);
unsigned long	hex_to_ul64(unsigned char *str);

/*
** ****************************************************************************
** ***************************** desecb_algo.c ********************************
** ****************************************************************************
*/
unsigned long	make_gip(unsigned long gip);
unsigned long	make_gep(unsigned long gep);
unsigned long	make_gsb(unsigned long gsb);
unsigned long	make_gpp(unsigned long gpp);
unsigned long	make_gfp(unsigned long gfp);

/*
** ****************************************************************************
** ***************************** desecb_core.c ********************************
** ****************************************************************************
*/

unsigned long	ecb_body(UL inp, UL keys[16]);
unsigned long	ecb_get_8(unsigned char *data);
void			ecb_put_8(unsigned char *data, UL ul64);
void			ecb_core(UC **inp, size_t size, UL mk, int flag);

/*
** ****************************************************************************
** ***************************** desecb_keys.c ********************************
** ****************************************************************************
*/

unsigned long	make_gkp(unsigned long a);
unsigned long	mutat_shift_left(unsigned long key, int bits);
void			make_half_keys(unsigned long half_keys[16], UL starter);
unsigned long	make_gcp(unsigned long c_half, unsigned long d_half);
void			make_keys(unsigned long keys[16], UL master_key, int flag);

/*
** ****************************************************************************
** ***************************** desecb_func.c ********************************
** ****************************************************************************
*/

void			ecb_show_key(unsigned long master_key);
void			ecb_e_inp(t_ssl *data, UC **inp, UC **out, size_t *size);
void			ecb_d_inp(t_ssl *data, UC **inp, UC **out, size_t *size);
void			ecb_hex_error(void *memory);
unsigned long	ecb_read_key(t_ssl *data);

/*
** ****************************************************************************
** ***************************** descbc_func.c ********************************
** ****************************************************************************
*/

unsigned long	cbc_get_iv(t_ssl *data);
void			cbc_encrypt_inp(t_ssl *data, UC **inp, UC **out, size_t *size);
void			cbc_decrypt_inp(t_ssl *data, UC **inp, UC **out, size_t *size);

/*
** ****************************************************************************
** ***************************** descbc_core.c ********************************
** ****************************************************************************
*/

void			cbc_showkey(unsigned long master_key);
void			cbc_print_key(t_ssl ssl);
void			cbc_encrypt(UC **inp, size_t size, t_ssl *ssl, int flag);
void			cbc_decrypt(UC **inp, size_t size, t_ssl *ssl, int flag);

/*
** ****************************************************************************
** ****************************** BONUS PART **********************************
** ****************************************************************************
*/

/*
** ****************************************************************************
** ***************************** ebccbc3core.c ********************************
** ****************************************************************************
*/

void			get_triple_key(unsigned char *str, t_ssl *data);
void			des3_get_key(t_ssl *data);
void			des3_print_key(t_ssl *data, int show_iv);
void			start_des3ecb(int argc, char **argv, int i);
void			start_des3cbc(int argc, char **argv, int i);

/*
** ****************************************************************************
** ***************************** desebc3algo.c ********************************
** ****************************************************************************
*/

void			des3ecb_e(UC **inp, size_t size, t_ssl *data);
void			des3ecb_d(UC **inp, size_t size, t_ssl *data);
void			des3ecb_e_inp(t_ssl *data, UC **in, UC **out, size_t *size);
void			des3ecb_d_inp(t_ssl *data, UC **in, UC **out, size_t *size);

/*
** ****************************************************************************
** ***************************** descbc3algo.c ********************************
** ****************************************************************************
*/

void			des3cbc_e(UC **inp, size_t size, t_ssl *data);
void			des3cbc_d(UC **inp, size_t size, t_ssl *data, UL iv);
void			des3cbc_e_inp(t_ssl *data, UC **inp, UC **out, size_t *size);
void			des3cbc_d_inp(t_ssl *data, UC **inp, UC **out, size_t *size);

/*
** ****************************************************************************
** ****************************** FT_SSL_MD5 **********************************
** ****************************************************************************
*/

/*
** ****************************************************************************
** ************************** struct for MD data ******************************
** ****************************************************************************
*/

typedef struct	s_md
{
	int		s;
	int		pfl;
	int		qfl;
	int		rfl;
	int		file;
	int		howuse;
	int		needfree;
	UC		*str;
}				t_md;

/*
** ****************************************************************************
** ***************************** managemdtps.c ********************************
** ****************************************************************************
*/

void			start_md(int argc, char **argv, int md);
void			start_md5(char *argv, t_md *data, int md);
void			start_sha256(char *argv, t_md *data, int md);
void			start_whirlpool(char *argv, t_md *data, int md);

/*
** ****************************************************************************
** ***************************** supportmdcd.c ********************************
** ****************************************************************************
*/

void			create_md_data(t_md *data);
void			check_md_flags(int argc, char **argv, t_md *data, int md);
void			print_md_str(t_md *data, unsigned char *name, int md);
void			print_md_str2(t_md *data, unsigned char *name);
#endif

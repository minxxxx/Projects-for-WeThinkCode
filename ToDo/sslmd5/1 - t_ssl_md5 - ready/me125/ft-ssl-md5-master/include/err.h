/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:02:30 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 13:02:31 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H
# define WP "   whirlpool\n"
# define ER00 "ft_ssl: Error: \""
# define ER01 "\" is an invalid command.\n"
# define ER02 "ERROR! '"
# define ER10 "Standard commands:\n\n"
# define ER11 "Message Digest commands:\n   md5\n   sha256\n"WP
# define ER12 "Cipher commands:\n   base64\n   des\n   des-ecb\n   des-cbc\n"
# define ER13 "   des3\n   des3-ecb\n   des3-cbc\n"
# define ER30 "ft_ssl: option requires an argument\n"
# define ER31 "   -e,  encrypt mode (default, with all cipher commands)\n"
# define ER32 "   -d,  decrypt mode (with all cipher commands)\n"
# define ER33 "   -a,  base64 encode/decode (with DES algorithms)\n"
# define ER34 "   -k,  key in hex is the next arguement (with DES algorithms)\n"
# define ER35 "   -v,  iv in hex is the next argument (with DES algorithms)\n"
# define ER36 "   -p,  print the iv/key (with DES algorithms)\n"
# define ER37 "   -i,  example: \"-i [input_file_name]\" (default STDIN)\n"
# define ER38 "   -o,  example: \"-o [output_file_name]\" (default STDOUT)\n"
# define ER40 "md -p,  echo STDIN to STDOUT and append the checksum to STDOUT\n"
# define ER41 "md -q,  quiet mode\n"
# define ER42 "md -r,  reverse the format of the output\n"
# define ER43 "md -s,  print the sum of the given string\n"
# define ERRS ER31, ER32, ER33, ER34, ER35, ER36
# define ERRM ER37, ER38
# define ERP1 ER00, argv[1], ER01, ER10, ER11, ER12, ER13
# define ERP2 ER02, str, ER01, ER30, ERRS, ERRM, ER40, ER41, ER42, ER43
#endif

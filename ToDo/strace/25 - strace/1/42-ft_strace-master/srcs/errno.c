/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:35:12 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/17 15:35:15 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_strace.h"

char *get_errno_name(int key)
{
	key = 0 - key;
	switch (key) {
		case (ENOENT):
			return ft_strjoin_nf(ft_strjoin("ENOENT (", strerror(ENOENT)), ")", 1);
		case EPERM:
			return ft_strjoin_nf(ft_strjoin("EPERM (" , strerror(EPERM)), ")", 1);
		case ESRCH:
			return ft_strjoin_nf(ft_strjoin("ESRCH (" , strerror(ESRCH)), ")", 1);
		case EINTR:
			return ft_strjoin_nf(ft_strjoin("EINTR (" , strerror(EINTR)), ")", 1);
		case EIO:
			return ft_strjoin_nf(ft_strjoin("EIO: (" , strerror(EIO)), ")", 1);
		case ENXIO:
			return ft_strjoin_nf(ft_strjoin("ENXIO (" , strerror(ENXIO)), ")", 1);
		case E2BIG:
			return ft_strjoin_nf(ft_strjoin("E2BIG (" , strerror(E2BIG)), ")", 1);
		case ENOEXEC:
			return ft_strjoin_nf(ft_strjoin("ENOEXEC (" , strerror(ENOEXEC)), ")", 1);
		case EBADF:
			return ft_strjoin_nf(ft_strjoin("EBADF (" , strerror(EBADF)), ")", 1);
		case ECHILD:
			return ft_strjoin_nf(ft_strjoin("ECHILD (" , strerror(ECHILD)), ")", 1);
		case EDEADLK:
			return ft_strjoin_nf(ft_strjoin("EDEADLK (" , strerror(EDEADLK)), ")", 1);
		case ENOMEM:
			return ft_strjoin_nf(ft_strjoin("ENOMEM (" , strerror(ENOMEM)), ")", 1);
		case EACCES:
			return ft_strjoin_nf(ft_strjoin("EACCES (" , strerror(EACCES)), ")", 1);
		case EFAULT:
			return ft_strjoin_nf(ft_strjoin("EFAULT (" , strerror(EFAULT)), ")", 1);
		case ENOTBLK:
			return ft_strjoin_nf(ft_strjoin("ENOTBLK (" , strerror(ENOTBLK)), ")", 1);
		case EBUSY:
			return ft_strjoin_nf(ft_strjoin("EBUSY (" , strerror(EBUSY)), ")", 1);
		case EEXIST:
			return ft_strjoin_nf(ft_strjoin("EEXIST (" , strerror(EEXIST)), ")", 1);
		case EXDEV:
			return ft_strjoin_nf(ft_strjoin("EXDEV (" , strerror(EXDEV)), ")", 1);
		case ENODEV:
			return ft_strjoin_nf(ft_strjoin("ENODEV (" , strerror(ENODEV)), ")", 1);
		case ENOTDIR:
			return ft_strjoin_nf(ft_strjoin("ENOTDIR (" , strerror(ENOTDIR)), ")", 1);
		case EISDIR:
			return ft_strjoin_nf(ft_strjoin("EISDIR (" , strerror(EISDIR)), ")", 1);
		case EINVAL:
			return ft_strjoin_nf(ft_strjoin("EINVAL (" , strerror(EINVAL)), ")", 1);
		case EMFILE:
			return ft_strjoin_nf(ft_strjoin("EMFILE (" , strerror(EMFILE)), ")", 1);
		case ENFILE:
			return ft_strjoin_nf(ft_strjoin("ENFILE (" , strerror(ENFILE)), ")", 1);
		case ENOTTY:
			return ft_strjoin_nf(ft_strjoin("ENOTTY (" , strerror(ENOTTY)), ")", 1);
		case ETXTBSY:
			return ft_strjoin_nf(ft_strjoin("ETXTBSY (" , strerror(ETXTBSY)), ")", 1);
		case EFBIG:
			return ft_strjoin_nf(ft_strjoin("EFBIG (" , strerror(EFBIG)), ")", 1);
		case ENOSPC:
			return ft_strjoin_nf(ft_strjoin("ENOSPC (" , strerror(ENOSPC)), ")", 1);
		case ESPIPE:
			return ft_strjoin_nf(ft_strjoin("ESPIPE (" , strerror(ESPIPE)), ")", 1);
		case EROFS:
			return ft_strjoin_nf(ft_strjoin("EROFS (" , strerror(EROFS)), ")", 1);
		case EMLINK:
			return ft_strjoin_nf(ft_strjoin("EMLINK (" , strerror(EMLINK)), ")", 1);
		case EPIPE:
			return ft_strjoin_nf(ft_strjoin("EPIPE (" , strerror(EPIPE)), ")", 1);
		case EDOM:
			return ft_strjoin_nf(ft_strjoin("EDOM: (" , strerror(EDOM)), ")", 1);
		case ERANGE:
			return ft_strjoin_nf(ft_strjoin("ERANGE (" , strerror(ERANGE)), ")", 1);
		case EAGAIN:
			return ft_strjoin_nf(ft_strjoin("EAGAIN (" , strerror(EAGAIN)), ")", 1);
		case EINPROGRESS:
			return ft_strjoin_nf(ft_strjoin("EINPROGRESS (" , strerror(EINPROGRESS)), ")", 1);
		case EALREADY:
			return ft_strjoin_nf(ft_strjoin("EALREADY (" , strerror(EALREADY)), ")", 1);
		case ENOTSOCK:
			return ft_strjoin_nf(ft_strjoin("ENOTSOCK (" , strerror(ENOTSOCK)), ")", 1);
		case EMSGSIZE:
			return ft_strjoin_nf(ft_strjoin("EMSGSIZE (" , strerror(EMSGSIZE)), ")", 1);
		case EPROTOTYPE:
			return ft_strjoin_nf(ft_strjoin("EPROTOTYPE (" , strerror(EPROTOTYPE)), ")", 1);
		case ENOPROTOOPT:
			return ft_strjoin_nf(ft_strjoin("ENOPROTOOPT (" , strerror(ENOPROTOOPT)), ")", 1);
		case EPROTONOSUPPORT:
			return ft_strjoin_nf(ft_strjoin("EPROTONOSUPPORT (" , strerror(EPROTONOSUPPORT)), ")", 1);
		case ESOCKTNOSUPPORT:
			return ft_strjoin_nf(ft_strjoin("ESOCKTNOSUPPORT (" , strerror(ESOCKTNOSUPPORT)), ")", 1);
		case EOPNOTSUPP:
			return ft_strjoin_nf(ft_strjoin("EOPNOTSUPP (" , strerror(EOPNOTSUPP)), ")", 1);
		case EPFNOSUPPORT:
			return ft_strjoin_nf(ft_strjoin("EPFNOSUPPORT (" , strerror(EPFNOSUPPORT)), ")", 1);
		case EAFNOSUPPORT:
			return ft_strjoin_nf(ft_strjoin("EAFNOSUPPORT (" , strerror(EAFNOSUPPORT)), ")", 1);
		case EADDRINUSE:
			return ft_strjoin_nf(ft_strjoin("EADDRINUSE (" , strerror(EADDRINUSE)), ")", 1);
		case EADDRNOTAVAIL:
			return ft_strjoin_nf(ft_strjoin("EADDRNOTAVAIL (" , strerror(EADDRNOTAVAIL)), ")", 1);
		case ENETDOWN:
			return ft_strjoin_nf(ft_strjoin("ENETDOWN (" , strerror(ENETDOWN)), ")", 1);
		case ENETUNREACH:
			return ft_strjoin_nf(ft_strjoin("ENETUNREACH (" , strerror(ENETUNREACH)), ")", 1);
		case ENETRESET:
			return ft_strjoin_nf(ft_strjoin("ENETRESET (" , strerror(ENETRESET)), ")", 1);
		case ECONNABORTED:
			return ft_strjoin_nf(ft_strjoin("ECONNABORTED (" , strerror(ECONNABORTED)), ")", 1);
		case ECONNRESET:
			return ft_strjoin_nf(ft_strjoin("ECONNRESET (" , strerror(ECONNRESET)), ")", 1);
		case ENOBUFS:
			return ft_strjoin_nf(ft_strjoin("ENOBUFS (" , strerror(ENOBUFS)), ")", 1);
		case EISCONN:
			return ft_strjoin_nf(ft_strjoin("EISCONN (" , strerror(EISCONN)), ")", 1);
		case ENOTCONN:
			return ft_strjoin_nf(ft_strjoin("ENOTCONN (" , strerror(ENOTCONN)), ")", 1);
		case EDESTADDRREQ:
			return ft_strjoin_nf(ft_strjoin("EDESTADDRREQ (" , strerror(EDESTADDRREQ)), ")", 1);
		case ESHUTDOWN:
			return ft_strjoin_nf(ft_strjoin("ESHUTDOWN (" , strerror(ESHUTDOWN)), ")", 1);
		case ETOOMANYREFS:
			return ft_strjoin_nf(ft_strjoin("ETOOMANYREFS (" , strerror(ETOOMANYREFS)), ")", 1);
		case ETIMEDOUT:
			return ft_strjoin_nf(ft_strjoin("ETIMEDOUT (" , strerror(ETIMEDOUT)), ")", 1);
		case ECONNREFUSED:
			return ft_strjoin_nf(ft_strjoin("ECONNREFUSED (" , strerror(ECONNREFUSED)), ")", 1);
		case ELOOP:
			return ft_strjoin_nf(ft_strjoin("ELOOP (" , strerror(ELOOP)), ")", 1);
		case ENAMETOOLONG:
			return ft_strjoin_nf(ft_strjoin("ENAMETOOLONG (" , strerror(ENAMETOOLONG)), ")", 1);
		case EHOSTDOWN:
			return ft_strjoin_nf(ft_strjoin("EHOSTDOWN (" , strerror(EHOSTDOWN)), ")", 1);
		case EHOSTUNREACH:
			return ft_strjoin_nf(ft_strjoin("EHOSTUNREACH (" , strerror(EHOSTUNREACH)), ")", 1);
		case ENOTEMPTY:
			return ft_strjoin_nf(ft_strjoin("ENOTEMPTY (" , strerror(ENOTEMPTY)), ")", 1);
		case EUSERS:
			return ft_strjoin_nf(ft_strjoin("EUSERS (" , strerror(EUSERS)), ")", 1);
		case EDQUOT:
			return ft_strjoin_nf(ft_strjoin("EDQUOT (" , strerror(EDQUOT)), ")", 1);
		case ESTALE:
			return ft_strjoin_nf(ft_strjoin("ESTALE (" , strerror(ESTALE)), ")", 1);
		case EREMOTE:
			return ft_strjoin_nf(ft_strjoin("EREMOTE (" , strerror(EREMOTE)), ")", 1);
		case ENOLCK:
			return ft_strjoin_nf(ft_strjoin("ENOLCK (" , strerror(ENOLCK)), ")", 1);
		case ENOSYS:
			return ft_strjoin_nf(ft_strjoin("ENOSYS (" , strerror(ENOSYS)), ")", 1);
		case EILSEQ:
			return ft_strjoin_nf(ft_strjoin("EILSEQ (" , strerror(EILSEQ)), ")", 1);
		case EBADMSG:
			return ft_strjoin_nf(ft_strjoin("EBADMSG (" , strerror(EBADMSG)), ")", 1);
		case EIDRM:
			return ft_strjoin_nf(ft_strjoin("EIDRM (" , strerror(EIDRM)), ")", 1);
		case EMULTIHOP:
			return ft_strjoin_nf(ft_strjoin("EMULTIHOP (" , strerror(EMULTIHOP)), ")", 1);
		case ENODATA:
			return ft_strjoin_nf(ft_strjoin("ENODATA (" , strerror(ENODATA)), ")", 1);
		case ENOLINK:
			return ft_strjoin_nf(ft_strjoin("ENOLINK (" , strerror(ENOLINK)), ")", 1);
		case ENOMSG:
			return ft_strjoin_nf(ft_strjoin("ENOMSG (" , strerror(ENOMSG)), ")", 1);
		case ENOSR:
			return ft_strjoin_nf(ft_strjoin("ENOSR (" , strerror(ENOSR)), ")", 1);
		case ENOSTR:
			return ft_strjoin_nf(ft_strjoin("ENOSTR (" , strerror(ENOSTR)), ")", 1);
		case EOVERFLOW:
			return ft_strjoin_nf(ft_strjoin("EOVERFLOW (" , strerror(EOVERFLOW)), ")", 1);
		case EPROTO:
			return ft_strjoin_nf(ft_strjoin("EPROTO (" , strerror(EPROTO)), ")", 1);
		case ETIME:
			return ft_strjoin_nf(ft_strjoin("ETIME (" , strerror(ETIME)), ")", 1);
		case ECANCELED:
			return ft_strjoin_nf(ft_strjoin("ECANCELED (" , strerror(ECANCELED)), ")", 1);
		case EOWNERDEAD:
			return ft_strjoin_nf(ft_strjoin("EOWNERDEAD (" , strerror(EOWNERDEAD)), ")", 1);
		case ENOTRECOVERABLE:
			return ft_strjoin_nf(ft_strjoin("ENOTRECOVERABLE (" , strerror(ENOTRECOVERABLE)), ")", 1);
		case ERESTART:
			return ft_strjoin_nf(ft_strjoin("ERESTART (" , strerror(ERESTART)), ")", 1);
		case ECHRNG:
			return ft_strjoin_nf(ft_strjoin("ECHRNG (" , strerror(ECHRNG)), ")", 1);
		case EL2NSYNC:
			return ft_strjoin_nf(ft_strjoin("EL2NSYNC (" , strerror(EL2NSYNC)), ")", 1);
		case EL3HLT:
			return ft_strjoin_nf(ft_strjoin("EL3HLT (" , strerror(EL3HLT)), ")", 1);
		case EL3RST:
			return ft_strjoin_nf(ft_strjoin("EL3RST (" , strerror(EL3RST)), ")", 1);
		case ELNRNG:
			return ft_strjoin_nf(ft_strjoin("ELNRNG (" , strerror(ELNRNG)), ")", 1);
		case EUNATCH:
			return ft_strjoin_nf(ft_strjoin("EUNATCH (" , strerror(EUNATCH)), ")", 1);
		case ENOCSI:
			return ft_strjoin_nf(ft_strjoin("ENOCSI (" , strerror(ENOCSI)), ")", 1);
		case EL2HLT:
			return ft_strjoin_nf(ft_strjoin("EL2HLT (" , strerror(EL2HLT)), ")", 1);
		case EBADE:
			return ft_strjoin_nf(ft_strjoin("EBADE (" , strerror(EBADE)), ")", 1);
		case EBADR:
			return ft_strjoin_nf(ft_strjoin("EBADR (" , strerror(EBADR)), ")", 1);
		case EXFULL:
			return ft_strjoin_nf(ft_strjoin("EXFULL (" , strerror(EXFULL)), ")", 1);
		case ENOANO:
			return ft_strjoin_nf(ft_strjoin("ENOANO (" , strerror(ENOANO)), ")", 1);
		case EBADRQC:
			return ft_strjoin_nf(ft_strjoin("EBADRQC (" , strerror(EBADRQC)), ")", 1);
		case EBADSLT:
			return ft_strjoin_nf(ft_strjoin("EBADSLT (" , strerror(EBADSLT)), ")", 1);
		case EBFONT:
			return ft_strjoin_nf(ft_strjoin("EBFONT (" , strerror(EBFONT)), ")", 1);
		case ENONET:
			return ft_strjoin_nf(ft_strjoin("ENONET (" , strerror(ENONET)), ")", 1);
		case ENOPKG:
			return ft_strjoin_nf(ft_strjoin("ENOPKG (" , strerror(ENOPKG)), ")", 1);
		case EADV:
			return ft_strjoin_nf(ft_strjoin("EADV (" , strerror(EADV)), ")", 1);
		case ESRMNT:
			return ft_strjoin_nf(ft_strjoin("ESRMNT (" , strerror(ESRMNT)), ")", 1);
		case ECOMM:
			return ft_strjoin_nf(ft_strjoin("ECOMM (" , strerror(ECOMM)), ")", 1);
		case EDOTDOT:
			return ft_strjoin_nf(ft_strjoin("EDOTDOT (" , strerror(EDOTDOT)), ")", 1);
		case ENOTUNIQ:
			return ft_strjoin_nf(ft_strjoin("ENOTUNIQ (" , strerror(ENOTUNIQ)), ")", 1);
		case EBADFD:
			return ft_strjoin_nf(ft_strjoin("EBADFD (" , strerror(EBADFD)), ")", 1);
		case EREMCHG:
			return ft_strjoin_nf(ft_strjoin("EREMCHG (" , strerror(EREMCHG)), ")", 1);
		case ELIBACC:
			return ft_strjoin_nf(ft_strjoin("ELIBACC (" , strerror(ELIBACC)), ")", 1);
		case ELIBBAD:
			return ft_strjoin_nf(ft_strjoin("ELIBBAD (" , strerror(ELIBBAD)), ")", 1);
		case ELIBSCN:
			return ft_strjoin_nf(ft_strjoin("ELIBSCN (" , strerror(ELIBSCN)), ")", 1);
		case ELIBMAX:
			return ft_strjoin_nf(ft_strjoin("ELIBMAX (" , strerror(ELIBMAX)), ")", 1);
		case ELIBEXEC:
			return ft_strjoin_nf(ft_strjoin("ELIBEXEC (" , strerror(ELIBEXEC)), ")", 1);
		case ESTRPIPE:
			return ft_strjoin_nf(ft_strjoin("ESTRPIPE (" , strerror(ESTRPIPE)), ")", 1);
		case EUCLEAN:
			return ft_strjoin_nf(ft_strjoin("EUCLEAN (" , strerror(EUCLEAN)), ")", 1);
		case ENOTNAM:
			return ft_strjoin_nf(ft_strjoin("ENOTNAM (" , strerror(ENOTNAM)), ")", 1);
		case ENAVAIL:
			return ft_strjoin_nf(ft_strjoin("ENAVAIL (" , strerror(ENAVAIL)), ")", 1);
		case EISNAM:
			return ft_strjoin_nf(ft_strjoin("EISNAM (" , strerror(EISNAM)), ")", 1);
		case EREMOTEIO:
			return ft_strjoin_nf(ft_strjoin("EREMOTEIO (" , strerror(EREMOTEIO)), ")", 1);
		case ENOMEDIUM:
			return ft_strjoin_nf(ft_strjoin("ENOMEDIUM (" , strerror(ENOMEDIUM)), ")", 1);
		case EMEDIUMTYPE:
			return ft_strjoin_nf(ft_strjoin("EMEDIUMTYPE (" , strerror(EMEDIUMTYPE)), ")", 1);
		case ENOKEY:
			return ft_strjoin_nf(ft_strjoin("ENOKEY (" , strerror(ENOKEY)), ")", 1);
		case EKEYEXPIRED:
			return ft_strjoin_nf(ft_strjoin("EKEYEXPIRED (" , strerror(EKEYEXPIRED)), ")", 1);
		case EKEYREVOKED:
			return ft_strjoin_nf(ft_strjoin("EKEYREVOKED (" , strerror(EKEYREVOKED)), ")", 1);
		case EKEYREJECTED:
			return ft_strjoin_nf(ft_strjoin("EKEYREJECTED (" , strerror(EKEYREJECTED)), ")", 1);
		case ERFKILL:
			return ft_strjoin_nf(ft_strjoin("ERFKILL (" , strerror(ERFKILL)), ")", 1);
		case EHWPOISON:
			return ft_strjoin_nf(ft_strjoin("EHWPOISON (" , strerror(EHWPOISON)), ")", 1);
		default:
			return "errno not found";
	}
}


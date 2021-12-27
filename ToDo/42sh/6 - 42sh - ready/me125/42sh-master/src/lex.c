/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ush/lex.h"
#include "ush/shell.h"
#include "ush/syn.h"

static inline t_tok	*tokpos(t_tok *tok, char const *it, char const *ln)
{
	tok->pos = (uint16_t)(it - ln);
	return (tok);
}

static inline int	tokenize(t_src *s, t_tok *tok)
{
	int st;

	tokpos(tok, *s->it, *s->ln);
	ft_isdigit(**s->it) ? (void)(++tok->len && ++*s->it) : 0;
	if (((st = sh_lexop(s, tok)) != NOP ||
		(st = sh_lexword(s, tok)) != NOP))
		return (st);
	return (sh_synerr(*s->ln, *s->it, "Unexpected token `%c'", **s->it));
}

inline int			sh_lexbslash(t_src *s)
{
	int st;

	if (**s->it == '\\' &&
		((sh_isreol(*s->it + 1) && !*(*s->it + 2)) ||
		((sh_isweol(*s->it + 1) && !*(*s->it + 3)))))
	{
		*s->it += sh_isreol(*s->it + 1) ? 2 : 3;
		if (s->fd >= 0 && (st = rl_catline(s->fd, -2, s->ln, s->it)))
			return (st);
	}
	return (YEP);
}

inline int			sh_tokenize(t_src *s, t_tok *tok)
{
	int st;

	while (1)
		if (**s->it == '\\' &&
			((sh_isreol(*s->it + 1) && !*(*s->it + 2)) ||
			((sh_isweol(*s->it + 1) && !*(*s->it + 3)))))
		{
			*s->it += sh_isreol(*s->it + 1) ? 2 : 3;
			if (s->fd >= 0 && (st = rl_catline(s->fd, -2, s->ln, s->it)))
				return (st);
		}
		else if (**s->it && ft_strchr(sh_ifs(), **s->it))
			++*s->it;
		else if (sh_iseol(*s->it))
			return (((tokpos(tok, (*s->it)++, *s->ln)->id = '\n')) & 0);
		else if (**s->it == '#')
			while (**s->it && !sh_iseol(*s->it))
				++*s->it;
		else if (!**s->it)
			return ((tokpos(tok, *s->it, *s->ln)->id = TOK_END) & 0);
		else
			return (tokenize(s, tok));
}

int					sh_lex(int fd, char **it, char **ln, t_lexcb *cb)
{
	t_src	src;
	t_deq	deq;
	t_tok	*tok;
	int		st;

	if (!*it || !**it)
		return (NOP);
	src.fd = fd;
	src.it = it;
	src.ln = ln ? ln : it;
	ft_deqctor(&deq, sizeof(t_tok));
	while (!(st = sh_lexline(&src, &deq, 0)))
	{
		if (ft_deqlen(&deq) == 1 && (tok = sh_tokpeek(&deq)) && tok->id == '\n')
			continue ;
		if (sh_syncheck(&src, &deq))
		{
			g_sh->status = 1;
			return (ft_dtor(OUF, (t_dtor)ft_deqdtor, &deq, NULL));
		}
		cb(&deq, *src.ln);
		break ;
	}
	st == OUF ? (g_sh->status = 1) : 0;
	return (ft_dtor(st, (t_dtor)ft_deqdtor, &deq, NULL));
}

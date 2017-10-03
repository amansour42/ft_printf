/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bigS.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:37:54 by amansour          #+#    #+#             */
/*   Updated: 2017/10/03 16:32:00 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int		wchar_to_write(int n, wchar_t *wstr)
{
	int i;
	int len;

	if (n < 0)
		return (ft_wstrlen(wstr));
	len = 0;
	i = -1;
	while (*wstr && len <= n)
	{
		++i;
		len += wchar_len(*wstr);
		++wstr;
	}
	return (i);
}

static int		char_to_write(int wlen, wchar_t *ws)
{
	int i;
	int a;

	i = 0;
	while (wlen-- && (a = wchar_len(*ws)))
	{
		i += a;
		++ws;
	}
	return (i);
}

/*static void		fill(char **str, char *s, int i)
{
	while (*s)
	{
		(*str)[i++] = *s;
		++s;
	}
	free(s);
	return ;
}
*/
char			*to_bigS(t_format f, va_list *ap)
{
	wchar_t	*wstr;
	char	*str;
	int		wlen;
	int		len;

	if (!(wstr =va_arg(*ap, wchar_t *)))
		return (ft_strdup("(null)"));
	wlen = wchar_to_write(f.p, wstr);
	len = 0;
	str = (char *)malloc(char_to_write(wlen, wstr) + 1);
	while (wlen)
	{
		convert_unicode(*wstr, &str, &len);
		++wstr;
		--wlen;
	}
	str[len] = '\0';
	return (str);
}

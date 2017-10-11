/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:23:56 by amansour          #+#    #+#             */
/*   Updated: 2017/09/27 11:55:52 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			wchar_len(wint_t c)
{
	if (c >= 0 && c <= 0x7F)
		return (1);
	else if (c >= 0x80 && c <= 0x7FF)
		return (2);
	else if ((c >= 0x800 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFF))
		return (3);
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	return (0);
}

int			ws_len(wchar_t *wstr)
{
	int len;

	len = 0;
	while (*wstr)
	{
		len += wchar_len((wint_t)(*wstr));
		++wstr;
	}
	return (len);
}

void	    convert_unicode_size(wint_t wc, int size, char **str)
{
	if (size == 2)
	{
		(*str)[1] = (wc & 0x3F) + 0x80;
		(*str)[0] = (wc >> 6)+ 0xC0;
	}
	else if (size == 3)
	{
		(*str)[2] = (wc & 0x3F) + 0x80;
		(*str)[1] = ((wc >> 6) & 0x3F) + 0x80;
		(*str)[0] = (wc >> 12) + 0xE0;
	}
	else
	{
		(*str)[3] = (wc & 0x3F) + 0x80;
		(*str)[2] = ((wc >> 6) & 0x3F) + 0x80;
		(*str)[1] = ((wc >> 12) & 0x3F) + 0x80;
		(*str)[0] = (wc >> 18) + 0xF0;
	}
	(*str)[size] = '\0';
	return ;
}

char		*convert_unicode(wint_t wc)
{
	int 			len;
	char			*str;

	len = wchar_len(wc);
	str = ft_strnew(len);
	if (len == 1)
	{
		str[0] = wc;
		str[1] = '\0';
		return (str);
	}
	if (len == 0)
	{
		str[0] = '\0';
		return (str);
	}
	convert_unicode_size(wc, len, &str);
	return (str);
}

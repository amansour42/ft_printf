/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:23:56 by amansour          #+#    #+#             */
/*   Updated: 2017/09/21 17:53:17 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			wchar_len(wchar_t wc)
{
	if (wc <= 0xFF)
		return (1);
	if (wc <= 0x7FF)
		return (2);
	if (wc <= 0xFFFF)
		return (3);
	//if (wc <= 0x10FFFF)
		return (4);
	//return (0);
}

int			ws_len(wchar_t *wstr)
{
	int len;

	len = 0;
	while (*wstr)
	{
		len += wchar_len(*wstr);
		++wstr;
	}
	return (len);
}

void	    convert_unicode_size(wchar_t wc, int size, char **str)
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

char		*convert_unicode(wchar_t wc)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:29:27 by amansour          #+#    #+#             */
/*   Updated: 2017/09/29 11:15:49 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int     len_p(int n, wchar_t *wstr)
{
    int i;
    int len;

    len = 0;
    i = 0;
    while (*wstr && (len += wchar_len(*wstr)) <= n)
    {
        ++i;
        ++wstr;
    }
    return (i);
}
char	*to_string(t_format format, va_list *ap)
{
	wchar_t	*wstr;
	char	*str;
	wchar_t	a;
	int		len;

	if (format.c == 'c')
	{
		a = (wchar_t)va_arg(*ap, wint_t);
		return (convert_unicode(a));
	}
	wstr = va_arg(*ap, wchar_t *);
	if (!wstr)
        //return (ft_strcut("(null)", format.precision));
        return ("(null)");
    len = (format.precision < 0) ? ft_wstrlen(wstr) : len_p(format.precision, wstr);
    str = (len) ? convert_unicode(*wstr) : "\0"; 
	while ((--len) > 0)
	{
		++wstr;
        str = ft_strjoin(str, convert_unicode(*wstr));
	}
   // printf("la precision = %d\nla longueur = %zu\n", format.precision, ft_strlen(str));   
    return (str);
}

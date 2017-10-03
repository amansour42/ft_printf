/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 09:50:53 by amansour          #+#    #+#             */
/*   Updated: 2017/10/03 17:12:12 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	char	*s;

	s = ft_strdup(format);
	va_start(ap, format);
	result = prints(&ap, s);
	va_end(ap);
	free(s);
	return(result);
}

int		prints(va_list *ap, char *str)
{
	int n;

	n = 0;
	while (*str)
	{
		while (*str && *str != '%')
		{
			write (1, str, 1);
			++n;
			++str;
		}
		while (*str == '%')
			test(&str, ap, &n);
	}
	return (n);
}

void	test(char **str, va_list *ap, int *n)
{
	t_format	format;

	format.width = 0;
	format.flag = 0;
	format.p = -1;
	format.mod = 0;
	fillFormat(str, &format, ap);
	if (!format.c)
		return ;
	if (format.c == 'n')
		to_n(format, ap, *n);
	else if (belong(format.c, CONV))
		*n += display(conversion(format, ap), format);
	else
		*n += display(c_to_s(format.c), format);
	++(*str);
	return ;
}

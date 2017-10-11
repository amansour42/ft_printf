/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 09:50:53 by amansour          #+#    #+#             */
/*   Updated: 2017/09/29 11:14:18 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	char	*str;

	str = ft_strdup(format);
	va_start(ap, format);
	result = prints(&ap, str);
	va_end(ap);
	return (result);
}

int			prints(va_list *ap, char *str)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i++]);
			++n;
		}
		if (str[i] == '%')
			i += test(&(str[i]), ap, &n);
	}
	return (n);
}

static int	search(char *str, va_list *ap, t_format *format)
{
	int i;

	i = 1;
	while (str[i] && (ft_isdigit(str[i]) || belong(str[i], OTHERS)))
	{
		(*format).flag |= flag(str, &i);
		(ft_isdigit(str[i])) ? (*format).width = string_to_int(str, &i) : 0;
		(str[i] == '*') ? (*format).width = va_arg(*ap, int) : 0;
		(str[i] == '*') ? ++i : 0;
		(*format).flag |= flag(str, &i);
		(ft_isdigit(str[i])) ? (*format).width = string_to_int(str, &i) : 0;
		if (str[i] == '.')
		{
			if (str[++i] == '*')
				(*format).precision = va_arg(*ap, int);
			else
				(*format).precision = string_to_int(str, &i);
			(str[i] == '*') ? ++i : 0;
		}
		(*format).mod |= modifier(str, &i);
	}
	return (i);
}

int			test(char *str, va_list *ap, int *n)
{
	t_format	format;
	int			i;

	initFormat(&format);
	i = search(str, ap, &format);
	if (!(format.c = str[i]))
		return (i);
	if (format.c == 'n')
		conversion_n(format, ap, *n);
	else if (belong(format.c, CONV))
		*n += display(conversion_others(format, ap), format);
	else
		*n += display(&(format.c), format);
	return (++i);
}

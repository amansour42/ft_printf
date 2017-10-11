/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:13:33 by amansour          #+#    #+#             */
/*   Updated: 2017/09/29 10:14:41 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*conversion_others(t_format format, va_list *ap)
{
	char *s;

	if (belong(format.c, "DUOCS"))
	{
		format.c += 32;
		format.mod |= LONGMOD;
	}
	if (format.c == 'p')
	{
		format.flag |= ALTFLAG;
		format.mod |= LONGMOD;
	}
	if (belong(format.c, "di"))
		return (to_sign_decimal(format, ap));
	if (belong(format.c, "uxXop"))
		return (to_decimal(format, ap));
	if (format.c == 'c' && !(format.mod & LONGMOD))
		return (convert_char((unsigned char)va_arg(*ap, int)));
	if (format.c == 's' && !(format.mod & LONGMOD))
	{
		s = ((s = va_arg(*ap, char *))) ? s : "(null)";
		return (ft_strcut(s, format.precision));
	}
	else if (format.c == '%')
		return (convert_char(format.c));
	return (to_string(format, ap));
}

char	*to_sign_decimal(t_format format, va_list *ap)
{
	intmax_t	a;

	if (format.mod & SIZETMOD)
		a = va_arg(*ap, ssize_t);
	else if (format.mod & MAXMOD)
		a = va_arg(*ap, intmax_t);
	else if (format.mod & LONGLONGMOD)
		a = va_arg(*ap, long long);
	else if (format.mod & LONGMOD)
		a = va_arg(*ap, long);
	else if (format.mod & HALFHALFMOD)
		a = (signed char)va_arg(*ap, int);
	else if (format.mod & HALFMOD)
		a = (short)va_arg(*ap, int);
	else
		a = va_arg(*ap, int);
	if (a < 0)
		return (nbr_to_string(-a, format, -1));
	return (nbr_to_string(a, format, 1));
}

char	*to_decimal(t_format format, va_list *ap)
{
	uintmax_t	a;

	if (format.mod & SIZETMOD)
		a = va_arg(*ap, size_t);
	else if (format.mod & MAXMOD)
		a = va_arg(*ap, uintmax_t);
	else if (format.mod & LONGLONGMOD)
		a = va_arg(*ap, unsigned long long);
	else if (format.mod & LONGMOD)
		a = va_arg(*ap, unsigned long);
	else if (format.mod & HALFHALFMOD)
		a = (unsigned char)va_arg(*ap, unsigned int);
	else if (format.mod & HALFMOD)
		a = (unsigned short)va_arg(*ap, unsigned int);
	else
		a = va_arg(*ap, unsigned int);
	return (nbr_to_string(a, format, 1));
}

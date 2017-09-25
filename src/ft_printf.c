/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 09:50:53 by amansour          #+#    #+#             */
/*   Updated: 2017/09/25 20:25:56 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	char	*str;

	str = ft_strdup(format);
	va_start(ap, format);
	result = prints(&ap, str);
	va_end(ap);
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
			ft_putchar(*str);
			++str;
			++n;
		}
		if (*str == '%')
			n+= test(&str, ap, n);
	}
	return (n);
}

int		test(char **str, va_list *ap, int n)
{
	t_format	format;
	char		*s;

	format.flag = 0;
	format.mod = 0;
	format.precision = -1;
	format.width = 0;
	++(*str);
	while(**str && (ft_isdigit(**str) || belong(**str, OTHERS)))
	{
		format.flag |= flag(str);
		format.width = (ft_isdigit(**str)) ? string_to_int(str) : format.width;
		format.width = (**str == '*') ? va_arg(*ap, int) : format.width;
		if (**str  == '*')
			++(*str);
		format.width = (ft_isdigit(**str)) ? string_to_int(str) : format.width;
		if(**str == '.')
		{
			++(*str);
			format.precision = (**str == '*') ? va_arg(*ap, int) : string_to_int(str);
			//format.precision = string_to_int(str);
			if (**str ==  '*')
				++(*str);
		}
		//printf("After precision : %s\nprecision = %d\n", *str, format.precision);
		format.mod |= modifier(str);
		//printf("After mod : %s\n", *str);
	}
	//printf("width = %d\n", format.width);
	//printf("Precision = %d\n", format.precision);
    if (!(format.c = **str))
        return (0);
	if (format.c == 'n')
	{
		conversion_n(format, ap, n);
		return (0);
	}
	if (belong(format.c, CONV))
		s = conversion_others(format, ap);
	else
		s = convert_char(format.c);
	++(*str);
	return (display(s, format));
}

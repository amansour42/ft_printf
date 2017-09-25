/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:18:07 by amansour          #+#    #+#             */
/*   Updated: 2017/09/25 21:01:32 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
static int		find_base(char c, char **str)
{
	*str = ft_strnew(17);
	if (c == 'X')
	ft_strcpy(*str, "0123456789ABCDEF");
	else
		ft_strcpy(*str, "0123456789abcdef");
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	if (c == 'o')
		return (8);
	return (10);
}

static int		length(uintmax_t nbr, int base)
{
	int len;

	len = 1;
	while ((nbr /= base))
		++len;
	return (len);
}

static char		*nbr_string(uintmax_t value, t_format format, char *op)
{
	char	*str;
	char	*s;
	int		len;
	int		base;

	base = find_base(format.c, &s);
	len = length(value, base);
	if (format.precision > len || (!format.precision && !value))
		len = format.precision;
	if (op)
		len += ft_strlen(op);
	if (format.c == 'o' && format.precision == (len - 1) && (format.flag & ALTFLAG))
        len -= ft_strlen(op);
    if ((format.flag & LEADZEROFLAG) && !(format.flag & LEFTFORMATFLAG))
		len = (format.precision < 0 && (format.width > len)) ? format.width : len;
    str = ft_strnew(len);
	str[len] = '\0';
	str[--len] = s[value % base];
	while ((value /= base))
		str[--len] = s[value % base];
	while (--len >= 0)
		str[len] = '0';
	str[0] = (op) ? op[0] : str[0];
	str[1] = (op && op[1]) ? op[1] : str[1];
	return (str);
}

char			*nbr_to_string(uintmax_t value, t_format format, int sign)
{
	if (sign < 0)
		return (nbr_string(value, format, "-"));
    if (!value && !format.precision && (format.flag & ALTFLAG) && format.c == 'o')
        return ("0");
    if (format.c == 'p' && !value && format.precision == 0)
        return ("0x");
    if (belong(format.c, "di") && (format.flag & SHOWSIGNFLAG))
		return (nbr_string(value, format, "+"));
	if (belong(format.c, "di") && (format.flag & SPACEFLAG))
		return (nbr_string(value, format, " "));
	if (format.c != 'p' && !value && format.precision == 0)
        return ("\0");
	if (format.c == 'p' || (value && format.c == 'x' && (format.flag & ALTFLAG)))
		return (nbr_string(value, format, "0x"));
	if (value && format.c == 'X' && (format.flag & ALTFLAG))
		return (nbr_string(value, format, "0X"));
	if (value && format.c == 'o' && (format.flag & ALTFLAG))
		return (nbr_string(value, format, "0"));
	return (nbr_string(value, format, NULL));
}

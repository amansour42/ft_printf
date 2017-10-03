/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:06:09 by amansour          #+#    #+#             */
/*   Updated: 2017/10/03 17:06:26 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			fillFormat(char **str, t_format *f, va_list *ap)
{
	++(*str);
	while(**str && (ft_isdigit(**str) || belong(**str, OTHERS)))
	{
		(*f).flag |= flag(str);
		(ft_isdigit(**str)) ? (*f).width = string_to_int(str) : 0;
		(**str == '*') ? (*f).width = va_arg(*ap, int) : 0;
		(**str == '*') ? ++(*str) : 0;
		(ft_isdigit(**str)) ? (*f).width = string_to_int(str) : 0;
		if(**str == '.')
		{
			++(*str);
			(*f).p = (**str == '*') ? va_arg(*ap, int) :
				string_to_int(str);
			(**str == '*') ? ++(*str) : 0;
		}
		(*f).mod |= modifier(str);
	}
	(*f).c = **str;
	return ;
}

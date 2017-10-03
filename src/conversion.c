/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:13:33 by amansour          #+#    #+#             */
/*   Updated: 2017/10/03 16:58:30 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*conversion(t_format f, va_list *ap)
{
	if (f.c == 'D' || f.c == 'i' || f.c == 'd')
		return (to_Ddi(f, ap));
	if (f.c == 'u' || f.c == 'U')
		return (to_Uu(f, ap));
	if (f.c == 'x' || f.c == 'X')
		return (to_Xx(f, ap));
	if (f.c == 'o' || f.c == 'O')
		return (to_Oo(f, ap));
	if (f.c == 'p')
		return (to_p(f, ap));
	if (f.c == 'c' && !(f.mod & LONGMOD))
		return (c_to_s((unsigned char)va_arg(*ap, int)));
	if (f.c == 's' && !(f.mod & LONGMOD))
		return (to_string(f, ap));
	if (f.c == 'C' || f.c == 'c')
		return (to_bigC(ap));
	if (f.c == 'S' || f.c == 's') 
		return (to_bigS(f, ap));
	return (NULL);
}

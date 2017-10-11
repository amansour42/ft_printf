/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_printed_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:55:48 by amansour          #+#    #+#             */
/*   Updated: 2017/09/21 14:08:59 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conversion_n(t_format format, va_list *ap, int n)
{
	void *ptr;

	ptr = va_arg(*ap, void*);
	if (format.mod & LONGLONGMOD)
		*(long long*)ptr = n;
	else if (format.mod & LONGMOD)
		*(long*)ptr = n;
	else if (format.mod & HALFHALFMOD)
		*(signed char*)ptr = n;
	else if (format.mod & HALFMOD)
		*(short*)ptr = n;
	else if (format.mod & SIZETMOD)
		*(size_t*)ptr = n;
	else
		*(int*)ptr = n;
	return ;
}

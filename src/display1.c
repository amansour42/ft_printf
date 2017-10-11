/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:36:55 by amansour          #+#    #+#             */
/*   Updated: 2017/09/29 11:13:47 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static void		n_write(int n, char c)
{
	while (n--)
		write(1, &c, 1);
	return ;
}

int			display(char *str, t_format format)
{
	int		len;
	char	l;

	len = ft_strlen(str);
	(!len && (format.c == 'c' || format.c == 'C')) len = 1 : 0;
	l = (format.flag & LEADZEROFLAG) ? '0' : ' ';
	if (format.width < 0)
	{
		format.flag |= LEFTFORMATFLAG;
		format.width = -format.width;
	}
	if (format.flag & LEFTFORMATFLAG)
	{
		write(1, str, len);
		(format.width > len) ? n_write(format.width - len, ' ') : 0;
	}
	else
	{
		(format.width > len) ? n_write(format.width - len, l) : 0;
		write(1, str, len);
	}
	return ((len < format.width) ? format.width : len);
}

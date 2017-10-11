/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:38:32 by amansour          #+#    #+#             */
/*   Updated: 2017/09/20 19:09:03 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_putstr(char const *s)
{
	if (s)
	{
		if (!(*s))
			write(1, "\0", 1);
		else
			write(1, s, ft_strlen(s));
	}
	return ;
}

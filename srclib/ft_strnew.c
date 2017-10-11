/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 11:15:32 by amansour          #+#    #+#             */
/*   Updated: 2017/09/18 13:48:08 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)ft_memalloc(size + 1);
	if (str)
	{
		if (size == 0)
			str[0] = '\0';
		else
		{
			ft_memset(str, 0, size);
			str[size] = '\0';
		}
	}
	return (str);
}

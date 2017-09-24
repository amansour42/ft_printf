/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 09:44:51 by amansour          #+#    #+#             */
/*   Updated: 2017/09/18 13:50:51 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	if (size == 0)
		return (NULL);
	str = (char*)malloc(sizeof(char) * size);
	if (str)
		ft_bzero((void*)str, size);
	return ((void*)str);
}

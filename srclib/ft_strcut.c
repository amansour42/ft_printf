/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:49:16 by amansour          #+#    #+#             */
/*   Updated: 2017/09/21 19:20:17 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*ft_strcut(char *str, int n)
{
	char	*s;
	int		len;

	len = ft_strlen(str);
	if (n < 0 || n >= len)
		return (str);
	if (n == 0)
		return ("\0");
	s = ft_strnew(n);
	ft_strncpy(s, str, n);
    return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:52:09 by amansour          #+#    #+#             */
/*   Updated: 2017/09/18 13:40:46 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		belong(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	if (str[i] == c)
		return (1);
	return (0);
}

int		convert_number(char *str)
{
	int result;

	result = 0;
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str) - 48;
		++str;
	}
	return (result);
}

/*void	add_end(char **s, int n)
{
	char	*str;
	int		i;

	str = ft_lstnew(n);
	ft_strcpy(str, *s);
	i = ft_strlen(*s);
	while (i < n)
		str[i++] = ' ';
	str[i] = '\0';
	free(*s);
	*s = str;
	return ;
}*/



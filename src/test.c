/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:59:43 by amansour          #+#    #+#             */
/*   Updated: 2017/09/25 17:31:48 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		flag(char *str, int *i)
{
	int nbr;

	nbr = 0;
	while(str[*i] && belong(str[*i], "#- +0"))
	{
		if (str[*i] == '#')
			nbr |= ALTFLAG;
		else if (str[*i] == '-')
			nbr |= LEFTFORMATFLAG;
		else if (str[*i] == '+')
			nbr |= SHOWSIGNFLAG;
		else if (str[*i] == ' ')
			nbr |= SPACEFLAG;
		else
			nbr |= LEADZEROFLAG;
		*i += 1;
	}
	return (nbr);
}

int		modifier(char *str, int *i)
{
	int nbr;

	nbr = 0;
	while (str[*i] && belong(str[*i], "lLhjz"))
	{
		if (str[*i] == 'l' && (nbr & LONGMOD))
			nbr |= LONGLONGMOD;
		else if (str[*i] == 'l')
			nbr |= LONGMOD;
		else if (str[*i] == 'L')
			nbr |= LONGDOUBLEMOD;
		else if (str[*i] == 'h' && (nbr & HALFMOD))
			nbr |= HALFHALFMOD;
		else if (str[*i] == 'h')
			nbr |= HALFMOD;
		else if (str[*i] == 'z')
			nbr |= SIZETMOD;
		else if (str[*i] == 'j')
			nbr |= MAXMOD;
		*i += 1;;
	}
	return (nbr);
}

int		string_to_int(char *str, int *i)
{
	int nbr;

	nbr = 0;
	while(str[*i] && ft_isdigit(str[*i]))
	{
		nbr = nbr * 10 + (str[*i] - '0');
		*i += 1;
	}
	return (nbr);
}

char	*convert_char(char c)
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

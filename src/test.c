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

int		flag(char **str)
{
	int nbr;

	nbr = 0;
	while(**str && belong(**str, "#- +\'$0"))
	{
		if (**str == '#')
			nbr |= ALTFLAG;
		else if (**str == '-')
			nbr |= LEFTFORMATFLAG;
		else if (**str == '+')
			nbr |= SHOWSIGNFLAG;
		else if (**str == ' ')
			nbr |= SPACEFLAG;
		//else if (**str == '*')
		  //  nbr |= ASTERIXFLAG; 
		else if (**str == '\'')
			nbr |= APOSTROPHEFLAG;
		else if (**str == '$')
			nbr |= DOLLORFLAG;
		else
			nbr |= LEADZEROFLAG;
		++(*str);
	}
	return (nbr);
}

int		modifier(char **str)
{
	int nbr;

	nbr = 0;
	while (**str && belong(**str, "lLhjz"))
	{
		if (**str == 'l' && (nbr & LONGMOD))
			nbr |= LONGLONGMOD;
		else if (**str == 'l')
			nbr |= LONGMOD;
		else if (**str == 'L')
			nbr |= LONGDOUBLEMOD;
		else if (**str == 'h' && (nbr & HALFMOD))
			nbr |= HALFHALFMOD;
		else if (**str == 'h')
			nbr |= HALFMOD;
		else if (**str == 'z')
			nbr |= SIZETMOD;
		else if (**str == 'j')
			nbr |= MAXMOD;
		++(*str);
	}
	return (nbr);
}

int		string_to_int(char **str)
{
	int nbr;

	nbr = 0;
	while(**str && ft_isdigit(**str))
	{
		nbr = nbr * 10 + (**str - '0');
		++(*str);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:36:55 by amansour          #+#    #+#             */
/*   Updated: 2017/10/03 19:57:06 by amansour         ###   ########.fr       */
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

/*static char		*readapt(char *str, int n, int len, char c)
{
	char	*s;
	int		i;
	int		j;

	i = (n > 0) ? -1 : len;
	s = (char*)malloc(ABS(n));
	j = 0;
	if (n > 0)
	{
		while (++i < (n - len))
			s[i] = c;
		while (i < n)
			s[i++] = str[j++];
	}
	else
	{
		n = ABS(n);
		ft_strncpy(s, str, len);
		while (i <  n)
			s[i++] = c;
	}
	s[i] = '\0';
	if (*str)
		free(str);
	return(s);
}*/

int			display(char *str, t_format f)
{
	int		len;
	char	c;
//	char	*s;

	(f.width < 0) ? f.flag |= LEFTFORMATFLAG : 0;
	(f.width < 0) ? f.width = ABS(f.width) : 0;
	if (!(len = ft_strlen(str)) && (f.c == 'C' || f.c == 'c'))
		++len;
	if (f.width > len)
	{
		//(f.flag & LEFTFORMATFLAG) ? f.width = -f.width : 0;
		if (f.flag & LEFTFORMATFLAG)
		{
			write(1, str, len);
			n_write(f.width - len, ' ');
			//s = readapt(str, -f.width, len, ' ');
		}
	//else if (f.width <= len)
	//	write(1, str, len);
		else
		{
			c = (f.flag & LEADZEROFLAG) ? '0' : ' ';
			//if (!(f.flag & LEADZEROFLAG && belong(f.c, "dDiuUoOxXp") && f.p >= 0))
			//	0;
			//else
			(f.p != -1 && belong(f.c, "dDiuUxXoOp") && c == '0') ? c = ' ' : 0;
			n_write(f.width - len, c);
			write(1, str, len);
			//s = readapt(str, f.width, len, c);
			//write(1, s, f.width);
			//free(s);
			//return (f.width);
		}
		//write (1, s, f.width);
		//free(s);
		//return (f.width);
	}
	//printf("%s\n", str);
	//if (str)
	else
		write (1, str, len);
	if (*str)
		free(str);
	return (MAX(len, f.width));
}

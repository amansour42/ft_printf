/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:04:21 by amansour          #+#    #+#             */
/*   Updated: 2017/10/03 16:49:21 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# define LONGMOD		0x01
# define LONGLONGMOD	0x02
# define HALFMOD		0x04
# define HALFHALFMOD	0x08
# define SIZETMOD		0x10
# define MAXMOD			0x20
# define LONGDOUBLEMOD	0x40
# define ALTFLAG		0x01
# define SHOWSIGNFLAG	0x02
# define LEFTFORMATFLAG	0x04
# define SPACEFLAG		0x08
# define APOSTROPHEFLAG	0x10
# define ASTERIXFLAG	0x20
# define DOLLORFLAG		0x40
# define LEADZEROFLAG	0x80
# define CONV			"DdiuUxXoOnpCcsS"
# define OTHERS			"*#- +\'.lhjz"
# define ABS(a)         (a >= 0) ? a : -a
# define MAX(a, b)      (a > b) ? a : b           

typedef struct			s_format
{
	int					flag;
	int					width;
	int					mod;
	char				c;
	int					p;
}						t_format;
//ft_printf.c
int						ft_printf(const char *format, ...);
int						prints(va_list *ap, char *str);
void					test(char **str, va_list *ap, int *n);
//util.c
int						belong(char c, char *str);
//conversion.c
char					*conversion(t_format f, va_list *ap);
//to_bigC.c
char					*to_bigC(va_list *ap);
//to_bigS.c
char					*to_bigS(t_format f, va_list *ap);
//to_decimal.c
char					*to_Uu(t_format f, va_list *ap);
char					*to_Oo(t_format f, va_list *ap);  
char					*to_Xx(t_format f, va_list *ap);  
//to_p.c
char					*to_p(t_format f, va_list *ap);  
//to_sign_decimal.c
char					*to_Ddi(t_format f, va_list *ap); 
//to_string.c
char					*to_string(t_format f, va_list *ap);
char					*c_to_s(char c);
//nbr_to_string.c
int						length(uintmax_t nbr, int base);
char					*nbr_to_string(uintmax_t v, int len, int base);
//test.c
int						string_to_int(char **str);
int						flag(char **str);
int						modifier(char **str);
//display.c
int 					display(char *str, t_format format);
//to_n.c
void					to_n(t_format format, va_list *ap,int n);
//format.c
void					fillFormat(char **s, t_format *format, va_list *ap);
//
int						wchar_len(wchar_t c);
int						ws_len(wchar_t *wstr);
int						ft_isdigit(int c);
char					*ft_strncpy(char *str1, const char *str2, size_t l);
size_t					ft_strlen(char const *str);
size_t					ft_wstrlen(wchar_t *wstr);  
char					*ft_strdup(const char *str);
void					convert_unicode(wchar_t c, char **s, int *i);
#endif

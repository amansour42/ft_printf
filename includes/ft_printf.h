/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:04:21 by amansour          #+#    #+#             */
/*   Updated: 2017/09/21 19:54:24 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <wchar.h>
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

typedef struct			s_format
{
	int					flag;
	int					width;
	int					mod;
	char				c;
	int					precision;
}						t_format;

int						ft_printf(const char *format, ...);
int						prints(va_list *ap, char *str);
int						test(char **str, va_list *ap, int n);
char					*ft_itoa_op(uintmax_t value, int base, int option);
int						belong(char c, char *str);
int						convert_number(char *str);
void					ft_flag(char c, int *flag);
char					*conversion(char c, va_list *ap, int flag, int *n);
char					*alt_flag(char c);
char					*to_sign_decimal(t_format format, va_list *ap);
char					*to_decimal(t_format format, va_list *ap);
char					*to_string(t_format format, va_list *ap);
char					*nbr_to_string(uintmax_t v, t_format format, int s);
int						string_to_int(char **str);
int						flag(char **str);
int						modifier(char **str);
int						display(char *str, t_format format);
void					conversion_n(t_format format, va_list *ap,int n);
char					*conversion_others(t_format format, va_list *ap);
int						wchar_len(wchar_t c);
int						ws_len(wchar_t *wstr);
int						ft_isdigit(int c);
char					*ft_strcat(char *dest, const char *src);
void					ft_putstr(char const *str);
char					*ft_strcut(char *str, int n);
char					*ft_strncpy(char *str1, const char *str2, size_t l);
void					ft_putchar(char c);
size_t					ft_strlen(char const *str);
size_t					ft_wstrlen(wchar_t *wstr);  
char					*ft_strnew(size_t i);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup(const char *str);
char					*ft_strcpy(char *s1, char const *s2);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memalloc(size_t n);
void					ft_bzero(void *ptr, size_t p);
int						ft_upcase(char c);
void					join(char **str, char *u);
char					*ft_strjoin(char const *str1, char const *str2);
char					*convert_unicode(wchar_t wc);
char					*convert_char(char c);
#endif

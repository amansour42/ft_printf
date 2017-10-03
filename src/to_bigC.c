#include "../includes/ft_printf.h"
#include <stdio.h>

char	*to_bigC(va_list *ap)
{
	wchar_t	a;
	int		len;
	char	*s;

	a = (wchar_t)va_arg(*ap, wint_t);
	len = wchar_len(a);
	if (!(len = wchar_len(a)))
		return ("");
	if (!(s = (char *)malloc(len + 1)))
		return (s);
	s[len] = '\0';
	len = 0;
	convert_unicode(a, &s, &len);
	return (s);
}

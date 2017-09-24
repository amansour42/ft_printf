#include "../includes/ft_printf.h"

void    ft_concat(char **str, char *s)
{
    char    *tmp;
    int     i;

    tmp = ft_strnew(ft_strlen(*str) + ft_strlen(s));
    ft_strcpy(tmp, *str);
    i = ft_strlen(*str);
    while (*s)
    {
        tmp[i++] = *s;
        ++s;
    }
    tmp[i] = '\0';
    free(*str);
    *str = tmp;
}

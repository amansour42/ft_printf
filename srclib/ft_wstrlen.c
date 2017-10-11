#include "../includes/ft_printf.h"

size_t  ft_wstrlen(wchar_t *ws)
{
    size_t len;

    len = 0;
    while (*ws)
    {
        ++len;
        ++ws;
    }
    return (len);
}

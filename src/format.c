
#include "../includes/ft_printf.h"

void    initFormat(t_format *format)
{
    (*format).flag = 0;
    (*format).mod = 0;
    (*format).precision = -1;
    (*format).width = 0;
    return ;
}

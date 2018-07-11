#include "ft_printf.h"
#include "libft/libft.h"

int     print_uint(va_list arg_list)
{
    unsigned int    u_int;
    unsigned int    len;
    char            *_u_int;
    int             div;

    u_int = va_arg(arg_list, unsigned int);
    if (u_int < 0)
         return (-1);
    div = 1;
    len = 0;
    while ((u_int / div) > 9)
    {
        div *= 10;
        len++;
    }
    _u_int = ft_itoabase(u_int, 10);
    ft_putstr(_u_int);
    return (len);
}

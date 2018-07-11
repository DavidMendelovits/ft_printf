#include "ft_printf.h"
#include "libft/libft.h"

int     print_uint(va_list arg_list)
{
    unsigned int    u_int;
    unsigned int    len;
    unsigned int    div;

    u_int = va_arg(arg_list, unsigned int);
    if (u_int < 0)
         return (-1);
    div = 1;
    len = 0;
    while ((u_int / div) > 9)
        div *= 10;
    while (div != 0)
    {
        len++;
        ft_putchar('0' + u_int / div);
        u_int %= div;
        div /= 10;
    }
    return (len);
}

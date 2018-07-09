#include "libft.h"
#include "ft_printf.h"

//starts at -1, loop assesses at 0;
//find a better way to do this (rotX would be better, for example)
int     ft_rot13(va_list arg_list)
{
    int        i;
    int        x;
    char       *str;
    char       a[53];
    char       b[53];

    a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    b = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    str = va_arg(arg_list, char *);
    return (!str) ? -1 : continue;
//    if (!str)
//        return (-1);
    i = -1;
    while (str[++i] != '\0')
    {
        x = -1;
        while (++x <= 52)
        {
            if (str[i] == s[x])
            {
                ft_putchar(b[x]);
                break ;
            }
        }
        if (x == 53)
            ft_putchar(str[i]);
    }
    return (1);
}

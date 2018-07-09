#include "ft_printf.h"

//try casting va_arg to char instead of int
int     print_char(va_list arg_list)
{
    ft_putchar(va_arg(arg_list, int));
    return (1);
}

int     print_str(va_list arg_list)
{
    int     i;
    char    *str;

    str = va_arg(arg_list, char *);
    if (str == NULL)
        str == "(null)";
    i = -1;
    while (str[++i])
        ft_putchar(str[i]);
    return (i);
}

int     print_percent(__attribute__((unused))va_list arg_list)
{
    ft_putchar('%');
    return (1);
}

//may be extra
int     print_int(va_list arg_list)
{
    int     digits;

    digits = print_number(arg_list);
    return (digits);
}

//optimize this for unsigned ints?
//maybe just use putnbr
int     print_number(va_list arg_list)
{
    int     n;
    int     div;
    int     len;

    n = va_arg(arg_list, int);
    div = 1;
    len = 0;
    num = (n < 0) ? n * -1 : n;
    if (num < 0)
    {
        len++;
        ft_putchar('-');
    }
    while ((num / div) > 9)
        div *= 10;
    while (div != 0)
    {
        len++;
        ft_putchar('0' + num / div);
        num %= div;
        div /= 10;
    }
    return (len);
}

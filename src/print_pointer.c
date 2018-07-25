#include "ft_printf.h"

int     print_adr(unsigned long n)
{
    int     printed_chars;

    printed_chars = 0;
    if (n > 15)
    {
        print_adr((n / 16));
        print_adr((n % 16));
    }
    else if (n < 10)
    {
        printed_chars += 1;
        ft_putchar(n + '0');
    }
    else
    {
        printed_chars += 1;
        n == 10 ? ft_putchar('a') : 0;
        n == 11 ? ft_putchar('b') : 0;
        n == 12 ? ft_putchar('c') : 0;
        n == 13 ? ft_putchar('d') : 0;
        n == 14 ? ft_putchar('e') : 0;
        n == 15 ? ft_putchar('f') : 0;
    }
    return (printed_chars);
}

int     print_ptr(va_list arg_list)
{
    void            *output;
    unsigned long   address;
    int             len;

    len = 0;
    output = va_arg(arg_list, void*);
    address = (unsigned long)(output);
    ft_putchar('0');
    ft_putchar('x');
    len += 2;
    len += print_adr(address);
    return (len);
}

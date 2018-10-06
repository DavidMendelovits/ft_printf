#include "libft.h"

void        ft_putnbr_base(unsigned long long number, char *base, int radix)
{
    if (number >= (unsigned long)radix)
    {
        ft_putnbr_base(number / (unsigned long)radix, base, radix);
    }
    if (number > (unsigned long)radix && (number % radix) >= (unsigned long)radix)
    {
        ft_putchar(base[number % radix - 1]);
    }
    else
    {
        ft_putchar(base[number % radix]);
    }
}

void        ft_putint_base(int  number, char *base, int radix)
{
    if (number >= radix)
    {
        ft_putnbr_base(number / radix, base, radix);
    }
    if (number > radix && (number % radix) >= radix)
    {
        ft_putchar(base[number % radix - 1]);
    }
    else
    {
        ft_putchar(base[number % radix]);
    }
}

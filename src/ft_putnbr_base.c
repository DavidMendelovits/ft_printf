#include "libft.h"

#define NUM "0123456789abcdef"

void        ft_putnbr_base(unsigned long long number, int base)
{
    if (number >= (unsigned long)base)
    {
        ft_putnbr_base(number / (unsigned long long)base, base);
    }
    if (number > (unsigned long)base && (number % base) >= (unsigned long)base)
    {
        ft_putchar(NUM[number % base - 1]);
    }
    else
    {
        ft_putchar(NUM[number % base]);
    }
}

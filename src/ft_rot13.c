#include "ft_printf.h"


int     ft_rot13(va_list arg_list)
{
    int     i;
    char    *cipher;

    i = 0;
    cipher = va_arg(arg_list, char *);
    while (cipher[i] != '\0')
    {
        if (ft_isupper(cipher[i]))
            cipher[i] = (((cipher[i] - 'A') + 13) % 26) + 'A';
        else if (ft_islower(cipher[i]))
            cipher[i] = (((cipher[i] - 'a') + 13) % 26) + 'a';  
        i++;
    }
    i = 0;
    while (cipher[i])
        ft_putchar(cipher[i++]);
    return (i);
}

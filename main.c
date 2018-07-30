#include "includes/ft_printf.h"
#include <stdio.h>

int     main(void)
{
    char            character = 'C';
    char            hello[] = "Hello, World!";
    int             n = 420;
    unsigned int    u_int = 4294967295;
    char            *ptr = "Hello, dude";

    printf("printf: (char) %c\n", character);
    ft_printf("ft_printf: (char)  %c\n", character);
    printf("printf: (string) %s\n", hello);
    ft_printf("ft_printf: (string) %s\n", hello);
    printf("printf: (int) %i\n", n);
    ft_printf("ft_printf: (int) %i\n", n);
    printf("printf: (uint) %u\n", u_int);
    ft_printf("ft_printf: (uint) %u\n", u_int);
    printf("printf: (ptr) %p\n", ptr);
	ft_printf("ft_printf: (ptr) %p\n", ptr);
    return (0);
}

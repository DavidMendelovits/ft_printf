#include "includes/ft_printf.h"
#include <stdio.h>

int     main(void)
{
    char            character = 'C';
    char            hello[] = "Hello, World!";
    int             n = 420;
    unsigned int    u_int = 4294967295;
    char            *ptr = "Hello, dude";

//    printf("\nprintf: char: %c", character);
    ft_printf("\nft_printf: char:  %c", character);
//    printf("\nprintf: string: %s", hello);
    ft_printf("\nft_printf: string: %s", hello);
//    printf("\nprintf: int: %i", n);
    ft_printf("\nft_printf: int: %i", n);
//    printf("\nprintf: uint: %u", u_int);
    ft_printf("\nft_printf: uint: %u \n", u_int);
    ft_printf("\n %u - %s\n", u_int, hello);
    ft_printf("ptr: %p", ptr);
    printf("\nprintf: ptr: %p", ptr);
    return (0);
}

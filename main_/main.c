#include "includes/ft_printf.h"
#include <stdio.h>

int     main(void)
{
    char            character = 'C';
//    char            hello[] = "Hello, World!";
	char			*hello = strdup("Hello, world!");
	int             n = 420;
    unsigned int    u_int = 4294967295;
    char            *ptr = "Hello, dude";

//    printf("------>printf: (char) %c\n", character);
//    ft_printf("------>ft_printf: (char)  %c\n", character);
    printf("--------->printf: (string) \n%.10s\n", hello);
    ft_printf("-------->ft_printf: (string) \n%.10s\n", hello);
    printf("--------->printf: (string) \n%.*s\n", 10, hello);
    ft_printf("-------->ft_printf: (string) \n%.*s\n", 10, hello);
	printf("--------->printf: (width)(string) \n%20s\n", strdup(hello));
//	ft_putendl(strdup(hello));
    ft_printf("--------->ft_printf: (width)(string) \n%20s\n", strdup(hello));
//	ft_putendl(strdup(hello));
	//    printf("printf: (string) %010s\n", hello);
//    ft_printf("ft_printf: (string) %010s\n", hello);
//	ft_putendl(hello);
	printf("1------->printf: (width)(string) \n%*s\n", 20, strdup(hello));
//    ft_putendl(hello);
	ft_printf("1--------->ft_printf: (width)(string) \n%*s\n", 20,  strdup(hello));
	printf("-------------------->printf: (width).(precision) \n%10.4s\n", strdup(hello));
	ft_printf("-------------------->ft_printf: (width).(precision) \n%10.4s\n", strdup(hello));
	printf("---------------->printf: *.* \n%*.*s\n", 10, 4, strdup(hello));
	ft_printf("---------------->ft_printf: *.* \n%*.*s\n", 10, 4, strdup(hello));
    printf("-------------->printf: (int) \n%05i\n", n);
  	ft_printf("----------->ft_printf: (int) \n%05i\n", n);
    printf("----------------->printf: (int) \n%125.66i\n", n);
  	ft_printf("-------->ft_printf: (int) \n%125.66i\n", n);
    printf("--------->printf: (uint) \n%120.20u\n", u_int);
    ft_printf("--------->ft_printf: (uint) \n%120.20u\n", u_int);
	printf("-_-------------->printf: (long uint) \n%lu\n", 4294967296);
	ft_printf("---------->ft_print: (long uint) \n%lu\n", 4294967296);
	printf("--------->printf: (octal) \n%o\n", 123456);
	ft_printf("--------->ft_printf: (octal) \n%o\n", 123456);
//	printf("--------->printf: (binary) \n%b\n", 123456);
//	ft_printf("--------->ft_printf: (binary) \n%b\n", 123456);
	printf("--------->printf: (hex) \n%x\n", 123456);
	ft_printf("--------->ft_printf: (hex) \n%x\n", 123456);
    printf("-------->printf: (ptr) \n%p\n", ptr);
	ft_printf("-------->ft_printf: (ptr) \n%p\n", ptr);
    return (0);
}

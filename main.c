#include "ft_printf.h"
#include "libft/libft.h"

int     main(void)
{
    ft_printf("Print_str: %s\n", "Hello World");
    unsigned int     num = 4294967295;
    ft_printf("Print_uint: %u\n", num);
    return (0);
}

#include "ft_printf.h"

void    dispatch(t_todo *list, t_content *content, int *i)
{
	WOW();
	t_argument	arg;
	i = 0;

	list->data = &arg;
	printf("list->spec: %c\n", list->spec);
    if (list->spec == 's' || list->spec == 'S')
        string(list, content);
 /*   else if (list->spec == 'd' || list->spec == 'i')
        decimal(list, content, i);
 */   else if (list->spec == 'c' || list->spec == 'C')
        character(list, content);
/*    else if (list->spec == '%')
        percent(list, content, i);
    else if (list->spec == 'p')
        pointer(list, content, i);
    else if (list->spec == 'o' || list->spec == 'O')
        octal(list, content, i);
    else if (list->spec == 'X' || list->spec == 'X')
        hexadecimal(list, content, i);
    else if (list->spec == 'u')
        unsigned_int(list, content, i);
    else if (list->spec == 'b')
        binary(list, content, i);
*/	
}


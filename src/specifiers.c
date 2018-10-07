#include "ft_printf.h"

void    dispatch(t_todo *list, t_content *content, int *i)
{
//	WOW();
	t_argument	arg;
	i = 0;

	list->data = &arg;
//	printf("list->spec: %c\n", list->spec);
//	printf("list->length = %s\n", list->length);
    if (list->spec == 's' || list->spec == 'S')
        string(list, content);
    else if (list->spec == 'd' || list->spec == 'i')
        decimal(list, content);
	else if (list->spec == 'D')
	{
		ft_strcpy(list->length, "l");
		decimal(list, content);
	}
    else if (list->spec == 'c' || list->spec == 'C')
        character(list, content);
    else if (list->spec == '%')
        percent(list, content);
    else if (list->spec == 'p')
        pointer(list, content);
    else if (list->spec == 'o')
        octal(list, content);
	else if (list->spec == 'O')
	{
		ft_strcpy(list->length, "l");
		octal(list, content);
	}
    else if (list->spec == 'X' || list->spec == 'x')
        hex(list, content);
   else if (list->spec == 'u')
        unsigned_int(list, content);
	else if (list->spec == 'U')
	{
		ft_strcpy(list->length, "l");
		unsigned_int(list, content);
	}
    else if (list->spec == 'b')
        binary(list, content);
//	printf("end dispatch\n");	
}


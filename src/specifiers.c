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
	{
		list->alt_form = 1;
        unsigned_number(list, content, "0123456789abcdef");
	}
	else if (list->spec == 'o')
        unsigned_number(list, content, "01234567");
	else if (list->spec == 'O')
	{
		ft_strcpy(list->length, "l");
		unsigned_number(list, content, "01234567");
	}
    else if (list->spec == 'X' || list->spec == 'x')
	{
		if (list->spec == 'x')
			unsigned_number(list, content, "0123456789abcdef");
		else if (list->spec == 'X')
			unsigned_number(list, content, "0123456789ABCDEF");
	}
	else if (list->spec == 'u')
        unsigned_number(list, content, "0123456789");
	else if (list->spec == 'U')
	{
		ft_strcpy(list->length, "l");
		unsigned_number(list, content, "0123456789");
	}
    else if (list->spec == 'b')	
        unsigned_number(list, content, "01");
	else if (list->spec == '%')
	{
		percent(list, content);
	}
//	printf("end dispatch\n");	
}


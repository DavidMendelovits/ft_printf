#include "ft_printf.h"

int     apply_flags(t_todo *list, t_content *content, int i)
{
    int     tmp;

    tmp = i;
    while (flag_check(content->format[tmp++]))
    {
        if (content->format[tmp] == '#')
            list->alt_form = 1;
        else if (content->format[tmp] == ' ')
            list->prepend_space = 1;
        else if (content->format[tmp] == '0')
            list->prepend_zero = 1;
        else if (content->format[tmp] == '-')
            list->left_align = 1;
        else if (content->format[tmp] == '+')
            list->show_sign = 1;
    }
    //return(?)
}


int     flag_check(char c)
{
    if (c == '#'|| c == '-' || c == '+'|| c == ' ' || c == 0)
        return (1);
    return (0);
}

int     is_wildcard(char c)
{
    if (c == '*' )
        return (1);
    return (0);
    //consider reading argument for wildcard and applying it in this function?
}

int     apply_precision(t_todo *list, t_content *content, int *i)
{
	int		tmp;
	int		p_len;

	tmp = i;
	p_len = 0;
	while (!(flag_check(content->format[++tmp]
            && !(is_wildcard(content->format[tmp])))))
	{
		if (p_len > 0)
			list->precision *= (10 * p_len);
		list->precision	+= ft_atoi(content->format[tmp]);
		p_len++;
	}
}

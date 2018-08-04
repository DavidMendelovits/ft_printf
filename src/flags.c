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
}


int     flag_check(char c)
{
    if (c == '#'|| c == '-' || c == '+'|| c == ' ' || c == 0)
        return (1);
    return (0);
}

int     apply_precision(t_todo *list, t_content *content, int *i)
{

}

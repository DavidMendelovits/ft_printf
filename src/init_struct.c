#include "ft_printf.h"

void    content_constructor(t_content *content, va_list _arg_list, const char *_format)
{
    content->fd = 1;
    content->r_val = 0;
    content->format = (char*)_format;
    content->arg_list = _arg_list
}

void    list_constructor(t_todo *list, t_content *content)
{
    list->left_align = 0;
    list->alt_form = 0;
    list->prepend_space = 0;
    list->prepend_zero = 0;
    list->show_sign = 0;
    list->length[0] = '\0';
    list->length[1] = '\0';
    list->length[2] = '\0';
    list->type = 0;
    list->len = 0;
	list->precision = 0;
    list->arg_list = &content->arg_list;
    list->fd = &content->fd;
    list->r_val = &content->fd;
}

int		store_precision

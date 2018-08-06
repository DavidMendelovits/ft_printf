/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:04:08 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/05 20:31:16 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    init_content(t_content *content, va_list _arg_list, const char *_format)
{
    content->fd = 1;
    content->r_val = 0;
    content->format = (char*)_format;
    content->arg_list = _arg_list
}

void    init_list(t_todo *list, t_content *content)
{
    list->left_align = 0;
    list->alt_form = 0;
    list->prepend_space = 0;
    list->prepend_zero = 0;
    list->show_sign = 0;
    list->length[0] = '\0';
    list->length[1] = '\0';
    list->length[2] = '\0';
    list->spec = '\0';
    list->len = 0;
	list->width = 0;
	list->precision = -1;
    list->arg_list = &content->arg_list;
    list->fd = &content->fd;
    list->r_val = &content->fd;
}

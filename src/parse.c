/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:46:37 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/04 20:50:46 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_conversion(t_todo *list, t_content *content, int *i)
{
	int		j = -1;
//i is '%' place
    while (content->format[++i] && !(spec_check(list, content, i)))
    {
        if (flag_check(content->format[i]))
            apply_flags(list, content, i);
        else if (content->format[i] == '.')
            apply_precision(list, content, i);
        else if (ft_isdigit(content->format[i]))
            apply_width(list, content, i);
        else if (ft_isalpha(content->format[i]))
            apply_length(list, content, i);
//        else if (content->format[i] =='&')
//            content->r_val += apply_colors(list, content, i);
    }
	
	
	
}

int     begin_parse(const char *format, va_list arg_list)
{
    int         i;
    t_todo      list;
    t_content   content;

    content_constructor(&content, arg_list, format);
    list_constructor(&list, &content)
    printed_chars = 0;
    i = -1;
    while (format[++i])
    {
        if (format[i] == '%')
        {
			if (!get_conversion(&list, &content, &i))
				write(2, "Error -> bad input.\n", 20);

  
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:46:37 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/05 20:31:30 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_conversion(t_todo *list, t_content *content, int *i)
{
	int		j = -1;
//i is '%' place
    while (content->format[++i] && !(spec_check(content->format[i])))
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
//           (error check?)
    }
	list->spec == content->format[i];
	dispatch(list, content, i);
	return (1);
}

int     begin_parse(const char *format, va_list arg_list)
{
    int         i;
    t_todo      list;
    t_content   content;

    init_content(&content, arg_list, format);
    init_list(&list, &content)
    printed_chars = 0;
    i = -1;
    while (format[++i])
    {
        if (format[i] == '%')
        {
			if (!get_conversion(&list, &content, &i))
				write(2, "Error -> bad input.\n", 20);
		}
		else
		{
			ft_putchar_fd(format[i], content.fd);
			content.r_val++;
		}
	}
	return (content.r_val);
}

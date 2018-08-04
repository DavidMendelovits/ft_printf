/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:46:37 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/04 16:01:35 by dmendelo         ###   ########.fr       */
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
            apply_flags(&list, content, i);
        else if (content->format[i] == '.')
            apply_precision(list, content, i);
        else if (ft_isdigit(content->format[i]))
            apply_width(list, content, i);
        else if (ft_isalpha(content->format[i]))
            apply_length(list, content, i);
//        else if (content->format[i] =='&')
//            content->r_val += apply_colors(list, content, i);
    }
	
	
	
	while (flagger[++j].op)
    {
        if (format[i + 1] == flagger[j].op[0])
        {
            if(!r_val = flagger[j].f(arg_list))
                return (0);
            break ;
        }
    }
    return (r_val);
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
			r_val = get_conversion(&list, &content, &i);
     //       j = -1;
     //       while (flagger[++j].op)
     //       {
     //           if (format[i + 1] == flagger[j].op[0])
     //           {
     //               r_val = flagger[j].f(arg_list);
     //               if (r_val == -1)
     //                   return (-1);
     //               printed_chars += r_val;
     //               break ;
     //           }
     //       }
            if (flagger[j].op == NULL && format[i + 1] != ' ')
            {
                if (format[i + 1] != '\0')
                {
                    ft_putchar(format[i]);
                    ft_putchar(format[i + 1]);
                    printed_chars += 2;
                }
                else
                    return (-1);
            }
            i += 1;
        }
        else
        {
            ft_putchar(format[i]);
            printed_chars++;
        }
    }
    return (printed_chars);
}

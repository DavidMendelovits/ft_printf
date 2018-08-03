/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:46:37 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/29 18:04:21 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_conversion(const char *format, flag_handler flagger[], va_list arg_list, int i)
{
	int		j = -1;
    int     r_val;

    //check for precision
    //check for width
    //check for conversion flags (single vs double)
    //check for padding
    //
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

int     begin_parse(const char *format, flag_handler flagger[], va_list arg_list)
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
			r_val = get_conversion(format, flagger, arg_list, i)
            j = -1;
            while (flagger[++j].op)
            {
                if (format[i + 1] == flagger[j].op[0])
                {
                    r_val = flagger[j].f(arg_list);
                    if (r_val == -1)
                        return (-1);
                    printed_chars += r_val;
                    break ;
                }
            }
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:04:18 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/07 16:45:31 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     apply_flags(t_todo *list, t_content *content, int *i)
{
//	WOW();
    int     tmp;

    tmp = *i;
    while (flag_check(content->format[tmp]))
    {
        if (content->format[tmp] == '#')
		{
            list->alt_form = 1;
//			printf("alt_form\n");
		}
		else if (content->format[tmp] == ' ')
            list->prepend_space = 1;
        else if (content->format[tmp] == '0' && !list->left_align)
            list->prepend_zero = 1;
        else if (content->format[tmp] == '-')
            list->left_align = 1;
        else if (content->format[tmp] == '+')
            list->show_sign = 1;
		tmp += 1;
    }
	*i = tmp - 1;
    return (1);
}


int     flag_check(char c)
{
//	WOW();
    if (c == '#'|| c == '-' || c == '+'|| c == ' ' || c == '0')
        return (1);
    return (0);
}

int     is_wildcard(char c)
{
//	WOW();
    if (c == '*' )
        return (1);
    return (0);
    //consider reading argument for wildcard and applying it in this function?
}

void     apply_precision(t_todo *list, t_content *content, int *i)
{
//	WOW();
	int		tmp;
	int		p_len;

	tmp = *i + 1;
//	printf("format[%d] = %c\n", tmp, content->format[tmp]);
	p_len = 0;
	list->precision = 0;
	while ((content->format[tmp] != '.')
		&& !(is_wildcard(content->format[tmp]))
		&& !(spec_check(content->format[tmp])))
	{
		if (p_len > 0)
			list->precision *= 10;
		list->precision	+= (content->format[tmp] - '0');
//		printf("format[%d] = %c\n", tmp, content->format[tmp]);
//		printf("precision: %d\n", list->precision);
		p_len++;
		tmp += 1;
	}
//	printf("p_len: %d\n", p_len);
	if (p_len == 0 && content->format[tmp] == '*')
	{
		get_wildcard(&list->precision, content, &p_len);
		*i += 1;
	}
	else
	{
		*i += p_len;
	}
}

int		spec_check(char c)
{
//	WOW();
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p'
	|| c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'o'
	|| c == 'O' || c == 'x' || c == 'X' || c == 'b' || c == '%'
	|| c == 'U')
		return (1);
//	printf("->return 0\n");
	return (0);
}

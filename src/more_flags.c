/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:16:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/07 14:11:16 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_width(t_todo *list, t_content *content, int *i)
{
//	WOW();
	int		tmp;
	int		w_len;

	tmp = *i;
	w_len = 0;
	list->width = 0;
	while (!(is_wildcard(content->format[tmp]))
		&& !(spec_check(content->format[tmp]))
		&& !(content->format[tmp] == '.'))
	{
		if (w_len > 0)
			list->width *= 10;
//		printf("format[%d] = %c\n", tmp, content->format[tmp]);
//		printf("width: %d\n", list->width);
		list->width += (content->format[tmp] - '0');
		w_len++;
		tmp += 1;
	}
	if (w_len == 0)
	{
		get_wildcard(&list->width, content, &w_len);
	}
	else
	{
		*i += w_len - 1;
	}
//	printf("list->width = %d\n", list->width);
//	printf("w_len = %d\n", w_len);

//	printf("*i = %d\n", *i);
}

int		ft_number_len(unsigned long n)
{
//	WOW();
	int		len;
	
	len = 1;
	while (n)
	{
//		printf("%lu\n", n);
		n /= 10;
		if (n)
		{
			len += 1;
		}
	}
	return (len);
}

int		ft_number_len_base(unsigned long n, int radix)
{
//	WOW();
	int		len;
	
	len = 1;
	while (n)
	{
//		printf("%lu\n", n);
		n /= radix;
		if (n)
		{
			len += 1;
		}
	}
	return (len);
}
void	get_wildcard(int *value, t_content *content, int *len)
{
//	WOW();
	*value = va_arg(*(content)->arg_list, int);
//	printf("wildcard = %d\n", *value);
	*len += ft_number_len(*value);
}

void	apply_length(t_todo *list, t_content *content, int *i)
{
//	WOW();
	int		tmp;

	tmp = *i;
	if (content->format[tmp] == 'h' && content->format[tmp + 1] == 'h'
	&& spec_check(content->format[tmp + 2]))
		ft_strcpy(list->length, "hh\0");
	else if (content->format[tmp] == 'h' 
	&& spec_check(content->format[tmp + 1]))
		ft_strcpy(list->length, "h\0");
	else if (content->format[tmp] == 'l' && content->format[tmp + 1] == 'l'
	&& spec_check(content->format[tmp + 2]))
		ft_strcpy(list->length, "ll\0");
	else if (content->format[tmp] == 'l'
	&& spec_check(content->format[tmp + 1]))
		ft_strcpy(list->length, "l\0");
	else if (content->format[tmp] == 'j'
	&& spec_check(content->format[tmp + 1]))
		list->length[0] = 'j';
	else if (content->format[tmp] == 'z'
	&& spec_check(content->format[tmp]))
		list->length[0] = 'z';
	*i += ft_strlen(list->length) - 1;
//	printf("list->length: %s\n", list->length);
}

int     validate_len(char c)
{
//	WOW();
    if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
        return (1);
    return (0);
}

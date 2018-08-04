/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:16:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/04 16:01:42 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_width(t_todo *list, t_content *content, int *i)
{
	int		tmp;
	int		w_len;

	tmp = i;
	w_len = 0;
	while (!(flag_check(content->format[++tmp])
		&& !(is_wildcard(content->format[tmp]))))
	{
		if (w_len > 0)
			list->width *= 10;
		list->width += ft_atoi(content->format[tmp]);
		w_len++;
	}
	if (w_len == 0)
		get_wildcard(list->width, content, &w_len);
	i += w_len;
}

void	get_wildcard(int *value, t_content *content, int *len)
{
	value = va_arg(content->arg_list, int);
	len += ft_strlen(value);
}

void	apply_length(t_todo *list, t_content *content, int *i)
{
	int		tmp;

	tmp = i;
	if (content->format[tmp] == 'h' && content->format[tmp + 1] == 'h'
	&& spec_check(content->format[tmp + 2]))
		ft_strcpy(list->length_cast, "hh\0");
	else if (content->format[tmp] == 'h' 
	&& spec_check(content->format[tmp + 1]))
		ft_strcpy(list->length_cast, "h\0");
	else if (content->format[tmp] == 'l' && content->format[tmp + 1] == 'l'
	&& spec_check(content->format[tmp + 2]))
		ft_strcpy(list->length_cast, "ll\0");
	else if (content->format[tmp] == 'l'
	&& spec_check(content->format[tmp + 1]))
		ft_strcpy(list->length_cast, "l\0");
	else if (content->format[tmp] == 'j'
	&& spec_check(content->format[tmp + 1]))
		list->length_cast[0] = 'j';
	else if (content->format[tmp] == 'z'
	&& spec_check(content->format[tmp]))
		list->length_cast[0] == 'z';
	i += ft_strlen(list->length_cast);
}

int     validate_len(char c)
{
    if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
        return (1);
    return (0);
}

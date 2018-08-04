/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:16:03 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/04 10:22:29 by dmendelo         ###   ########.fr       */
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
	int		len_len;

	tmp = i;
	len_len = 0;
	while (!(flag_check(content->format[++tmp])))
	{
		//
	}
}

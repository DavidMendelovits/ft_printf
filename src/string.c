/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 16:34:07 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/05 20:31:25 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(t_todo *list, t_content *content, int *i)
{
	int		str;

	str = eval_str(list)
	if (list->spec == 's')
		print_string(list, content);
	else if (list->spec == 'S')
		print_wide_string(list, content);
}
/*
int		eval_str(t_todo *list)
{
	if (list->spec == 's')
		return (1);
	else if (list->spec == 'S')
		return (2);
}
*/
void	print_string(t_todo *list, t_content *content)
{
	list->data->str = va_arg(content->arg_list, char*);
	list->len = ft_strlen(list->data->str);
	if (list->left_align)
	{
		print_precision(list, content);
		print_width(list, content);
	}
	else
	{
		print_width(list, content);
		print_precision(list, content);
	}	
}

void	print_wchar_string(t_todo *list, t_content *content)
{
	list->data->
}

void	print_width(t_todo *list, t_content *content)
{
	int		pad;
	char	pad_char;

	if (list->prepend_zero)
		pad_char = '0';
	else
		pad_char = ' ';
	if (list->precision >= 0 && list->precision < list->len)
		pad = list->width - list->precision;
	else
		pad = list->width - list->precision;
	while (pad > 0)
	{
		write(content->fd, pad_char, 1);
		pad--;
		content->rval++;
	}
}

void	print_precision(t_todo *list, t_content *content)
{
	int		_precision;

	if (list->precision != -1 && list->precision < list->len)
		_precision = list->precision;
	else
		_precision = list->len;
	write(content->fd, list->data->str, _precision);
	content->r_val += _precision;
}

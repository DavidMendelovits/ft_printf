/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 16:34:07 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 07:45:35 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(t_todo *list, t_content *content)
{
//	WOW();
	if (list->spec == 's')
		print_string(list, content);
	else if (list->spec == 'S')
		print_wide_string(list, content);
}

char	*wstring_dup(t_content *content)
{
	char		*dup;
	wchar_t		*reg;
	int			i;

	reg = va_arg(*content->arg_list, wchar_t *);
	dup = (char *)malloc(sizeof(char) * (ft_strlen((char*)reg) + 1));
	i = 0;
	while (reg[i])
	{
		dup[i] = (char)reg[i];
		i += 1;
	}
	dup[i] = '\0';
	return (dup);
}

void	print_wide_string(t_todo *list, t_content *content)
{
//	WOW();
	list->data->str = wstring_dup(content);
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

void	character(t_todo *list, t_content *content)
{
//	WOW();
	list->data->character = va_arg(*content->arg_list, int);
	list->len = 1;
	if (list->left_align)
	{
		write(1, &list->data->character, 1);
		print_width(list, content);
	}
	else
	{
		print_width(list, content);
		write(1, &list->data->character, 1);
	}
	content->r_val += 1;
}

void	print_string(t_todo *list, t_content *content)
{
//	WOW();
	list->data->str = va_arg(*content->arg_list, char*);
	if (!list->data->str)
	{
		write(1, "(null)", 6);
		content->r_val += 6;
		return ;
	}
//	printf("str: %s\n", list->data->str);
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
//	write(1, &list->data->str, list->len);
//	content->r_val += list->len;
}

//void	print_wchar_string(t_todo *list, t_content *content)
//{
//	list->data->
//}

void	print_width(t_todo *list, t_content *content)
{
//	WOW();
	int		pad;
	char	pad_char;

	if (list->prepend_zero)
		pad_char = '0';
	else
		pad_char = ' ';
	if (list->precision >= 0 && (list->spec == 's' || list->spec == 'S') && ft_strlen(list->data->str) == 0)
		pad = list->width - list->len;
	else if (list->precision > 0 && (list->spec == 's' || list->spec == 'S') &&
			list->len > list->precision)
		pad = list->width - list->precision;
	else if (list->precision > 0 && list->precision >= list->len && (list->spec == 'd' || list->spec == 'i'))
	{
		pad = list->width - list->precision;
	//	printf("pad = %d\n", pad);
	}
	else if (list->precision > 0 && list->precision > list->len)
		pad = list->width - list->precision;
	else if (list->precision == 0 && list->data->u_num == 0)
		pad = list->width - list->precision;
	else
		pad = list->width - list->len;
	if (list->alt_form && (list->spec == 'x' || list->spec == 'X'))
		pad -= 2;
	else if (list->alt_form && (list->spec == 'o' || list->spec == 'O'))
		pad -= 1;
	if (list->precision > 0 && list->width > 0)
		pad_char = ' ';
	if (list->data->num < 0 || list->show_sign)
	{
		pad -= 1;
	}
	while (pad > 0)
	{
		write(content->fd, &pad_char, 1);
		pad--;
		content->r_val++;
	}
}

void	print_precision(t_todo *list, t_content *content)
{
//	WOW();
	int		_precision;

	if (list->precision != -1 && list->precision < list->len)
		_precision = list->precision;
	else
		_precision = list->len;
	write(content->fd, list->data->str, _precision);
	content->r_val += _precision;
}

void	percent(t_todo *list, t_content *content)
{
	list->len = 1;
	if (list->left_align)
	{
		write(1, "%", 1);
		print_width(list, content);
	}
	else
	{
		print_width(list, content);
		write(1, "%", 1);
	}
	content->r_val += 1;
}

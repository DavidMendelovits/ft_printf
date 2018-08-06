/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 16:33:58 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/05 20:31:28 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_conversion(t_todo *list, t_content *content)
{
	if (list->length_cast[0] == '\0')
		list->data->u_num == va_arg(content->arg_list, unsigned int);
	else if (list->length_cast[0] == 'h' && list->length_cast[1] == 'h')
	{	
		list->data->u_num == 
			(unsigned char)va_arg(content->arg_list, unsigned int);
	}
	else if (list->length_cast[0] == 'h')
	{
		list->data->u_num ==
			(unsigned short)va_arg(content->arg_list, unsigned int);
	}
	else if (list->length_cast[0] == 'l' && list->length_cast[1] == 'l')
		list->data->u_num == va_arg(content->arg_list, unsigned long long);
	else if (list->length_cast[0] == 'l')
		list->data->u_num == va_arg(content->arg_list, unsigned long);
	else if (list->length_cast[0] == 'j')
		list->data->u_num == va_arg(content->arg_list, uintmax_t);
	else if (list->length_cast[0] == 'z')
		list->data->u_num == va_arg(content->arg_list, size_t);
}

void	conversion(t_todo *list, t_content *content)
{
	if (list->length_cast[0] == '\0')
		list->data->num == va_arg(content->arg_list, int);
	else if (list->length_cast[0] == 'h' && list->length_cast[1] == 'h')
		list->data->num == (char)va_arg(content->arg_list, int);
	else if (list->length_cast[0] == 'h')
		list->data->num == (short)va_arg(content->arg_list, int);
	else if (list->length_cast[0] == 'l' && list->length_cast[1] == 'l')
		list->data->num == va_arg(content->arg_list, long long);
	else if (list->length_cast[0] == 'l')
		list->data->num == va_arg(content->arg_list, long);
	else if (list->length_cast[0] == 'j')
		list->data->num == va_arg(content->arg_list, intmax_t);
	else if (list->length_cast[0] == 'z')
		list->data->num == va_arg(content->arg_list, size_t);
}

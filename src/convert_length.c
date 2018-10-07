/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 16:33:58 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/07 15:31:32 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_conversion(t_todo *list, t_content *content)
{
//	WOW();
	if (list->length[0] == '\0')
		list->data->u_num = va_arg(*content->arg_list, unsigned int);
	else if (list->length[0] == 'h' && list->length[1] == 'h')
	{	
		list->data->u_num = 
			(unsigned char)va_arg(*content->arg_list, unsigned int);
	}
	else if (list->length[0] == 'h')
	{
		list->data->u_num =
			(unsigned short)va_arg(*content->arg_list, unsigned int);
	}
	else if (list->length[0] == 'l' && list->length[1] == 'l')
		list->data->u_num = va_arg(*content->arg_list, unsigned long long);
	else if (list->length[0] == 'l')
		list->data->u_num = va_arg(*content->arg_list, unsigned long);
	else if (list->length[0] == 'j')
		list->data->u_num = va_arg(*content->arg_list, uintmax_t);
	else if (list->length[0] == 'z')
		list->data->u_num = va_arg(*content->arg_list, size_t);
}

void	conversion(t_todo *list, t_content *content)
{
//	WOW();
	if (list->length[0] == '\0')
	{
		list->data->num = va_arg(*content->arg_list, int);
//		printf("none\n");
	}
	else if (list->length[0] == 'h' && list->length[1] == 'h')
	{
//		printf("hh\n");
		list->data->num = (signed char)va_arg(*content->arg_list, int);
	}
	else if (list->length[0] == 'h')
		list->data->num = (short)va_arg(*content->arg_list, int);
	else if (list->length[0] == 'l' && list->length[1] == 'l')
		list->data->num = va_arg(*content->arg_list, long long);
	else if (list->length[0] == 'l')
		list->data->num = va_arg(*content->arg_list, long);
	else if (list->length[0] == 'j')
		list->data->num = va_arg(*content->arg_list, intmax_t);
	else if (list->length[0] == 'z')
	{
		list->data->num = va_arg(*content->arg_list, size_t);
	//	printf("\nz\n");
	}
}

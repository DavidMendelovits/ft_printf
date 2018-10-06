/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:19:24 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/05 18:36:05 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_zero(t_todo *list, t_content *content)
{
	int			zero;
	char		_z;

	_z = '0';
	zero = list->precision - list->len;
	printf("precision (%d) - len(%d)\n", list->precision, list->len);
	while (zero > 0)
	{
		write(1, &_z, 1);
		zero -= 1;
		content->r_val += 1;
	}
}

void		decimal(t_todo *list, t_content *content)
{
	WOW();
	list->data->num = va_arg(*content->arg_list, int);
	list->len = ft_number_len(list->data->num);
	if (list->left_align)
	{
		ft_putnbr(list->data->num);
		print_width(list, content);
	}
	else
	{
		print_width(list, content);
		print_zero(list, content);
		ft_putnbr(list->data->num);
	}
}

void		unsigned_int(t_todo *list, t_content *content)
{
	WOW();
	list->data->u_num = va_arg(*content->arg_list, unsigned int);
	printf("u_num = %ju\n", list->data->u_num);
	list->len = ft_number_len(list->data->u_num);
	printf("len: %d\n", list->len);
	if (list->left_align)
	{
		ft_putnbr_base(list->data->u_num, 10);
		print_width(list, content);
	}
	else
	{
		print_width(list, content);
		print_zero(list, content);
		ft_putnbr_base(list->data->u_num, 10);
	}
}

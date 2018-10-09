/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:28:01 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 08:47:02 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_number_len(const intmax_t _number)
{
//	WOW();
	int			len;
	intmax_t	number;

	len = 0;
	number = _number;
	if (number < 0)
	{
		number *= -1;
//		len += 1;
	}
	len += ft_number_len_base(number, 10);
//	printf("len: %d\n", len);
	return (len);
}

void			prepend_sign(t_todo *list, t_content *content)
{
	//WOW();
	if (list->prepend_space && list->data->num >= 0 && !list->appended_sign && !(list->width > 0 && list->precision > 0))
	{
		write(1, " ", 1);
		list->appended_sign = 1;
		list->len += 1;
	}
	else if (list->show_sign && list->data->num >= 0 && !list->appended_sign)
	{
		write(1, "+", 1);
		list->appended_sign = 1;
		list->len += 1;
	}
	content->r_val += 0;
}

void			print_number(t_todo *list, t_content *content, char *base)
{
//	WOW();
	int			radix;

	radix = ft_strlen(base);
	if (list->show_sign && list->data->num >= 0)
	{
		prepend_sign(list, content);
	}
	else if (list->data->num < 0)
	{
		list->data->num *= -1;
		content->r_val += 1;
	}
	if (list->precision  || list->data->num)
	{
		content->r_val += list->len;
		if (list->appended_sign)
			list->len -= 1;
		print_zero(list, content);
		ft_putnbr_base(list->data->num, base, 10);
//		printf("r_val + list->len = r_val(%d)\n", content->r_val);
	}
}


void			decimal(t_todo *list, t_content *content)
{
//	WOW();
	conversion(list, content);
//	printf("content->r_val = %d\n", content->r_val);
	list->len = get_number_len(list->data->num);
	if (list->left_align)
	{
		if (list->data->num < 0)
		{
			write(1, "-", 1);
			list->len += 1;
		}
		else if (list->prepend_space && list->data->num >= 0)
			prepend_sign(list, content);
		print_number(list, content, "0123456789");
		print_width(list, content);	
	}
	else
	{
//		if (list->appended_sign)
//			list->len -= 1;
		if (list->prepend_zero && list->precision <= 0 && list->data->num < 0)
		{
			write(1, "-", 1);
			print_width(list, content);
		}
		else if (list->data->num < 0)
		{
			print_width(list, content);
			write(1, "-", 1);
		}
		else
		{
			if (list->prepend_zero && list->width)
			{
				prepend_sign(list, content);
				if (list->appended_sign)
					list->len -= 1;
				print_width(list, content);
				if (list->appended_sign)
					list->len += 1;
			}
			else
			{
				print_width(list, content);
				if ((list->prepend_space || list->show_sign) && list->data->num >= 0)
					prepend_sign(list, content);
			}
		}
//		if (list->appended_sign)
//			list->len -= 1;
//		if (list->appended_sign)
//			list->len += 1;
		print_number(list, content, "0123456789");
	}
}

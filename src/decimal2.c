/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:28:01 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/08 18:41:26 by dmendelo         ###   ########.fr       */
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
	if (list->prepend_space && list->data->num >= 0)
	{
		write(1, " ", 1);
		list->prepend_space = 0;
	}
	else if (list->show_sign && list->data->num >= 0)
	{
		write(1, "+", 1);
		list->show_sign = 0;
	}
	list->len += 1;
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
		print_zero(list, content);
		content->r_val += list->len;
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
//		printf("content->r_val = %d\n", content->r_val);
		print_number(list, content, "0123456789");
//		printf("content->r_val = %d\n", content->r_val);
		print_width(list, content);	
//		printf("content->r_val = %d\n", content->r_val);
	}
	else
	{
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
			if ((list->prepend_space || list->show_sign) && list->data->num >= 0)
				prepend_sign(list, content);
			print_width(list, content);
		}
//	printf("content->r_val = %d\n", content->r_val);
		print_number(list, content, "0123456789");
//		printf("content->r_val = %d\n", content->r_val);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:19:24 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/09 07:13:29 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_zero(t_todo *list, t_content *content)
{
	int			zero;
	char		_z;

	_z = '0';
	zero = list->precision - list->len;
	if (list->alt_form && (list->spec == 'x' || list->spec == 'X'))
	{
//		zero += 2;
	//	list->width -= 2;
	}
	if (list->alt_form && (list->spec == 'x' || list->spec == 'X') && list->prepend_zero)
	{
		list->width -= 2;
	}
	if (list->alt_form && (list->spec == 'o' || list->spec == 'O'))
		zero -= 1;
	while (zero > 0)
	{
		write(1, &_z, 1);
		zero -= 1;
		content->r_val += 1;
	}
}
/*
void		prepend_sign(t_todo *list, t_content *content)
{
	if (list->prepend_space && list->data->num >= 0)
	{
		write(1, " ", 1);
	}
//	else if (list->show_sign && list->data->num > 0)
//	{
//		write(1, "+", 1);
//	}
	list->len += 1;
	content->r_val += 1;
//	list->len += 1;
}
*/
/*
void		decimal(t_todo *list, t_content *content)
{
//	WOW();
//	list->data->num = va_arg(*content->arg_list, int);
	conversion(list, content);
//	if (!list->data->num)
	//{
//		write(1, "0", 1);
//		return ;
//	}
//	printf("list->data->num: %jd\n", list->data->num);
	if (list->data->num < 0)
	{
		list->data->num *= -1;
		list->len = ft_number_len(list->data->num);
		list->data->num *= -1;
//		list->len += 1;
	}
	else
		list->len = ft_number_len(list->data->num);
//	printf("\n1\n");
	if (list->left_align)
	{
		if (list->prepend_space && list->data->num > 0)
		{
			write(1, " ", 1);
		}
		if (list->data->num && list->precision)
			ft_putnbr_base(list->data->num, "0123456789", 10);
		else if (list->precision > 0)
			return ;
		print_width(list, content);
	}
	else
	{
		if (list->show_sign)
		{
			if (list->data->num > 0)
				write(1, "+", 1);
		}
		else if (list->prepend_space && list->data->num >= 0)
			prepend_sign(list, content);
		print_width(list, content);
		if (list->data->num < 0)
		{
			list->data->num *= -1;
			write(1, "-", 1);
		}
		print_zero(list, content);
		if (list->data->num)
			ft_putnbr_base(list->data->num, "0123456789", 10);
		else if (list->precision)
			write(1, "0", 1);
	}
	content->r_val += list->len;
}
*/
/*
void		percent(t_todo *list, t_content *content)
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
}
*/
void		unsigned_int(t_todo *list, t_content *content)
{
//	WOW();
//	list->data->u_num = va_arg(*content->arg_list, unsigned int);
	unsigned_conversion(list, content);
//	printf("u_num = %ju\n", list->data->u_num);
	list->len = ft_number_len(list->data->u_num);
//	printf("len: %d\n", list->len);
	if (list->left_align)
	{
		ft_putnbr_base(list->data->u_num, "0123456789", 10);
		print_width(list, content);
	}
	else
	{
		print_width(list, content);
		print_zero(list, content);
		ft_putnbr_base(list->data->u_num, "0123456789", 10);
	}
	content->r_val += list->len;
}

void		octal(t_todo *list, t_content *content)
{
//	WOW();
	unsigned_conversion(list, content);
	list->len = ft_number_len_base(list->data->u_num, 8);
	if (list->alt_form)
		list->len += 1;
//	printf("octal: %jo\n", list->data->num);
	if (list->left_align)
	{
		if (list->alt_form && list->data->u_num)
		{
			write(1, "0", 1);
		}
		ft_putnbr_base(list->data->u_num, "01234567", 8);
		print_width(list, content);
	}
	else
	{
		print_width(list, content);
		if (list->alt_form && list->data->u_num)
		{
			write(1, "0", 1);
		}
//		printf("\nprecision -. %d\n", list->precision);
		if (list->precision > 0)	
			print_zero(list, content);
		if (list->data->u_num || list->precision)
			ft_putnbr_base(list->data->u_num, "01234567", 8);
		else if (list->data->u_num == 0 && list->precision == 0 && list->alt_form)
		{
			write(1, "0", 1);
		}
//		else if (!list->precision)
//			write(1, "0", 1);
//		else if (list->alt_form)
//			write(1, "0", 1);
	}
	content->r_val += list->len;
}

void		binary(t_todo *list, t_content *content)
{
//	WOW();
	unsigned_conversion(list, content);
	list->len = ft_number_len_base(list->data->u_num, 2);
	if (list->left_align)
	{
		ft_putnbr_base(list->data->num, "01", 2);
		print_width(list, content);
	}
	else
	{
		print_width(list, content);
		ft_putnbr_base(list->data->num, "01", 2);
	}
	content->r_val += list->len;
}

void		hex(t_todo *list, t_content *content)
{
//	WOW();
	char		base[17];
	char		prefix[3];

	if (list->spec == 'X')
	{
		ft_strcpy(base, "0123456789ABCDEF");
	}
	else if (list->spec == 'x')
	{
		ft_strcpy(base, "0123456789abcdef");
	}
	unsigned_conversion(list, content);
//	if (!list->data->u_num && list->precision == 0)
//		return ;
	list->len = ft_number_len_base(list->data->u_num, 16);
	if (list->alt_form && list->spec == 'X' && list->data->u_num)
		ft_strcpy(prefix, "0X");
	else if (list->alt_form && list->spec == 'x' && list->data->u_num)
		ft_strcpy(prefix, "0x");
	if (list->alt_form && list->data->u_num)
		content->r_val += 2;
	else
		ft_bzero(prefix, 3);
	if (list->alt_form && list->data->u_num)
		list->len += 2;
	if (list->left_align)
	{
		if (list->data->u_num)
			ft_putstr(prefix);
		ft_putnbr_base(list->data->num, base, 16);
		print_width(list, content);
	}
	else
	{
		if (list->data->u_num)
			ft_putstr(prefix);
		print_width(list, content);
		if (list->alt_form)
			list->len -= 2;
		if (list->precision > 0)
			print_zero(list, content);
		if (list->data->u_num || list->precision)
		{
			ft_putnbr_base(list->data->num, base, 16);
		}
	}
	content->r_val += list->len;
}

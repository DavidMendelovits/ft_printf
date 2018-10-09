/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:42:45 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/08 17:00:21 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_prefix(char *prefix, t_todo *list)
{
//	WOW();
	ft_bzero(prefix, 3);
	if (list->alt_form)
	{
		if (list->spec == 'X')
			ft_strcpy(prefix, "0X");
		else if (list->spec == 'x')
			ft_strcpy(prefix, "0x");
		else if (list->spec == 'o' || list->spec == 'O')
			ft_strcpy(prefix, "0");
	}
}

void			print_unsigned(t_todo *l, t_content *c, char *base, int radix)
{
//	WOW();

	if (l->precision || l->data->u_num)
	{
		if (l->precision > l->len)
			print_zero(l, c);
		ft_putnbr_base(l->data->u_num, base, radix);
		c->r_val += l->len;
	}
	else if (l->data->u_num == 0 && l->precision == 0 && l->alt_form && l->spec == 'o')
	{
		write(1, "0", 1);
		c->r_val += 1;
	}
}

void			print_prefix(char *prefix, t_content *content)
{
	ft_putstr(prefix);
	content->r_val += ft_strlen(prefix);
}

void			unsigned_number(t_todo *list, t_content *content, char *base)
{
//	WOW();
	int			radix;
	char		prefix[3];

	unsigned_conversion(list, content);
	radix = ft_strlen(base);
	list->len = ft_number_len_base(list->data->u_num, radix);
	get_prefix(prefix, list);

	if (list->left_align)
	{
		if (list->alt_form && list->data->u_num)
			print_prefix(prefix, content);
		print_unsigned(list, content, base, radix);
		print_width(list, content);
	}
	else
	{
//		if (list->prepend_space)
//			prepend_sign(list, content);
		if (list->prepend_zero && list->alt_form)
		{
			if (list->data->u_num)
				print_prefix(prefix, content);
			if (list->prepend_zero)
				print_width(list, content);
		}
		else
		{
			print_width(list, content);
			if (list->data->u_num && list->alt_form)
				print_prefix(prefix, content);
		}
		print_unsigned(list, content, base, radix);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:42:23 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/07 16:30:25 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pointer(t_todo *list, t_content *content)
{
//	unsigned long		address;

//	address = va_arg(*content->arg_list, unsigned long);
	unsigned_conversion(list, content);
	list->len = ft_number_len_base(list->data->u_num, 16);
	ft_putstr("0x");
	ft_putnbr_base(list->data->u_num, "0123456789abcdef", 16);
	print_zero(list, content);
//	print_width(list, content);
	//printf("%lx\n", address);
	list->r_val += 1;
}

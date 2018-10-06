/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:42:23 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/05 18:56:10 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pointer(t_todo *list, t_content *content)
{
	unsigned long		address;

	address = va_arg(*content->arg_list, unsigned long);
	ft_putstr("0x");
	ft_putnbr_base(address, 16);
	//printf("%lx\n", address);
	list->r_val += 1;
}

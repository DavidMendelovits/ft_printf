/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 23:01:21 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/06 09:47:09 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
//	WOW();
	int				printed_characters;
	va_list			arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	printed_characters = begin_parse(format, arg_list);
	va_end(arg_list);
	return (printed_characters);
}

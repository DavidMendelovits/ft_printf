/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 23:01:21 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/08 09:20:05 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int				printed_characters;
	flag_handler 	flagger[13];
	va_list			arg_list;

	if (format == NULL)
		return (-1);

	flagger = { {"c", print_char}, {"s", print_str}, {"%", print_percent},
				{"d", print_int}, {"i", print_int}, {"b", print_binary},
				{"r", print_rev}, {"R", print_rot13}, {"u", print_uint},
				{"o", print_octal}, {"x", print_hex}, {"X", print_HEX},
				{NULL, NULL} };
	va_start(arg_list, format);
	print_characters = begin_parse(format, flagger, arg_list);
	va_end(arg_list);
	return (printed_chars);
}

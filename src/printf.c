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
#include "print_pointer.c"

flag_handler        g_flagger[] = { {"c", print_char}, {"s", print_str},
    {"%", print_percent}, {"d", print_int}, {"i", print_int},
    {"R", ft_rot13}, {"u", print_uint}, {"p", print_ptr}, {"b", print_binary} {NULL, NULL} };
/*
    {"b", print_binary}, {"r", print_rev}, {"R", print_rotX},
    {"u", print_uint}, {"o", print_octal}, {"x", print_hex},
    {"X", print_HEX}, {NULL, NULL} };
*/

int		ft_printf(const char *format, ...)
{
	int				printed_characters;
	va_list			arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	printed_characters = begin_parse(format, g_flagger, arg_list);
	va_end(arg_list);
	return (printed_characters);
}

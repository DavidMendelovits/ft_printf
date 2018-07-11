/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:48:32 by dmendelo          #+#    #+#             */
/*   Updated: 2018/07/07 23:00:43 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

//op = operator, f = translation function
struct flagHandler
{
	char	*op;
	int		(*f)(va_list);
};
typedef struct flagHandler flag_handler;

int     begin_parse(const char *format, flag_handler flagger[], va_list arg_list);
int		ft_printf(const char *format, ...);
int     print_char(va_list arg_list);
int		print_str(va_list arg_list);
int     print_int(va_list arg_list);
int     print_uint(va_list arg_list);
int     print_number(va_list arg_list);
int     print_percent(__attribute__((unused))va_list arg_list);
int     ft_rot13(va_list arg_list);


# endif

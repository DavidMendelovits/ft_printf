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
#include "../libft/libft.h"

//op = operator, f = translation function
typedef struct  s_handler
{
	char	*op;
	int		(*f)(va_list);
}               t_handler;

typedef struct      s_content
{
    int     fd;
    int     r_val;
    char    *format;
    va_list arg_list;
}                   t_content;

typedef struct      s_todo
{
    int         alt_form;
    int         left_align;
    int         prepend_space;
    int         prepend_zero;
    int         show_sign;
    char        length[3];
    char        type;
    int         len;
    int         precision;
    int         width;
    int         *ret;
    int         *fd;
    va_list     *arg_list;
    raw         data;
}                   t_todo;

int     begin_parse(const char *format, flag_handler flagger[], va_list arg_list);
int		ft_printf(const char *format, ...);
int     print_char(va_list arg_list);
int		print_str(va_list arg_list);
int     print_int(va_list arg_list);
int     print_uint(va_list arg_list);
int     print_number(va_list arg_list);
int     print_percent(__attribute__((unused))va_list arg_list);
int     print_ptr(va_list arg_list);
int     print_adr(unsigned long n);
int     ft_rot13(va_list arg_list);
char    *itoabase(long long n, int base);


# endif

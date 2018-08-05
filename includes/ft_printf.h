/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:48:32 by dmendelo          #+#    #+#             */
/*   Updated: 2018/08/04 20:50:33 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include "../libft/libft.h"

//op = operator, f = translation function
/*
typedef struct      s_handler
{
	char	*op;
	int		(*f)(va_list);
}                   t_handler;
*/
typedef struct      s_content
{
    int     fd;
    int     r_val;
    char    *format;
    va_list arg_list;
}                   t_content;


typedef struct      s_todo
{
    va_list     *arg_list;
    int         alt_form:1;
    int         left_align:1;
    int         prepend_space:1;
    int         prepend_zero:1;
    int         show_sign:1;
    char        length_cast[3];
    char        type;
    int         len;
    int         precision;
    int         width;
    int         *r_value;
    int         *fd;

//raw         data;
}                   t_todo;

int		ft_printf(const char *format, ...);
int		begin_parse(const char *format, va_list arg_list);
void	content_constructor(t_content *content, va_list _arg_list, const char *format);
void	list_constructor(t_todo *list, t_content *content);
int		get_conversion(t_todo *list, t_content *content, int *i);
int		apply_flags(t_todo *list, t_content *content, int *i);
void	apply_precision(t_todo *list, t_content *content, int *i);
void	apply_width(t_todo *list, t_content *content, int *i);
void	*apply_length(t_todo *list, t_content *content, int *i);
int		flag_check(char c);
int		is_wildcard(char c);
void	get_wildcard(char c);
int		spec_check(char c);
int		validate_len(char c);
void    dispatch(t_todo list, t_content *content, int *i);



//format these for new parsing engine

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

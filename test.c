/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:37:43 by dmendelo          #+#    #+#             */
/*   Updated: 2018/10/08 11:27:48 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				main(void)
{
	ft_printf("->%x\n", 42);
	printf("->%x\n", 42);
	ft_printf("<-%-x\n", 42);
	printf("<-%-x\n", 42);
	return (0);
}

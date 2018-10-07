/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:49:11 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/21 17:44:33 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*c_set;

	if (!s || !c)
		return (NULL);
	if (!(c_set = ft_strnew(2)))
		return (NULL);
	c_set[0] = c;
	return (ft_strsplit_c_set((char*)s, c_set));
}

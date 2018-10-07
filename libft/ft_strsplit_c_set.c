/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_c_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:08:02 by dmendelo          #+#    #+#             */
/*   Updated: 2018/04/23 17:38:26 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c, char const *c_set)
{
	int		i;

	i = 0;
	while (c_set[i])
	{
		if (c == c_set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, const char *c_set)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] && is_separator(str[i], c_set))
		i++;
	if (str[i] && !is_separator(str[i], c_set))
		count = 1;
	while (str[i])
	{
		if (!is_separator(str[i], c_set) && is_separator(str[i - 1], c_set))
			count++;
		i++;
	}
	return (count);
}

static int	word_size(char *str, char const *c_set)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] && !is_separator(str[i], c_set))
	{
		size++;
		i++;
	}
	return (size);
}

char		**ft_strsplit_c_set(char *str, const char *c_set)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	if (!(tab = (char**)malloc(sizeof(char*) *
					(count_words(str, c_set) + 1))))
		return (NULL);
	i = -1;
	index = -1;
	while (str[++i])
		if (!is_separator(str[i], c_set))
		{
			if (index == -1 || is_separator(str[i - 1], c_set))
			{
				if (!(tab[++index] = (char*)malloc(sizeof(char) * (word_size(
										str + 1, c_set) + 1))))
					return (NULL);
				j = 0;
			}
			tab[index][j] = str[i];
			tab[index][++j] = '\0';
		}
	tab[++index] = 0;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:58:01 by wluong            #+#    #+#             */
/*   Updated: 2021/10/06 16:38:20 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	nb_words_set(char const *s, char *set)
{
	unsigned int	i;
	unsigned int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (is_in_set(s[i], set) == 0 && s[i] != '\0')
		{
			while (is_in_set(s[i], set) == 0 && s[i] != '\0')
				i++;
			words++;
		}
		while (is_in_set(s[i], set) == 1 && s[i] != '\0')
			i++;
	}
	return (words);
}

int	len_words_set(char const *s, char *set)
{
	unsigned int	i;

	i = 0;
	while (is_in_set(s[i], set) == 0 && s[i] != '\0')
	{
		i++;
	}
	return (i + 1);
}

char	**boucle_while_set(char const *s, char *set, unsigned int i, char **str)
{
	unsigned int	k;
	unsigned int	j;

	k = 0;
	while (s[i])
	{
		if (is_in_set(s[i], set) == 0 && s[i] != '\0')
		{
			j = 0;
			str[k] = malloc(sizeof(char) * len_words_set(s + i, set));
			if (!str[k])
				return (NULL);
			while (is_in_set(s[i], set) == 0 && s[i] != '\0')
			{
				str[k][j] = (char)s[i];
				j++;
				i++;
			}
			str[k][j] = '\0';
			k++;
		}
		while (is_in_set(s[i], set) == 1 && s[i] != '\0')
			i++;
	}
	return (str);
}

char	**ft_split_set(char const *s, char *set)
{
	unsigned int	i;
	char			**str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char *) * (nb_words_set(s, set) + 1));
	if (!str)
		return (NULL);
	str[nb_words_set(s, set)] = NULL;
	return (boucle_while_set(s, set, i, str));
}

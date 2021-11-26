/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:43:03 by wluong            #+#    #+#             */
/*   Updated: 2021/10/06 16:37:17 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			words++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (words);
}

int	len_words(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i + 1);
}

char	**boucle_while(char const *s, char c, unsigned int i, char **str)
{
	unsigned int	k;
	unsigned int	j;

	k = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			j = 0;
			str[k] = malloc(sizeof(char) * len_words(s + i, c));
			if (!str[k])
				return (NULL);
			while (s[i] != c && s[i] != '\0')
			{
				str[k][j] = (char)s[i];
				j++;
				i++;
			}
			str[k][j] = '\0';
			k++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char *) * (nb_words(s, c) + 1));
	if (!str)
		return (NULL);
	str[nb_words(s, c)] = NULL;
	return (boucle_while(s, c, i, str));
}

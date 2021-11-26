/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:12:47 by wluong            #+#    #+#             */
/*   Updated: 2021/10/06 16:22:30 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char const *set, int c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	index_debut(char const *s1, char const *set)
{
	int	i;

	i = 0;
	if (is_in_set(set, s1[i]) == 1)
	{
		while (is_in_set(set, s1[i]) == 1)
			i++;
	}
	return (i);
}

int	index_fin(char const *s1, char const *set)
{
	int	j;

	j = ft_strlen(s1) - 1;
	if (is_in_set(set, s1[j]) == 1)
	{
		while (is_in_set(set, s1[j]) == 1)
			j--;
	}
	return (j);
}

int	str_len(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;

	i = index_debut(s1, set);
	j = index_fin(s1, set);
	len = 0;
	if (j < i)
		return (len);
	while (i <= j)
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (NULL);
	i = index_debut(s1, set);
	j = index_fin(s1, set);
	k = 0;
	str = malloc(sizeof(char) * (str_len(s1, set) + 1));
	if (!str)
		return (NULL);
	while (i <= j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_minilib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawwar <hawwar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:55:58 by hawwar            #+#    #+#             */
/*   Updated: 2021/11/23 15:34:09 by hawwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_str_swith(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char	*ft_strjoinch(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

void	ft_free_str(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*strjoin_path(char const *s1, char const *s2)
{
	char	*tmp1;
	char	*tmp2;
	char	*result;
	int		i;
	int		j;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	i = 0;
	j = 0;
	result = (char *)malloc(ft_strlen(tmp1) + ft_strlen(tmp2) + 2);
	if (!result)
		return (NULL);
	while (tmp1[i] != '\0')
	{
		result[i] = tmp1[i];
		i++;
	}
	result[i++] = '/';
	while (tmp2[j] != '\0')
		result[i++] = tmp2[j++];
	result[i] = '\0';
	return (result);
}

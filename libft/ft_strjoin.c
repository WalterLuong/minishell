/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:19:06 by wluong            #+#    #+#             */
/*   Updated: 2021/10/14 02:09:06 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len1;
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[j + i] = s2[j];
		j++;
	}
	str[j + i] = '\0';
	return (str);
}

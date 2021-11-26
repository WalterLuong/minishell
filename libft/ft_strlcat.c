/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:28:19 by wluong            #+#    #+#             */
/*   Updated: 2020/09/30 14:01:09 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_src;

	i = 0;
	j = 0;
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	while (j < dstsize && dst[j])
		j++;
	if (dstsize <= j)
		return (len_src + dstsize);
	while (dstsize && (--dstsize - j) && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (len_src + j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:42:28 by wluong            #+#    #+#             */
/*   Updated: 2020/09/25 12:10:29 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;

	i = 0;
	d1 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	while (i < n)
	{
		d1[i] = (unsigned char)s1[i];
		if ((unsigned char)s1[i] == (unsigned char)c)
			return ((void *)d1 + i + 1);
		i++;
	}
	return (NULL);
}

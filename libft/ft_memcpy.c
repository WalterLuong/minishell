/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:21:13 by wluong            #+#    #+#             */
/*   Updated: 2020/09/24 12:15:57 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;

	i = 0;
	d1 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:32:27 by wluong            #+#    #+#             */
/*   Updated: 2021/10/06 16:30:26 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = (void *)malloc(size * count);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

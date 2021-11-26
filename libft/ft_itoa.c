/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:28:36 by wluong            #+#    #+#             */
/*   Updated: 2021/10/06 16:35:06 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*boucle_while1(char *str, long int nb, int len)
{
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			len;

	nb = n;
	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (boucle_while1(str, nb, len));
}

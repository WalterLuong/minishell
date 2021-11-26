/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:43:30 by wluong            #+#    #+#             */
/*   Updated: 2020/09/11 16:52:06 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i > 9)
	{
		ft_putnbr_fd((i / 10), fd);
		ft_putnbr_fd((i % 10), fd);
	}
	else if (i < 0 && i > -2147483648)
	{
		ft_putchar_fd('-', fd);
		i = -i;
		ft_putnbr_fd(i, fd);
	}
	else if (i == -2147483648)
	{
		ft_putnbr_fd(-21474, fd);
		ft_putnbr_fd(83648, fd);
	}
	else
		ft_putchar_fd((i + '0'), fd);
}

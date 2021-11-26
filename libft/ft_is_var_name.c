/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_var_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:23:21 by user42            #+#    #+#             */
/*   Updated: 2021/10/11 22:41:59 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_var_name(char *str)
{
	int	i;

	if (ft_isalpha(str[0]) || str[0] == '-')
	{
		i = 1;
		while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			i++;
		if (str[i])
			return (0);
		else
			return (1);
	}
	return (0);
}

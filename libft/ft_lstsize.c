/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:06:33 by wluong            #+#    #+#             */
/*   Updated: 2021/10/06 16:31:57 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			len;
	t_list		*list;

	len = 0;
	list = lst;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

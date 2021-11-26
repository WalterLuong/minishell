/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:33:54 by user42            #+#    #+#             */
/*   Updated: 2021/10/12 02:27:11 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	back = *lst;
	if (!back)
	{
		*lst = new;
		return ;
	}
	while (back->next)
		back = back->next;
	back->next = new;
}

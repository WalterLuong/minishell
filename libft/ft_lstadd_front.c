/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 10:58:35 by wluong            #+#    #+#             */
/*   Updated: 2020/09/25 12:37:54 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst[0])
	{
		alst[0] = new;
		return ;
	}
	if (!new)
		return ;
	new->next = alst[0];
	alst[0] = new;
}

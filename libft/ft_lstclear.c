/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:31:04 by wluong            #+#    #+#             */
/*   Updated: 2021/09/27 17:19:51 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*temp;

	if (!del)
		return ;
	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = temp;
		}
	}
	*lst = NULL;
}

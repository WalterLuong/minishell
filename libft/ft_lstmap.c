/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 10:17:53 by wluong            #+#    #+#             */
/*   Updated: 2021/10/06 16:34:18 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*lst_final;
	t_list		*new;

	if (!lst || !f)
		return (NULL);
	lst_final = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&lst_final, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_final, new);
		lst = lst->next;
	}
	return (lst_final);
}

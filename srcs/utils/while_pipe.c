/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:37:27 by wluong            #+#    #+#             */
/*   Updated: 2021/11/25 14:52:25 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*while_pipe(int pipe, t_list *lexer)
{
	t_elem	*this;
	t_list	*cursor;

	cursor = lexer->next;
	this = cursor->content;
	while (this->this_pipe != pipe)
	{
		this = cursor->content;
		cursor = cursor->next;
	}
	return (cursor);
}

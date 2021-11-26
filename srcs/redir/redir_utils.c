/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:25:55 by wluong            #+#    #+#             */
/*   Updated: 2021/11/22 11:46:24 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_fds(t_fds *fds)
{
	fds->last_out = NULL;
	fds->last_in = NULL;
	fds->which_redir = 0;
	fds->in = 0;
	fds->out = 0;
}

void	ending_redir(t_elem *this, t_elem *next, t_fds *fds)
{
	if (this->type == T_REDIR1)
	{
		fds->last_out = next->str;
		fds->out = 1;
	}
	else if (this->type == T_REDIR2)
	{
		fds->last_in = next->str;
		fds->in = 10;
	}
	else if (this->type == T_REDIR3)
	{
		fds->last_out = next->str;
		fds->out = 100;
	}
	else if (this->type == T_REDIR4)
	{
		fds->last_in = next->str;
		fds->in = 1000;
	}
}

void	find_the_last(t_list *lexer, int pipe, t_fds *fds)
{
	t_list	*cursor;
	t_elem	*this;
	t_elem	*next;

	cursor = while_pipe(pipe, lexer);
	this = cursor->content;
	while (cursor->next && this->this_pipe == pipe)
	{
		this = cursor->content;
		next = cursor->next->content;
		ending_redir(this, next, fds);
		cursor = cursor->next;
	}
	fds->which_redir = fds->in + fds->out;
}

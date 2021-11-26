/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:58:58 by wluong            #+#    #+#             */
/*   Updated: 2021/11/25 14:52:54 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	which_quotes(t_list *lexer)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = lexer->next;
	while (cursor)
	{
		this = cursor->content;
		if (this->str[0] == '\'')
			this->quotes = 2;
		else if (this->str[0] == '"')
			this->quotes = 1;
		cursor = cursor->next;
	}
}

int	has_error(t_elem *this, t_elem *next)
{
	if (this->type == T_REDIR1 || this->type == T_REDIR2
		|| this->type == T_REDIR3
		|| this->type == T_REDIR4 || this->type == T_REDIR5)
	{
		if (next->type != T_FD && next->type != T_DELIMITER)
		{
			ft_putstr_fd("bash : syntax error\n", 2);
			return (0);
		}
	}
	if (this->type == T_PIPE)
	{
		if (next->type == T_PIPE)
		{
			ft_putstr_fd("bash : syntax error\n", 2);
			return (0);
		}
	}
	return (1);
}

int	check_error(t_list *lexer)
{
	t_list		*cursor;
	t_elem		*this;
	t_elem		*next;

	cursor = lexer->next;
	this = cursor->content;
	if (ft_lstsize(lexer) == 2)
	{
		if (this->type != T_CMD)
		{
			ft_putstr_fd("bash : syntax error\n", 2);
			return (0);
		}
	}
	while (cursor->next)
	{
		this = cursor->content;
		next = cursor->next->content;
		if (!has_error(this, next))
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

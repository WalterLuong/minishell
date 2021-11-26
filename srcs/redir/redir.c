/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:54:59 by wluong            #+#    #+#             */
/*   Updated: 2021/11/22 12:01:53 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	skip_n_create(t_elem *this, t_elem *next, t_fds *fds)
{
	if (this->type == T_REDIR4)
	{
		if (ft_strcmp(next->str, fds->last_in))
			skip_heredoc(next->str);
	}
	else if (this->type == T_REDIR1)
	{
		if (ft_strcmp(next->str, fds->last_out))
			create_file_out(next->str);
	}
	else if (this->type == T_REDIR3)
	{
		if (ft_strcmp(next->str, fds->last_out))
			create_file_appen(next->str);
	}
}

int	apply_first_redirs(t_list *lexer, t_fds *fds, int pipe)
{
	t_list	*cursor;
	t_elem	*this;
	t_elem	*next;

	cursor = while_pipe(pipe, lexer);
	this = cursor->content;
	while (this->this_pipe == pipe && cursor->next)
	{
		this = cursor->content;
		next = cursor->next->content;
		if (this->type == T_REDIR2)
		{
			if (ft_strcmp(next->str, fds->last_in))
			{
				if (check_fd_in(next->str) == -1)
					return (1);
			}
		}
		skip_n_create(this, next, fds);
		cursor = cursor->next;
	}
	return (0);
}

int	apply_last_redirs(t_fds *fds, int pipe, t_list *lexer, char ***envp)
{
	if (fds->which_redir > 0)
	{
		if (fds->which_redir == 1)
			redir_out(fds->last_out, pipe, lexer, envp);
		if (fds->which_redir == 10)
			redir_in(fds->last_in, pipe, lexer, envp);
		if (fds->which_redir == 100)
			redir_appen(fds->last_out, pipe, lexer, envp);
		if (fds->which_redir == 1000)
			redir_heredoc(fds->last_in, pipe, lexer, envp);
		if (fds->which_redir == 11)
			redir_in_out(fds, pipe, lexer, envp);
		if (fds->which_redir == 1001)
			redir_heredoc_out(fds, pipe, lexer, envp);
		if (fds->which_redir == 110)
			redir_in_appen(fds, pipe, lexer, envp);
		if (fds->which_redir == 1100)
			redir_heredoc_appen(fds, pipe, lexer, envp);
		return (1);
	}
	return (0);
}

int	redirection(t_list *lexer, int pipe, char ***envp)
{
	t_fds	fds;

	init_fds(&fds);
	find_the_last(lexer, pipe, &fds);
	if (apply_first_redirs(lexer, &fds, pipe))
		return (1);
	if (apply_last_redirs(&fds, pipe, lexer, envp))
		return (1);
	return (0);
}

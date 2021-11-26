/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:18:53 by hawwar            #+#    #+#             */
/*   Updated: 2021/11/24 02:20:40 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_n_opt(t_list *lexer, int pipe)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = lexer->next;
	this = cursor->content;
	while (this->this_pipe < pipe)
	{
		this = cursor->content;
		cursor = cursor->next;
	}
	while (this->this_pipe == pipe && cursor)
	{
		this = cursor->content;
		if (this->type == T_OPT)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

int	how_much_args(t_list *lexer, int pipe)
{
	t_list	*cursor;
	t_elem	*this;
	int		args;

	cursor = lexer->next;
	this = cursor->content;
	args = 0;
	while (this->this_pipe < pipe)
	{
		this = cursor->content;
		cursor = cursor->next;
	}
	while (this->this_pipe == pipe && cursor)
	{
		this = cursor->content;
		if (this->type == T_ARGS || this->type == T_RES)
			args++;
		cursor = cursor->next;
	}
	return (args);
}

void	make_echo(t_elem *this, int args)
{
	if (this->type == T_ARGS)
	{
		ft_putstr_fd(this->str, 1);
		if (args > 0)
		{
			ft_putstr_fd(" ", 1);
			args--;
		}
	}
}

int	ft_echo(t_list *lexer, int pipe)
{
	int		flag;
	int		args;
	t_list	*cursor;
	t_elem	*this;

	flag = check_n_opt(lexer, pipe);
	args = how_much_args(lexer, pipe) - 1;
	cursor = lexer->next;
	this = cursor->content;
	while (this->this_pipe < pipe)
	{
		this = cursor->content;
		cursor = cursor->next;
	}
	while (this->this_pipe == pipe && cursor)
	{
		this = cursor->content;
		make_echo(this, args);
		cursor = cursor->next;
	}
	if (flag == 0)
		write(1, "\n", 1);
	return (0);
}

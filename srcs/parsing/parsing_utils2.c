/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:34:32 by wluong            #+#    #+#             */
/*   Updated: 2021/11/19 18:03:22 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	apply_option(t_elem *this, int i, t_list *cursor)
{
	t_elem	*prev;

	if (!this->str[i] && i > 1)
	{
		prev = cursor->previous->content;
		if (prev->type == T_CMD || prev->type == T_OPT)
			this->type = T_OPT;
	}
}

void	is_option(t_list *lexer)
{
	t_list	*cursor;
	t_elem	*this;
	int		i;

	cursor = lexer->next;
	while (cursor)
	{
		i = 0;
		this = cursor->content;
		if (this->type == T_ARGS && this->str[i] == '-')
		{
			i++;
			while (this->str[i])
			{
				if (this->str[i] != 'n')
					break ;
				i++;
			}
			apply_option(this, i, cursor);
		}
		cursor = cursor->next;
	}
}

int	should_interpret1(t_elem *this)
{
	if (this->type == T_SEMI)
	{
		ft_putstr_fd("Minishell does not interpret \";\"\n", 2);
		return (1);
	}
	if (this->type == T_OP_BRA || this->type == T_CL_BRA)
	{
		ft_putstr_fd("Minishell does not interpret \"{\" or \"}\"\n", 2);
		return (1);
	}
	if (this->type == T_OP_PAR || this->type == T_CL_PAR)
	{
		ft_putstr_fd("Minishell does not interpret \"(\" or \")\"\n", 2);
		return (1);
	}
	return (0);
}

int	should_interpret2(t_elem *this)
{
	if (this->type == T_AND)
	{
		ft_putstr_fd("Minishell does not interpret \"&\"\n", 2);
		return (1);
	}
	if (this->type == T_BSLASH)
	{
		ft_putstr_fd("Minishell does not interpret \"\\\"\n", 2);
		return (1);
	}
	return (0);
}

int	not_interpret(t_list *lexer)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = lexer->next;
	while (cursor)
	{
		this = cursor->content;
		if (should_interpret1(this) == 1 || should_interpret2(this) == 1)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

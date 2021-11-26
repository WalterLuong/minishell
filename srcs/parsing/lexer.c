/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:24:57 by wluong            #+#    #+#             */
/*   Updated: 2021/11/22 12:07:49 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../libft/libft.h"

int	lexing_squote(char **input)
{
	char	*str;

	str = *input;
	if (*str == '\'')
	{
		str++;
		while (*str && *str != '\'')
			str++;
		if (!*str || *str != '\'')
			return (0);
	}
	*input = str;
	return (1);
}

int	lexing_dquote(char **input)
{
	char	*str;

	str = *input;
	if (*str == '"')
	{
		str++;
		while (*str && *str != '"')
			str++;
		if (!*str || *str != '"')
			return (0);
	}
	*input = str;
	return (1);
}

int	lexing_quotes(char **input)
{
	if (**input == '"' || **input == '\'')
	{
		if (!lexing_squote(input))
			return (0);
		else if (!lexing_dquote(input))
			return (0);
		input++;
	}
	return (1);
}

void	get_new_lexer(t_list *lexer)
{
	t_list	*cursor;
	t_elem	*this;
	t_elem	*next;

	cursor = lexer->next;
	while (cursor)
	{
		this = cursor->content;
		if (this->type == T_ARGS)
		{
			if (cursor->next)
			{
				next = cursor->next->content;
				while (next->type == T_ARGS && cursor->next)
				{
					next = cursor->next->content;
					this = cursor->content;
					if (next->type == T_ARGS)
						this->type = T_SPACE;
					cursor = cursor->next;
				}
			}
		}
		cursor = cursor->next;
	}
}

int	fill_lexer(char *input, t_list **lexer)
{
	t_elem	this;
	char	*last;

	last = input;
	while (*input)
	{
		this = which_token(input);
		if ((this.str || *input == '"' || *input == '\'') && last != input)
			add_lexer(lexer, last, input - last, T_ARGS);
		if (this.str)
		{
			input = input + this.len;
			add_lexer(lexer, this.str, this.len, this.type);
			last = input;
		}
		else if (!lexing_quotes(&input))
			return (0);
		else
			input++;
	}
	if (last != input)
		add_lexer(lexer, last, input - last, T_ARGS);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 00:36:13 by wluong            #+#    #+#             */
/*   Updated: 2021/11/23 14:46:35 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_lexer(t_list *lexer)
{
	which_quotes(lexer);
	replace_var_env(lexer);
	is_fd(lexer);
	is_cmd(lexer);
}

void	add_to_new_lex(t_list **lexer, t_elem *this)
{
	t_list	*new;
	t_elem	*new_elem;

	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return ;
	new_elem->str = ft_strdup(this->str);
	new_elem->len = this->len;
	new_elem->quotes = this->quotes;
	new_elem->this_pipe = this->this_pipe;
	new_elem->type = this->type;
	new = ft_lstnew(new_elem);
	ft_lstadd_back(lexer, new);
}

void	change_lexer(t_list *tmp, t_list **lexer)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = tmp->next;
	while (cursor)
	{
		this = cursor->content;
		if (this->type != T_SPACE)
			add_to_new_lex(lexer, this);
		cursor = cursor->next;
	}
}

int	parsing(char *buf, t_list *lexer)
{
	t_list	*tmp;

	tmp = ft_lstnew(NULL);
	if (!fill_lexer(buf, &tmp))
	{
		ft_putstr_fd("Quotes are not closed !\n", 2);
		free_lexer(tmp);
		return (0);
	}
	get_new_lexer(tmp);
	change_lexer(tmp, &lexer);
	free_lexer(tmp);
	if (lexer->next)
	{
		if (!not_interpret(lexer))
		{
			parse_lexer(lexer);
			if (!check_error(lexer) || syntax_error(lexer))
				return (0);
			which_pipe(lexer);
			is_option(lexer);
			return (1);
		}
	}
	return (0);
}

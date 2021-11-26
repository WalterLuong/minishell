/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:33:19 by wluong            #+#    #+#             */
/*   Updated: 2021/11/23 15:18:41 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_elem	*existing_token(void)
{
	static t_elem	tokens[]
		= {
	{"<<", 2, 0, T_REDIR4, 0},
	{">>", 2, 0, T_REDIR3, 0},
	{">|", 2, 0, T_REDIR1, 0},
	{"<>", 2, 0, T_REDIR5, 0},
	{">", 1, 0, T_REDIR1, 0},
	{"<", 1, 0, T_REDIR2, 0},
	{"(", 1, 0, T_OP_PAR, 0},
	{")", 1, 0, T_CL_PAR, 0},
	{"}", 1, 0, T_CL_BRA, 0},
	{"{", 1, 0, T_OP_BRA, 0},
	{";", 1, 0, T_SEMI, 0},
	{"|", 1, 0, T_PIPE, 0},
	{"&", 1, 0, T_AND, 0},
	{" ", 1, 0, T_SPACE, 0},
	{"\\", 1, 0, T_BSLASH, 0},
	{"\n", 1, 0, T_SPACE, 0},
	{"\t", 1, 0, T_SPACE, 0},
	{NULL, 1, 0, 0, 0}
	};

	return (tokens);
}

void	add_lexer(t_list **lexer, char *input, int len, t_tokens type)
{
	char	*str;
	t_elem	*new_elem;
	t_list	*new_list;

	str = input;
	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return ;
	new_elem->str = ft_strdup(str);
	new_elem->str[len] = 0;
	new_elem->len = len;
	new_elem->type = type;
	new_elem->this_pipe = 0;
	new_elem->quotes = 0;
	new_list = ft_lstnew(new_elem);
	ft_lstadd_back(lexer, new_list);
}

t_elem	which_token(char *input)
{
	t_elem			*ex_tok;
	t_elem			inexistant;

	ex_tok = existing_token();
	inexistant.str = NULL;
	inexistant.type = 0;
	inexistant.len = 0;
	while (ex_tok && ex_tok->str)
	{
		if (!ft_strncmp(input, ex_tok->str, ex_tok->len))
			return (*ex_tok);
		++ex_tok;
	}
	return (inexistant);
}

void	print_lexer(t_list *lexer)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = lexer->next;
	while (cursor)
	{
		this = cursor->content;
		printf("[str : %s ;\ttype = %i;\tquotes = %d\tpipe = %d]\n",
			this->str, this->type, this->quotes, this->this_pipe);
		cursor = cursor->next;
	}
	printf("\n");
}

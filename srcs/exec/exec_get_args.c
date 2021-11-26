/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:06:40 by user42            #+#    #+#             */
/*   Updated: 2021/11/21 17:06:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	how_much_args_in_pipe(t_list *lexer, int pipe)
{
	t_list	*cursor;
	t_elem	*this;
	int		ret;

	ret = 0;
	cursor = while_pipe(pipe, lexer);
	this = cursor->content;
	while (cursor && this->this_pipe == pipe)
	{
		this = cursor->content;
		if (this->type == T_CMD)
			ret++;
		if (this->type == T_ARGS)
			ret++;
		if (this->type == T_OPT)
			ret++;
		cursor = cursor->next;
	}
	return (ret);
}

char	**args_into_str(t_list *lexer, int pipe)
{
	char	**args;
	t_list	*cursor;
	t_elem	*this;
	int		i;

	args = malloc(sizeof(char *) * (how_much_args_in_pipe(lexer, pipe) + 1));
	if (!args)
		return (NULL);
	cursor = while_pipe(pipe, lexer);
	this = cursor ->content;
	i = 0;
	while (cursor && this->this_pipe == pipe)
	{
		this = cursor->content;
		if (this->type == T_CMD || this->type == T_ARGS || this->type == T_OPT)
		{
			args[i] = ft_strdup(this->str);
			i++;
		}
		cursor = cursor->next;
	}
	args[i] = NULL;
	return (args);
}

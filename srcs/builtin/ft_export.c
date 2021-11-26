/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:41:50 by user42            #+#    #+#             */
/*   Updated: 2021/11/22 18:36:37 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_to_export(t_elem *this, char ***envp)
{
	int	keyindex;

	if (this->type == T_ARGS)
	{
		if (isvalid_export(this->str))
		{
			keyindex = check_key(*envp, this->str);
			if (keyindex >= 0)
			{
				if (have_equal(this->str))
					add_key_envp(envp, this->str, keyindex);
			}
			else
				add_envp(this->str, envp);
		}
		else
		{
			new_int_error("export", this->str, "not valid id", 1);
			return (1);
		}
	}
	return (0);
}

int	ft_export(t_list *lexer, int pipe, char ***envp)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = while_pipe(pipe, lexer);
	this = cursor->content;
	while (this->this_pipe == pipe && cursor)
	{
		this = cursor->content;
		if (add_to_export(this, envp))
			return (1);
		if (this->type == T_CMD && env_too_much_args(lexer, pipe) == 1)
			print_export(*envp, 1);
		cursor = cursor->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:13:05 by wluong            #+#    #+#             */
/*   Updated: 2021/10/18 00:16:03 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_str(t_list *lexer)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = lexer->next;
	while (cursor)
	{
		this = cursor->content;
		free(this->str);
		cursor = cursor->next;
	}
}
/*
void	free_env(t_var *env)
{
	t_var	*tmp;

	if (env)
	{
		while (env)
		{
			tmp = env->next;
			free(env->key);
			free(env->value);
			free(env);
			env = tmp;
		}
		free(env->key);
		free(env->value);
		env = NULL;
	}
}*/

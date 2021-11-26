/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 00:59:57 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 05:12:11 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_too_much_args(t_list *lexer, int pipe)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = while_pipe(pipe, lexer);
	this = cursor->content;
	while (this->this_pipe == pipe && cursor)
	{
		this = cursor->content;
		if (this->type == T_ARGS)
		{
			return (0);
		}
		cursor = cursor->next;
	}
	return (1);
}

int	ft_env(t_list *lexer, int pipe, char **envp)
{
	int		i;
	t_list	*cursor;
	t_elem	*this;

	i = 0;
	cursor = while_pipe(pipe, lexer);
	this = cursor->content;
	while (this->this_pipe == pipe && cursor)
	{
		this = cursor->content;
		if (!env_too_much_args(lexer, pipe))
			return (cmd_error("env", "too many aguments", 2));
		while (envp[i])
		{
			if (have_equal(envp[i]))
			{
				ft_putstr_fd(envp[i], 1);
				ft_putstr_fd("\n", 1);
			}
			i++;
		}
		cursor = cursor->next;
	}
	return (0);
}

char	**copy_envp(char **envs)
{
	char	**new;
	int		i;

	i = 0;
	while (envs[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (envs[++i])
		new[i] = ft_strdup(envs[i]);
	new[i] = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:52:01 by wluong            #+#    #+#             */
/*   Updated: 2021/11/24 16:47:07 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	is_var_in_env(char **split, int i, int len)
{
	int		j;
	char	**tmp;

	j = 0;
	while (g_ms.cpenv[j])
	{
		tmp = ft_split(g_ms.cpenv[j], '=');
		if (!ft_strncmp(split[i] + 1, tmp[0]
				, ft_strlen(tmp[0])))
		{
			free(split[i]);
			split[i] = ft_strdup(g_ms.cpenv[j] + len);
		}
		free_split(tmp);
		j++;
	}
}

void	is_var_not_in_env(char **split, int i, int len)
{
	char	*res;

	if (split[i][0] == '$' && len != 1)
	{
		if (split[i][1] == '?' && len == 2)
		{
			free(split[i]);
			res = ft_itoa(g_ms.ret);
			split[i] = ft_strdup(res);
			free(res);
		}
		else
		{
			free(split[i]);
			split[i] = ft_strdup("");
		}
	}
}

char	**replace_var(char *s)
{
	char	**split;
	int		i;
	int		len;

	i = 0;
	split = ft_new_split(s);
	while (split[i])
	{
		len = ft_strlen(split[i]);
		if (split[i][0] == '$' && len != 1)
		{
			is_var_in_env(split, i, len);
			is_var_not_in_env(split, i, len);
		}
		i++;
	}
	return (split);
}

void	replace_var_in_q(char **split_q)
{
	char	**split_env;
	int		i;
	char	*tmp;

	i = 0;
	while (split_q[i])
	{
		if (split_q[i][0] != '\'')
		{
			split_env = replace_var(split_q[i]);
			free(split_q[i]);
			tmp = rejoin_the_split(split_env);
			split_q[i] = ft_strtrim(tmp, "\"");
			free(tmp);
			free_split(split_env);
		}
		else
		{
			tmp = ft_strtrim(split_q[i], "'");
			free(split_q[i]);
			split_q[i] = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
}

void	replace_var_env(t_list *lexer)
{
	t_list	*cursor;
	t_elem	*this;
	char	**split_q;

	cursor = lexer->next;
	while (cursor)
	{
		this = cursor->content;
		split_q = split_quotes(this->str);
		replace_var_in_q(split_q);
		free(this->str);
		this->str = rejoin_the_split(split_q);
		free_split(split_q);
		cursor = cursor->next;
	}
}

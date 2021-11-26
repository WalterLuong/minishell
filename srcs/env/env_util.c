/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:13:12 by hawwar            #+#    #+#             */
/*   Updated: 2021/11/22 19:45:24 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_key_envp(char ***envp, char *cmd, int keyindex)
{
	free((*envp)[keyindex]);
	(*envp)[keyindex] = ft_strdup(cmd);
}

int	count_envp_row(char **envp)
{
	int	row;

	row = 0;
	while (envp[row])
		row++;
	return (row);
}

char	**sort_env(char **envp)
{
	int		i;
	int		j;
	char	**new;
	char	*temp;

	new = copy_envp(envp);
	i = 0;
	while (new[i])
	{
		j = i + 1;
		while (new[j])
		{
			if (ft_strncmp(new[i], new[j], ft_strlen(new[i])) > 0)
			{
				temp = new[i];
				new[i] = new[j];
				new[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (new);
}

int	is_valid_key(char *key)
{
	int	i;

	i = 0;
	if (!key)
		return (0);
	if (ft_strlen(key) == 0)
		return (0);
	while (key[i])
	{
		if (ft_isdigit(key[0]))
			return (0);
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	isvalid_export(char *line)
{
	char	**str_arg;
	char	*key;
	int		i;
	int		ret;

	i = 0;
	str_arg = ft_split(line, '=');
	key = str_arg[0];
	ret = is_valid_key(key);
	while (str_arg[i])
	{
		free(str_arg[i]);
		i++;
	}
	free(str_arg);
	return (ret);
}

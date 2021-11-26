/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:32:03 by wluong            #+#    #+#             */
/*   Updated: 2021/11/22 19:45:40 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	have_equal(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	print_quote(char *str, int fd)
{
	int	i;

	i = 0;
	if (have_equal(str))
	{
		while (str[i] != '=')
			i++;
		write(fd, str, ++i);
		write(fd, "\"", 1);
		write(fd, str + i, ft_strlen(str + i));
		write(fd, "\"", 1);
	}
	else
	{
		while (str[i])
			i++;
		write(fd, str, ++i);
	}
}

void	print_export(char **envp, int fd)
{
	int		i;
	char	**sorted;

	i = 0;
	sorted = sort_env(envp);
	while (sorted[i])
	{
		ft_putstr_fd("declare -x ", fd);
		print_quote(sorted[i], fd);
		ft_putchar_fd('\n', fd);
		free(sorted[i]);
		i++;
	}
	free(sorted);
}

int	check_key(char **envp, char *line)
{
	int	i;
	int	key;

	i = 0;
	key = 0;
	if (have_equal(line))
	{
		while (line[key] != '=')
			key++;
	}
	else
	{
		while (line[key])
			key++;
	}
	while (envp[i])
	{
		if (ft_strncmp(envp[i], line, key) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	add_envp(char *cmd, char ***envp)
{
	char	**new;
	int		row;
	int		i;

	i = 0;
	row = count_envp_row(*envp);
	new = (char **)malloc(sizeof(char *) * (row + 2));
	if (!new)
		return (0);
	while ((*envp)[i])
	{
		new[i] = ft_strdup((*envp)[i]);
		free((*envp)[i]);
		i++;
	}
	free(*envp);
	new[i] = ft_strdup(cmd);
	new[++i] = NULL;
	*envp = new;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:31:30 by user42            #+#    #+#             */
/*   Updated: 2021/11/25 15:25:45 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_env_var(char *var)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_ms.cpenv[++i])
	{
		tmp = ft_strjoinch(var, '=');
		if (ft_str_swith(g_ms.cpenv[i], tmp))
		{
			free(tmp);
			return (ft_strchr(g_ms.cpenv[i], '=') + 1);
		}
		free(tmp);
	}
	return (NULL);
}

int	print_error(char *path)
{
	DIR	*dir;
	int	fd;

	fd = open(path, O_WRONLY);
	dir = opendir(path);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(path, STDERR);
	if (ft_strchr(path, '/') == NULL)
		ft_putstr_fd(" command not found\n", STDERR);
	else if (fd != -1 && dir == NULL)
		ft_putstr_fd(" permission denied\n", STDERR);
	else if (fd == -1 && dir != NULL)
		ft_putstr_fd(" is a directory\n", STDERR);
	else if (fd == -1 && dir == NULL)
		ft_putstr_fd(" no such file or directory\n", STDERR);
	if (path == NULL && fd == -1 && dir == NULL)
		g_ms.ret = 127;
	else
		g_ms.ret = 127;
	if (dir)
		closedir(dir);
	close (fd);
	return (g_ms.ret);
}

int	ft_process(char *path, char **args)
{
	g_ms.ret = 0;
	g_ms.pid = fork();
	if (g_ms.pid == 0)
	{
		if (ft_strchr(path, '/') != NULL)
			g_ms.ret = execve(path, args, g_ms.cpenv);
		g_ms.ret = print_error(path);
		exit(g_ms.ret);
	}
	else
		waitpid(g_ms.pid, &g_ms.ret, 0);
	if (g_ms.sigint == 1 || g_ms.sigquit == 1)
		return (g_ms.ret);
	if (g_ms.ret == 32512 || g_ms.ret == 32256)
		return (g_ms.ret = g_ms.ret / 256);
	else
		return (!!g_ms.ret);
	return (g_ms.ret);
}

char	*check_bin(char *bin, char *cmd)
{
	DIR				*dir;
	struct dirent	*repo;
	char			*path;

	path = NULL;
	dir = opendir(bin);
	if (!dir)
		return (NULL);
	while (1)
	{
		repo = readdir(dir);
		if (!repo)
			break ;
		if (ft_strcmp(repo->d_name, cmd) == 0)
			path = strjoin_path(bin, repo->d_name);
	}
	closedir(dir);
	return (path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawwar <hawwar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:09:40 by user42            #+#    #+#             */
/*   Updated: 2021/11/23 17:59:05 by hawwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	exec_bin(char *path, char **args, char **bin)
{
	if (path != NULL)
	{
		g_ms.ret = ft_process(path, args);
		ft_free_str(bin);
		free(path);
		ft_free_str(args);
		return (g_ms.ret);
	}
	else
	{
		g_ms.ret = ft_process(args[0], args);
		ft_free_str(bin);
		free(path);
		ft_free_str(args);
		return (g_ms.ret);
	}
	ft_free_str(bin);
	free(path);
	ft_free_str(args);
	return (g_ms.ret);
}

int	exec_nonbuiltin(t_list *lexer, int pipe)
{
	char	**args;
	char	*path;
	char	**bin;
	int		i;

	args = args_into_str(lexer, pipe);
	g_ms.ret = 127;
	if (get_env_var("PATH") == NULL)
	{
		g_ms.ret = ft_process(args[0], args);
		ft_free_str(args);
		return (g_ms.ret);
	}
	bin = ft_split(get_env_var("PATH"), ':');
	if (!args[0] && !bin[0])
		return (-1);
	i = 1;
	path = check_bin(bin[0] + 5, args[0]);
	while (args[0] && bin[i] && path == NULL)
		path = check_bin(bin[i++], args[0]);
	exec_bin(path, args, bin);
	return (g_ms.ret);
}

int	is_buitlin(char *str)
{
	if (!ft_strcmp(str, "echo"))
		return (1);
	else if (!ft_strcmp(str, "pwd"))
		return (1);
	else if (!ft_strcmp(str, "env"))
		return (1);
	else if (!ft_strcmp(str, "unset"))
		return (1);
	else if (!ft_strcmp(str, "cd"))
		return (1);
	else if (!ft_strcmp(str, "export"))
		return (1);
	else if (!ft_strcmp(str, "exit"))
		return (1);
	return (0);
}

void	exec_buitlin(t_list *lexer, int pipe, char ***envp, char *str)
{
	if (!ft_strcmp(str, "echo"))
		g_ms.ret = ft_echo(lexer, pipe);
	else if (!ft_strcmp(str, "pwd"))
		g_ms.ret = ft_pwd(lexer, pipe);
	else if (!ft_strcmp(str, "env"))
		g_ms.ret = ft_env(lexer, pipe, *envp);
	else if (!ft_strcmp(str, "unset"))
		g_ms.ret = ft_unset(lexer, pipe, *envp);
	else if (!ft_strcmp(str, "cd"))
		g_ms.ret = ft_cd(lexer, pipe);
	else if (!ft_strcmp(str, "export"))
		g_ms.ret = ft_export(lexer, pipe, envp);
	else if (!ft_strcmp(str, "exit"))
	{
		g_ms.ret = ft_exit(lexer, pipe);
		if (g_ms.ret != -1)
			exit_succes(lexer);
		else
			g_ms.ret = 1;
	}
}

void	exec_cmd(t_list *lexer, int pipe, char ***envp)
{
	t_list	*cursor;
	t_elem	*this;

	cursor = while_pipe(pipe, lexer);
	this = cursor->content;
	while (cursor && this->this_pipe == pipe)
	{
		this = cursor->content;
		if (this->type == T_CMD)
		{
			if (is_buitlin(this->str))
			{
				exec_buitlin(lexer, pipe, envp, this->str);
				return ;
			}
			else
			{
				g_ms.ret = exec_nonbuiltin(lexer, pipe);
				return ;
			}
		}
		cursor = cursor->next;
	}
}

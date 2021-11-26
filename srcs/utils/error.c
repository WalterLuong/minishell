/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 23:53:02 by user42            #+#    #+#             */
/*   Updated: 2021/11/03 12:40:39 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	new_int_error(char *cmd, char *arg, char *msg, int fd)
{
	if (cmd)
	{
		ft_putstr_fd(cmd, fd);
		ft_putstr_fd(": ", fd);
	}
	if (arg)
	{
		ft_putstr_fd(arg, fd);
		ft_putstr_fd(": ", fd);
	}
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	cmd_error(char *cmd, char *msg, int fd)
{
	if (cmd)
	{
		ft_putstr_fd(cmd, fd);
		ft_putstr_fd(": ", fd);
	}
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	return (1);
}

bool	error_bool(char *cmd, char *arg, char *msg, int fd)
{
	if (cmd)
	{
		ft_putstr_fd(cmd, fd);
		ft_putstr_fd(": ", fd);
	}
	if (arg)
	{
		ft_putstr_fd(arg, fd);
		ft_putstr_fd(": ", fd);
	}
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

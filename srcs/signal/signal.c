/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:25:48 by user42            #+#    #+#             */
/*   Updated: 2021/11/25 14:43:27 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** ctrl-\ : (SIGQUIT) is received. regenerat the prompt
** ctrl-c : (SIGINT) is receveived. new line + new prompt + clear text
**          for child process no new prompt because is already done by parent
*/

void	parent_signal(int sig)
{
	if (sig == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 2);
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_ms.ret = 130;
	}
}

void	child_signal(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: (core dumped)\n", 2);
		g_ms.ret = 131;
		g_ms.sigquit = 1;
	}
	else if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		g_ms.ret = 130;
		g_ms.sigint = 1;
	}
}

void	get_signal(int sig)
{
	if (g_ms.pid)
		child_signal(sig);
	else
		parent_signal(sig);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:39:02 by wluong            #+#    #+#             */
/*   Updated: 2021/11/25 14:42:35 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_mshell	g_ms;

int	too_much_ac(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		ft_putstr_fd("Too much arguments.\n", 2);
		return (0);
	}
	return (1);
}

void	minishell(t_list *lexer)
{
	if (lexer->next)
	{
		if (count_pipes(lexer) + 1 > 1)
			ft_pipex(lexer);
		else
		{
			if (!redirection(lexer, 0, &g_ms.cpenv))
				exec_cmd(lexer, 0, &g_ms.cpenv);
		}
	}	
}

int	main(int ac, char **av, char **envp)
{
	t_list		*lexer;

	if (!too_much_ac(ac, av))
		return (0);
	g_ms.ret = 0;
	g_ms.cpenv = copy_envp(envp);
	while (1)
	{
		g_ms.pid = 0;
		g_ms.sigint = 0;
		g_ms.sigquit = 0;
		signal(SIGINT, get_signal);
		signal(SIGQUIT, get_signal);
		lexer = ft_lstnew(NULL);
		g_ms.buf = readline("\033[1;34mminishell ➜ \033[m");
		if (g_ms.buf == NULL)
			exit_succes(lexer);
		add_history(g_ms.buf);
		if (!parsing(g_ms.buf, lexer))
			g_ms.ret = 127;
		else
			minishell(lexer);
		free_all(lexer);
	}
	return (g_ms.ret);
}

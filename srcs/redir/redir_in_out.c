/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:24:57 by wluong            #+#    #+#             */
/*   Updated: 2021/11/19 20:27:16 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	redir_in_out(t_fds *fds, int pipe, t_list *lexer, char ***envp)
{
	int	f_stdin;
	int	f_stdout;
	int	fd1;
	int	fd2;

	f_stdin = dup(STDIN_FILENO);
	f_stdout = dup(STDOUT_FILENO);
	fd1 = open(fds->last_in, O_RDONLY, 0644);
	if (fd1 == -1)
	{
		printf("bash : %s : File not found.\n", fds->last_in);
		return (-1);
	}
	fd2 = open(fds->last_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	exec_cmd(lexer, pipe, envp);
	dup2(f_stdin, STDIN_FILENO);
	dup2(f_stdout, STDOUT_FILENO);
	close(fd1);
	close(fd2);
	return (0);
}

int	redir_in_appen(t_fds *fds, int pipe, t_list *lexer, char ***envp)
{
	int	f_stdin;
	int	f_stdout;
	int	fd1;
	int	fd2;

	f_stdin = dup(STDIN_FILENO);
	f_stdout = dup(STDOUT_FILENO);
	fd1 = open(fds->last_in, O_RDONLY, 0644);
	if (fd1 == -1)
	{
		printf("bash : %s : File not found.\n", fds->last_in);
		return (-1);
	}
	fd2 = open(fds->last_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	exec_cmd(lexer, pipe, envp);
	dup2(f_stdin, STDIN_FILENO);
	dup2(f_stdout, STDOUT_FILENO);
	close(fd1);
	close(fd2);
	return (0);
}

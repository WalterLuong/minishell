/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:23:38 by wluong            #+#    #+#             */
/*   Updated: 2021/11/19 20:27:07 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redir_heredoc_out(t_fds *fds, int pipe, t_list *lexer, char ***envp)
{
	int		f_stdin;
	int		f_stdout;
	int		fd1;
	int		fd2;

	f_stdin = dup(STDIN_FILENO);
	f_stdout = dup(STDOUT_FILENO);
	heredoc_while(fds->last_in);
	fd1 = open("/tmp/1", O_RDONLY, 0644);
	fd2 = open(fds->last_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	exec_cmd(lexer, pipe, envp);
	dup2(f_stdin, STDIN_FILENO);
	dup2(f_stdout, STDOUT_FILENO);
	unlink("/tmp/1");
}

void	redir_heredoc_appen(t_fds *fds, int pipe, t_list *lexer, char ***envp)
{
	int		f_stdin;
	int		f_stdout;
	int		fd1;
	int		fd2;

	f_stdin = dup(STDIN_FILENO);
	f_stdout = dup(STDOUT_FILENO);
	heredoc_while(fds->last_in);
	fd1 = open("/tmp/1", O_RDONLY, 0644);
	fd2 = open(fds->last_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	exec_cmd(lexer, pipe, envp);
	dup2(f_stdin, STDIN_FILENO);
	dup2(f_stdout, STDOUT_FILENO);
	unlink("/tmp/1");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:56:40 by wluong            #+#    #+#             */
/*   Updated: 2021/11/19 20:11:34 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_fd_in(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY, 0644);
	if (fd == -1)
	{
		printf("bash : %s : File not found.\n", name);
		return (-1);
	}
	close(fd);
	return (0);
}

int	redir_in(char *name, int pipe, t_list *lexer, char ***envp)
{
	int		f_stdin;
	int		fd;

	f_stdin = dup(STDIN_FILENO);
	fd = open(name, O_RDONLY, 0644);
	if (fd == -1)
	{
		printf("bash : %s : File not found.\n", name);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	exec_cmd(lexer, pipe, envp);
	dup2(f_stdin, STDIN_FILENO);
	close(fd);
	return (0);
}

void	skip_heredoc(char *delim)
{
	int		f_stdin;
	char	buf[4096];
	int		output;
	char	*delim_line;

	f_stdin = dup (STDIN_FILENO);
	delim_line = ft_strjoin(delim, "\n");
	write (0, "> ", 2);
	output = read(0, buf, 4095);
	while (output > 0)
	{
		buf[output] = '\0';
		if (!ft_strcmp(buf, delim_line))
			break ;
		write(0, "> ", 2);
		output = read(0, buf, 4095);
	}
	dup2(f_stdin, STDIN_FILENO);
	free(delim_line);
}

void	heredoc_while(char *delim)
{
	char	*delim_line;
	int		fd;
	int		output;
	char	buff[4095];

	write(0, "> ", 2);
	delim_line = ft_strjoin(delim, "\n");
	fd = open("/tmp/1", O_RDWR | O_CREAT | O_TRUNC, 0644);
	output = read(0, buff, 4095);
	while (output > 0)
	{
		buff[output] = '\0';
		if (!ft_strcmp(buff, delim_line))
			break ;
		ft_putstr_fd(buff, fd);
		write(0, "> ", 2);
		output = read(0, buff, 4095);
	}
	free(delim_line);
	close (fd);
}

void	redir_heredoc(char *delim, int pipe, t_list *lexer, char ***envp)
{
	int		f_stdin;
	int		fd;

	f_stdin = dup(STDIN_FILENO);
	heredoc_while(delim);
	fd = open("/tmp/1", O_RDONLY, 0644);
	dup2(fd, STDIN_FILENO);
	exec_cmd(lexer, pipe, envp);
	dup2 (f_stdin, STDIN_FILENO);
	close(fd);
	unlink("/tmp/1");
}

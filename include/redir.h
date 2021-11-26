/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:18:11 by wluong            #+#    #+#             */
/*   Updated: 2021/11/25 14:44:55 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "minishell.h"

typedef struct s_fds
{
	char	*last_out;
	char	*last_in;
	int		which_redir;
	int		in;
	int		out;
}				t_fds;

/* REDIR UTILS */
void	init_fds(t_fds *fds);
void	find_the_last(t_list *lexer, int pipe, t_fds *fds);

/* REDIR IN AND HEREDOC */
int		check_fd_in(char *name);
int		redir_in(char *name, int pipe, t_list *lexer, char ***envp);
void	skip_heredoc(char *delim);
void	redir_heredoc(char *delim, int pipe, t_list *lexer, char ***envp);
void	heredoc_while(char *delim);

/* REDIR OUT */
void	create_file_out(char *name);
void	redir_out(char *name, int pipe, t_list *lexer, char ***envp);
void	create_file_appen(char *name);
void	redir_appen(char *name, int pipe, t_list *lexer, char ***envp);

/* MIXED REDIR */
void	redir_heredoc_appen(t_fds *fds, int pipe, t_list *lexer, char ***envp);
void	redir_heredoc_out(t_fds *fds, int pipe, t_list *lexer, char ***envp);
int		redir_in_out(t_fds *fds, int pipe, t_list *lexer, char ***envp);
int		redir_in_appen(t_fds *fds, int pipe, t_list *lexer, char ***envp);

/* REDIRECTION */
int		redirection(t_list *lexer, int pipe, char ***envp);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:53:55 by wluong            #+#    #+#             */
/*   Updated: 2021/11/25 15:04:34 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"
# include "parsing.h"

/* COUNT */
int		count_pipes(t_list *lexer);
int		check_args(t_list *lexer, int pipe);
int		count_args(t_list *lexer, int pipe);

/* ERROR */
int		new_int_error(char *cmd, char *arg, char *msg, int fd);
int		cmd_error(char *cmd, char *msg, int fd);
bool	error_bool(char *cmd, char *arg, char *msg, int fd);
void	free_array(char **array);

/* FREE */
void	free_split(char **s);
void	free_lexer(t_list *lexer);
void	free_all(t_list *lexer);

/* STRING UTILS */
void	init_vec(t_vec *cpt);
char	*rejoin_the_split(char **s);

/* WHILE PIPE */
t_list	*while_pipe(int pipe, t_list *lexer);

#endif
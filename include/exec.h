/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawwar <hawwar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:45:22 by hawwar            #+#    #+#             */
/*   Updated: 2021/11/23 18:32:09 by hawwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

/* Get arguments */

int		how_much_args_in_pipe(t_list *lexer, int pipe);
char	**args_into_str(t_list *lexer, int pipe);

/* Utils fonctions */

int		ft_str_swith(char *s1, char *s2);
char	*ft_strjoinch(char const *s1, char c);
void	ft_free_str(char **arr);
char	*ft_strnew(size_t size);
char	*strjoin_path(char const *s1, char const *s2);
char	*get_env_var(char *var);
int		print_error(char *path);
int		ft_process(char *path, char **args);
char	*check_bin(char *bin, char *cmd);

/* Exec cmd & builtin */

int		exec_nonbuiltin(t_list *lexer, int pipe);
int		is_buitlin(char *str);
void	exec_buitlin(t_list *lexer, int pipe, char ***envp, char *str);
void	exec_cmd(t_list *lexer, int pipe, char ***envp);

#endif
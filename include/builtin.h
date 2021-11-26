/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 00:05:19 by wluong            #+#    #+#             */
/*   Updated: 2021/10/20 22:47:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/* ECHO */
int		ft_echo(t_list *lexer, int pipe);

/* EXIT */
int		ft_exit(t_list *lexer, int pipe);
void	exit_succes(t_list *lexer);
void	free_str(t_list *lexer);
void	free_env(t_var *env);

/* ENV */
int		ft_env(t_list *lexer, int pipe, char **envp);
int		env_too_much_args(t_list *lexer, int pipe);
int		declare_env(void);
int		crt_updt_env(char *arg);
char	**copy_envp(char **envs);
int		add_envp(char *cmd, char ***envp);
int		check_key(char **envp, char *line);

/* PWD */
int		ft_pwd(t_list *lexer, int pipe);

/* CD */
int		ft_cd(t_list *lexer, int pipe);
int		change_dir_var(t_var *var, char *var_name, int fd_err);

/* EXPORT */
int		ft_export(t_list *lexer, int pipe, char ***envp);

/* UNSET */
int		ft_unset(t_list *lexer, int pipe, char **envp);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:58:41 by user42            #+#    #+#             */
/*   Updated: 2021/11/25 15:14:52 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

typedef struct s_var
{
	struct stat		*buf;
	char			*env_path;
	char			**path;
	int				flag;
}					t_var;

extern int	g_exit_status;

int		have_equal(char *line);
void	add_key_envp(char ***envp, char *cmd, int keyindex);
int		count_envp_row(char **envp);
char	**sort_env(char **envp);
int		is_valid_key(char *key);
int		isvalid_export(char *line);
void	free_split(char **s);
char	**replace_var(char *s);
void	print_quote(char *str, int fd);
void	print_export(char **envp, int fd);
int		check_key(char **envp, char *line);
int		add_envp(char *cmd, char ***envp);

/*	SIGNAUX	*/
void	get_signal(int sig);
void	parent_signal(int sig);
void	child_signal(int sig);

#endif
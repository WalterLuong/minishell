/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 00:13:35 by wluong            #+#    #+#             */
/*   Updated: 2021/11/25 15:03:16 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "utils.h"

typedef struct s_vec
{
	int	i;
	int	j;
	int	k;
}				t_vec;

void	free_str(t_list *lexer);
int		count_pipes(t_list *lexer);
void	which_pipe(t_list *lexer);
void	get_new_lexer(t_list *lexer);
char	*rejoin_the_split(char **s);

/* ENV VAR */
void	replace_var_env(t_list *lexer);

/* ERRORS */
int		check_error(t_list *lexer);
int		syntax_error(t_list *lexer);

/* QUOTES */
char	**split_quotes(char *s);
void	which_quotes(t_list *lexer);

/* PARSING */
void	is_fd(t_list *lexer);
void	is_cmd(t_list *lexer);
void	is_option(t_list *lexer);
int		not_interpret(t_list *lexer);
int		parsing(char *buf, t_list *lexer);

#endif
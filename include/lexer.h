/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:26:19 by wluong            #+#    #+#             */
/*   Updated: 2021/11/23 16:39:06 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum s_tokens
{
	T_DQ,
	T_SQ,
	T_SEMI,
	T_SPACE,
	T_REDIR1,
	T_REDIR2,
	T_REDIR3,
	T_REDIR4,
	T_REDIR5,
	T_ARGS,
	T_CMD,
	T_FD,
	T_OPT,
	T_DELIMITER,
	T_EQUAL,
	T_PIPE,
	T_OP_BRA,
	T_CL_BRA,
	T_OP_PAR,
	T_CL_PAR,
	T_ENV,
	T_BSLASH,
	T_AND,
	T_RES,
	T_NULL
}					t_tokens;

typedef struct s_elem
{
	char			*str;
	int				len;
	int				this_pipe;
	t_tokens		type;
	int				quotes;
}					t_elem;

void	add_lexer(t_list **lexer, char *input, int len, t_tokens type);
t_elem	which_token(char *input);
int		fill_lexer(char *input, t_list **lexer);
void	print_lexer(t_list *lexer);
t_elem	*existing_token(void);

#endif
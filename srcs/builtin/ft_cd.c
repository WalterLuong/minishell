/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:12:38 by user42            #+#    #+#             */
/*   Updated: 2021/11/24 17:12:47 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	mv_home(char **p_buffer)
{
	chdir(getenv("HOME"));
	if (p_buffer != 0)
		free(*p_buffer);
	return (0);
}

void	make_path(t_list *lexer)
{
	char	*tmp;
	t_list	*cursor;
	t_elem	*this;

	tmp = NULL;
	cursor = lexer->next;
	while (cursor)
	{
		this = cursor->content;
		if (this->type == T_ARGS)
		{
			tmp = this->str;
			this->str = ft_strjoin(getenv("HOME"), &this->str[1]);
		}
		free(tmp);
		cursor = cursor->next;
	}
}

int	tilde(t_elem *this, t_list *lexer, char *p_buffer)
{
	if (this->str[0] == '~')
	{
		if (this->str[1] == '/')
			make_path(lexer);
		else if (this->str[1] == 0)
			return (mv_home(&p_buffer));
	}
	return (1);
}

int	wrong_path(t_elem *this, char *p_buffer)
{
	if (chdir(this->str) == -1)
	{
		chdir(p_buffer);
		free(p_buffer);
		new_int_error("cd", this->str, strerror(errno), 2);
		return (1);
	}
	return (0);
}

int	ft_cd(t_list *lexer, int pipe)
{
	char	*p_buffer;
	t_list	*cursor;
	t_elem	*this;

	cursor = while_pipe(pipe, lexer);
	this = cursor->content;
	while (this->this_pipe == pipe && cursor)
	{
		this = cursor->content;
		if (this->type == T_CMD && env_too_much_args(lexer, pipe) == 1)
			return (mv_home(0));
		if (check_args(lexer, pipe))
			return (1);
		p_buffer = getcwd(0, 0);
		if (this->type == T_ARGS)
		{
			if (!tilde(this, lexer, p_buffer))
				return (0);
			if (wrong_path(this, p_buffer))
				return (1);
		}
		free(p_buffer);
		cursor = cursor->next;
	}
	return (0);
}

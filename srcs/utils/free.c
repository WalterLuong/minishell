/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:54:30 by user42            #+#    #+#             */
/*   Updated: 2021/11/22 17:53:17 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_split(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

void	free_lexer(t_list *lexer)
{
	free_str(lexer);
	ft_lstclear(&lexer, free);
}

void	free_all(t_list *lexer)
{
	free_lexer(lexer),
	free(g_ms.buf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:33:54 by wluong            #+#    #+#             */
/*   Updated: 2021/11/25 14:46:35 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "minishell.h"

void	close_write_read(int *pipes);
void	parent(int fd_in, t_list *lexer);
void	children(t_list *lexer, int fd_in);
void	ft_pipex(t_list *lexer);

#endif
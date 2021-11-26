/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:47:52 by hawwar            #+#    #+#             */
/*   Updated: 2021/11/25 15:14:34 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

# include "../libft/libft.h"
# include "lexer.h"
# include "utils.h"
# include "parsing.h"
# include "redir.h"
# include "env.h"
# include "builtin.h"
# include "exec.h"
# include "pipe.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_mshell
{
	int			ret;
	char		*buf;
	char		**cpenv;
	int			sigint;
	int			sigquit;
	pid_t		pid;
}				t_mshell;

extern t_mshell	g_ms;

#endif
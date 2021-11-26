/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:51:05 by wluong            #+#    #+#             */
/*   Updated: 2021/11/25 15:13:05 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_vec(t_vec *cpt)
{
	cpt->i = 0;
	cpt->j = 0;
	cpt->k = 0;
}

char	*rejoin_the_split(char **s)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strdup("");
	while (s[i])
	{
		tmp = ft_strjoin(str, s[i]);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (str);
}

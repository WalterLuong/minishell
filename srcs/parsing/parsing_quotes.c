/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:50:03 by wluong            #+#    #+#             */
/*   Updated: 2021/11/23 16:34:49 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_words_process(char *s, int i, int c)
{
	int	j;

	j = i + 1;
	while (s[j] != c && s[j])
		j++;
	if (s[j])
		j++;
	return (j);
}

int	get_words(char *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != '"' && s[i] != '\'')
		{
			while (s[i] && (s[i] != '\'' && s[i] != '"'))
				i++;
			words++;
		}
		else if (s[i] == '"')
		{
			i = get_words_process(s, i, '"');
			words++;
		}
		else if (s[i] == '\'')
		{
			i = get_words_process(s, i, '\'');
			words++;
		}
	}
	return (words);
}

void	get_i_and_j(char *s, t_vec *cpt, int c)
{
	cpt->j = cpt->i;
	cpt->i = get_words_process(s, cpt->i, c);
}

void	not_in_quotes(char *s, t_vec *cpt)
{
	cpt->j = cpt->i;
	while (s[cpt->i] && (s[cpt->i] != '\'' && s[cpt->i] != '"'))
		cpt->i++;
}

char	**split_quotes(char *s)
{
	char	**str;
	t_vec	cpt;

	str = malloc(sizeof(char *) * (get_words(s) + 1));
	init_vec(&cpt);
	while (s[cpt.i])
	{
		if (s[cpt.i] != '"' && s[cpt.i] != '\'')
		{
			not_in_quotes(s, &cpt);
			str[cpt.k++] = ft_strdupn(s + cpt.j, cpt.i - cpt.j);
		}
		else if (s[cpt.i] == '"')
		{
			get_i_and_j(s, &cpt, '"');
			str[cpt.k++] = ft_strdupn(s + cpt.j, cpt.i - cpt.j);
		}
		else if (s[cpt.i] == '\'')
		{
			get_i_and_j(s, &cpt, '\'');
			str[cpt.k++] = ft_strdupn(s + cpt.j, cpt.i - cpt.j);
		}
	}
	str[cpt.k] = NULL;
	return (str);
}

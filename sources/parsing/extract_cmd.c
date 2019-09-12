/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:18:15 by mbonati           #+#    #+#             */
/*   Updated: 2019/09/12 12:18:16 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static char	*extract_quote_word(char *cmd_line, int *i)
{
	size_t	i_word;
	char	quote_size;
	char	*word;

	quote = cmd_line[*i];
	quote_size = quote_len(&cmd_line[*i]);
	if (!(word = malloc(sizeof(char) * (quote_size + 1))))
		return (NULL);
	word[quote_size] = '\0';
	i_word = 0;
	while (i_word < quote_size)
	{
		if (cmd_line[i] == '\\')
			(*i)++;
		word[i_word] = cmd_line[*i];
		i_word++;
		(*i)++;
	}
	(*i++);
	return (word);
}

static char	*extract_word(char *cmd_line, int *i)
{
	char		*word;
	size_t		i_word;

	i_word = 0;
	if (!(word = (char *)malloc(sizeof(char) * (word_len(&cmd_line[*i]) + 1))))
		return (0);
	while (cmd_line[*i] && !(ft_isspace(cmd_line[*i])) && !(cmd_line[*i] == '\'') && !(cmd_line[*i] == '"'))
	{
		if (cmd_line[i] == '\\')
			(*i)++;
		word[i_word] = cmd_line[*i];
		(*i)++;
		i_word++;
	}
	word[i_word] = '\0';
	return (word);
}

char		*extract_cmd(char *cmd_line)
{
	size_t	i;
	char	*tmp_quote;
	char	quote;
	char	*res;

	tmp_quote = NULL;
	while (ft_isspace(cmd_line[i]))
		i++;
	if (cmd_line[i] == '\'' || cmd_line[i] == '"') //si on tombe sur une quote
	{
		quote = cmd_line[i];
		if (!(tmp_quote = extract_quote_word(cmd_line, &i)))
			return (NULL);
		i++;
		if (ft_isspace(cmd_line[i]) || !(cmd_line[i]))
			return (tmp_quote);
		return (ft_strjoinfree(tmp_quote, extract_cmd(&cmd_line[i]), 1));
	}

}

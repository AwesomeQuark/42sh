/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:46:09 by mbonati           #+#    #+#             */
/*   Updated: 2019/08/30 15:46:11 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

size_t	quote_len(char *cmd_line)
{
	char	quote;
	size_t	i;

	quote = cmd_line[0];
	if (cmd_line[1] == quote)
		return (0);
	i = 1;
	while (cmd_line[i] && cmd_line[i] != quote)
		i++;
	return (i - 1);
}

char	*extract_quote_word(char *cmd_line, int *i)
{
	size_t	i_res;
	size_t	size;
	char	quote_size;
	char	*res;

	quote = cmd_line[*i];
	quote_size = quote_len(cmd_line[*i]);
	if (!(res = malloc(sizeof(char) * (quote_size + 1))))
		return (NULL);
	res[quote_size] = '\0';
	i_res = 0;
	while (i_res < quote_size)
	{
		res[i_res] = cmd_line[*i];
		i_res++;
		*i++;
	}
	return (res);
}

size_t	word_size(char *cmd_line)
{
	size_t	i;

	i = 0;
	while ()
}

char	*extract_word(char *cmd_line)
{
	size_t	i;
	char	*tmp_quote;

	tmp_quote = NULL;
	if (cmd_line[i] == '\'' || cmd_line[i] == '"')
		if (!(tmp_quote = extract_quote_word(cmd_line, &i)))
			return (NULL);
}

t_token *cmd_handler(char *cmd_line)
{
	t_token	**all_words;

}

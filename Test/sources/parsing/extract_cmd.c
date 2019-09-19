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

#include "21sh.h"

static char	*extract_quote_word(char *line, int *i)
{
	//printf("extract_quote_word\n");

	size_t	i_word;
	size_t	quote_size;
	char	*word;

	quote_size = quote_len(&line[*i]);
	if (!(word = malloc(sizeof(char) * (quote_size + 1))))
		return (NULL);
	word[quote_size] = '\0';
	i_word = 0;
	(*i)++;
	while (i_word < quote_size)
	{
		if (line[*i] == '\\')
		{
			*i += 2;
			word[i_word] = line[*i];
		}
		else
		{
			word[i_word] = line[*i];
			i_word++;
			(*i)++;
		}
	}
	(*i)++;
	return (word);
}

static char	*extract_word(char *line, int *i)
{
	//printf("extract_word\n");
	char		*word;
	size_t		i_word;
	size_t		word_size;

	i_word = 0;
	word_size = word_len(&line[*i]);
	if (!(word = (char *)malloc(sizeof(char) * (word_size + 1))))
		return (0);
	while (line[*i] && !ft_isspace(line[*i]) && !is_quote(line[*i]) &&\
		!(is_operator(line[*i])))
	{
		if (line[*i] == '\\')
			(*i)++;
		word[i_word] = line[*i];
		(*i)++;
		i_word++;

	}
	word[i_word] = '\0';
	return (word);
}

char	*handle_quote(char *line, int *i)
{
	//printf("handle_quote\n");
	char *tmp_quote;

	tmp_quote = NULL;
	if (!(tmp_quote = extract_quote_word(line, i)))
		return (NULL);
	if (!(line[*i]) || ft_isspace(line[*i]) || is_operator(line[*i]))
		return (tmp_quote);
	return (ft_strjoinfree(tmp_quote, extract_cmd(line, i), 2));
}

char	*handle_word(char *line, int *i)
{
	//printf("handle_word\n");

	char *tmp_word;

	tmp_word = NULL;
	if (!(tmp_word = extract_word(line, i)))
		return (NULL);
	if (line[*i] == '\'' || line[*i] == '"')
		return (ft_strjoinfree(tmp_word, extract_cmd(line, i), 2));
	return (tmp_word);
}

char		*extract_cmd(char *line, int *i)
{
	//printf("extract_cmd %s\n", &line[*i]);

	while (ft_isspace(line[*i]))
		(*i)++;
	if (!line[*i])
		return (NULL);
	if (line[*i] == '\'' || line[*i] == '"')
		return (handle_quote(line, i));
	return (handle_word(line, i));
}

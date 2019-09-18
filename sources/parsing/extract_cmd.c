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

static char	*extract_quote_word(char *cmd_line, int *i)
{

	size_t	i_word;
	size_t	quote_size;
	char	*word;

	quote_size = quote_len(&cmd_line[*i]);
	if (!(word = malloc(sizeof(char) * (quote_size + 1))))
		return (NULL);
	word[quote_size] = '\0';
	i_word = 0;
	(*i)++;
	while (i_word < quote_size)
	{
		if (cmd_line[*i] == '\\')
		{
			*i += 2;
			word[i_word] = cmd_line[*i];
		}
		else
		{
			word[i_word] = cmd_line[*i];
			i_word++;
			(*i)++;
		}
	}
	(*i)++;
	return (word);
}

static char	*extract_word(char *cmd_line, int *i)
{
	char		*word;
	size_t		i_word;
	size_t		size_word;

	i_word = 0;
	size_word = word_len(&cmd_line[*i]) + 1;
	if (!(word = (char *)malloc(sizeof(char) * (size_word + 2))))
		return (NULL);
	word[i_word++] = '"';
	while (i_word < size_word)
	{
		if (cmd_line[*i] == '\\')
			(*i)++;
		word[i_word] = cmd_line[*i];
		(*i)++;
		i_word++;
	}
	word[i_word++] = '"';
	word[i_word] = '\0';
	return (word);
}

static char	*extract_operator(char *cmd_line, int *i)
{
	char	c_op;
	size_t	operator_size;
	char	*operator;
	size_t	y;

	c_op = cmd_line[*i];
	operator_size = 1;
	operator = NULL;
	if (cmd_line[*i + 1] == c_op || cmd_line[*i + 1] == '&')
		operator_size = 2;
	if (!(operator = malloc(sizeof(char) * (operator_size + 1))))
		return (error_malloc("extract_operator"));
	operator[operator_size] = '\0';
	y = 0;
	while (y < operator_size)
	{
		operator[y] = cmd_line[*i];
		(*i)++;
		y++;
	}
	return (operator);
}

static char	*handle_word(char *cmd_line, int *i)
{
	char *tmp_word;

	tmp_word = NULL;
	if (!(tmp_word = extract_word(cmd_line, i)))
		return (NULL);
	if (cmd_line[*i] == '\'' || cmd_line[*i] == '"')
		return (ft_strjoinfree(tmp_word, extract_cmd(cmd_line, i), 1));
	return (tmp_word);
}

static char	*handle_quote(char *cmd_line, int *i)
{
	char *tmp_quote;

	tmp_quote = NULL;
	if (!(tmp_quote = extract_quote_word(cmd_line, i)))
		return (NULL);
	if (!(cmd_line[*i]) || ft_isspace(cmd_line[*i]))
		return (tmp_quote);
	return (ft_strjoinfree(tmp_quote, extract_cmd(cmd_line, i), 1));
}

char		*extract_cmd(char *cmd_line, int *i)
{
	while (ft_isspace(cmd_line[*i]))
		(*i)++;
	if (is_operator(cmd_line[*i]))
		return (extract_operator(cmd_line, i));
	if (cmd_line[*i] == '\'' || cmd_line[*i] == '"') //si on tombe sur une quote
		return (handle_quote(cmd_line, i));
	return (handle_word(cmd_line, i));
}

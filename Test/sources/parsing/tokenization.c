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

#include "21sh.h"

static int		operator_handler(char *line, int *i, t_token *new)
{
	char	*tmp_value;

	if (line[*i] == ';')
	{
		if (!(tmp_value = extract_separator(i)))
			return (0);
		new->value = tmp_value;
		new->type = 2;
	}
	else if (is_operator(line[*i]))
	{
		if (!(tmp_value = extract_operator(line, i)))
			return (0);
		new->value = tmp_value;
		new->type = 0;
	}
	return (1);
}

static int		cmd_handler(char *line, int *i, t_token *new)
{
	char	*tmp_value;

	if (!(tmp_value = extract_cmd(line, i)))
		return (0);
	new->value = tmp_value;
	new->type = 1;
	return (1);
}

static int	check_line(char *line, int *i, t_token *new)
{
	while (ft_isspace(line[*i]))
		(*i)++;
	if (line[*i] != ';' && !is_operator(line[*i]))
	{
		if (!(cmd_handler(line, i, new)))
			return (0);
	}
	else if (!(operator_handler(line, i, new)))
		return (0);
	return (1);
}

int		tokenization(char *line, t_token **all_words)
{
	t_token	*new_word;
	int		res_extract;
	int		i;

	i = 0;
	new_word = NULL;
	while (line[i])
	{
		if (!(new_word = token_init()))
			return (0);
		if (!(res_extract = check_line(line, &i, new_word)))
		{
			delete_token(new_word);
			return (0);
		}
		add_token(all_words, new_word);
	}
	return (1);
}

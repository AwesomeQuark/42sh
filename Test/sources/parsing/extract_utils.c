/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:46:09 by mbonati           #+#    #+#             */
/*   Updated: 2019/08/30 15:46:11 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int is_operator(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == '&' || c == ';')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

size_t	quote_len(char *line)
{
	printf("quote_len\n");
	char	quote;
	size_t	i;
	size_t	res;

	quote = line[0];
	i = 1;
	res = 1;
	while (line[i] && line[i] != quote)
	{
		if (line[i] == '\\')
			i++;
		i++;
		res++;
	}
	return (res - 1);
}

size_t	word_len(char *line)
{
	printf("word_len\n");
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (line[i] && !is_operator(line[i]) && !(ft_isspace(line[i]))\
		&& !(is_quote(line[i])))
	{
		if (line[i] == '\\')
			i++;
		i++;
		res++;
	}
	return (res);
}

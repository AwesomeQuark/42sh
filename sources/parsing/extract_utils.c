/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:05:46 by mbonati           #+#    #+#             */
/*   Updated: 2019/09/12 13:05:47 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

size_t	quote_len(char *cmd_line)
{
	char	quote;
	size_t	i;
	size_t	res;

	quote = cmd_line[0];
	i = 1;
	res = 1;
	while (cmd_line[i] && cmd_line[i] != quote)
	{
		if (cmd_line[i] == '\\')
			i++;
		i++;
		res++;
	}
	return (res - 1);
}

size_t	word_len(char *cmd_line)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (cmd_line[i] && !(ft_isspace(cmd_line[i])) && (cmd_line[i] != '\'' || cmd_line[i] != '"'))
	{
		if (cmd_line[i] == '\\')
			i++;
		i++;
		res++;
	}
	return (res);
}

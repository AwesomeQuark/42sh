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

char	*extract_quote_word(char *cmd_line)
{
	size_t	i_cmd;
	size_t	i_res;
	size_t	size;
	char	quote_size;
	char	*res;

	quote = cmd_line[0];
	quote_size = quote_len(cmd_line);
	if (!(res = malloc(sizeof(char) * (quote_size + 1))))
		return (NULL);
	res[quote_size] = '\0';
	i_cmd = 1;
	i_res = 0;
	while (i_res < quote_size)
	{
		res[i_res] = cmd_line[i_cmd];
		i_res++;
	}
	return (res);
}

char	*extract_word(char *cmd_line)
{

}


t_token *cmd_handler(char *cmd_line)
{
	t_token	**all_words;

}

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

#include "../../includes/21sh.h"

int		cmd_handler(char *cmd_line, t_token **all_words)
{
	//printf("cmd_handler\n");
	t_token	*new_word;
	char	*res_cmd;
	int		i;

	i = 0;
	new_word = NULL;
	while (cmd_line[i])
	{
		if (!(res_cmd = extract_cmd(cmd_line, &i)))
			return (0);
		if (res_cmd)
		{
			new_word = token_init(res_cmd);
			add_token(all_words, new_word);
		}
	}
	return (1);
}

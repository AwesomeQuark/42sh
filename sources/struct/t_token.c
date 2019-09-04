/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:01:40 by mbonati           #+#    #+#             */
/*   Updated: 2019/09/04 15:01:41 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		token_type(char *item)
{
	t_type	token_type;

	if (strcmp(item, ">") == 0 || strcmp(item, ">>") == 0 ||\
		strcmp(item, "<") == 0 || strcmp(item, "<<") == 0 ||\
		strcmp(item, ">&") == 0 || strcmp(item, "<&") == 0 ||\
		strcmp(item, "|") == 0 || strcmp(item, "||") == 0 ||\
		strcmp(item, "&&") == 0)
		return (OPERATOR);
	return (WORD);
}

t_token	*token_init(char *item)
{
	t_token	new;

	new.next = NULL;
	new.value = item;
	new.type = token_type(item);
}

void	add_token(t_token **all, t_token *new)
{

}

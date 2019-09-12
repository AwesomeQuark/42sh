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

#include "../../includes/21sh.h"

static int		token_type(char *item)
{
	//printf("token_type\n");

	if (strcmp(item, ">") == 0 || strcmp(item, ">>") == 0 ||\
		strcmp(item, "<") == 0 || strcmp(item, "<<") == 0 ||\
		strcmp(item, ">&") == 0 || strcmp(item, "<&") == 0 ||\
		strcmp(item, "|") == 0 || strcmp(item, "||") == 0 ||\
		strcmp(item, "&&") == 0)
		return (OPERATOR);
	return (WORD);
}

t_token			*token_init(char *item)
{
	//printf("token_init\n");

	t_token	*new;

	if (!(new = malloc(sizeof(t_token))))
		return (NULL);
	new->next = NULL;
	new->value = item;
	new->type = token_type(item);
	return (new);
}

void			add_token(t_token **all, t_token *new)
{
	//printf("add_token\n");

	while (all && *all != NULL)
		all = &(*all)->next;
	new->next = (*all);
	*all = new;
}

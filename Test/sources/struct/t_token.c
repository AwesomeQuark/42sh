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

#include "21sh.h"

/*static int		token_type(char *item)
{
	printf("token_type\n");

	if (strcmp(item, ">") == 0 || strcmp(item, ">>") == 0 ||\
		strcmp(item, "<") == 0 || strcmp(item, "<<") == 0 ||\
		strcmp(item, ">&") == 0 || strcmp(item, "<&") == 0 ||\
		strcmp(item, "|") == 0 || strcmp(item, "||") == 0 ||\
		strcmp(item, "&&") == 0 || strcmp(item, "&") == 0)
		return (OPERATOR);
	if (strcmp(item, ";") == 0)
		return (SEPARATOR);
	return (WORD);
}*/

t_token		*token_init(void)
{
	t_token *new;

	if (!(new = malloc(sizeof(t_token))))
	//	return ((int)error_malloc("token_init"));
		return (0);
	new->next = NULL;
	new->value = NULL;
	new->type = -1;
	return (new);
}

void			add_token(t_token **all, t_token *new)
{
	while (all && *all != NULL)
		all = &(*all)->next;
	new->next = (*all);
	*all = new;
}

int		delete_t_token(t_token **all_token)
{
	t_token *tmp;

	tmp = NULL;
	while (*all_token != NULL)
	{
		tmp = (*all_token)->next;
		ft_strdel(&(*all_token)->value);
		(*all_token) = tmp;
	}
	if (*all_token)
		free(*all_token);
	if (tmp)
		free(tmp);
	return (0);
}

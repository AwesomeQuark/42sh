/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:00:30 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:44:04 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_set(size_t size, char c)
{
	char	*tab;

	if (!(tab = malloc(sizeof(char) * size + 1)))
		return (NULL);
	tab[size] = '\0';
	while (size-- > 0)
		tab[size] = c;
	return (tab);
}

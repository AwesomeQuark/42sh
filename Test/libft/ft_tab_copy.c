/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:57:02 by mbonati           #+#    #+#             */
/*   Updated: 2019/06/06 11:57:05 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_copy(char **tab)
{
	char	**new;
	size_t	size;
	size_t	i;

	size = ft_tab_size(tab);
	if (!(new = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	new[size] = NULL;
	i = 0;
	while (i < size)
	{
		if (!(new[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	return (new);
}

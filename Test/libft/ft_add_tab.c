/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:36:50 by mbonati           #+#    #+#             */
/*   Updated: 2019/05/16 15:36:52 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	fill_tab(char **tab, char **new_tab, char *new, size_t size)
{
	size_t	i_tab;

	i_tab = 0;
	while (i_tab < size)
	{
		if (!(new_tab[i_tab] = ft_strdup(tab[i_tab])))
			return (0);
		i_tab++;
	}
	if (!(new_tab[i_tab] = ft_strdup(new)))
		return (0);
	return (1);
}

char		**ft_add_tab(char **tab, char *new)
{
	char	**new_tab;
	size_t	size_tab;

	size_tab = ft_tab_size(tab);
	if (!(new_tab = malloc(sizeof(char *) * (size_tab + 2))))
		return (NULL);
	new_tab[size_tab + 1] = NULL;
	if (!(fill_tab(tab, new_tab, new, size_tab)))
		return (NULL);
	ft_tab_del(tab);
	ft_strdel(&new);
	return (new_tab);
}

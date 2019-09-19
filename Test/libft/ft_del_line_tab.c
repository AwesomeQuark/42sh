/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:36:50 by mbonati           #+#    #+#             */
/*   Updated: 2019/05/16 15:36:52 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	fill_tab(char **tab, char **new_tab, size_t place)
{
	size_t	i_ntab;
	size_t	i_tab;
	size_t	size;

	i_ntab = 0;
	i_tab = 0;
	size = ft_tab_size(tab);
	while (i_tab < size)
	{
		if (i_tab == place)
			i_tab++;
		if (tab[i_tab])
			if (!(new_tab[i_ntab] = ft_strdup(tab[i_tab])))
				return (0);
		i_tab++;
		i_ntab++;
	}
	return (1);
}

char		**ft_del_line_tab(char **tab, size_t place)
{
	char	**new_tab;
	size_t	size_tab;

	size_tab = ft_tab_size(tab);
	if (!(new_tab = malloc(sizeof(char *) * size_tab)))
		return (NULL);
	new_tab[size_tab - 1] = NULL;
	if (!(fill_tab(tab, new_tab, place)))
		return (NULL);
	ft_tab_del(tab);
	return (new_tab);
}

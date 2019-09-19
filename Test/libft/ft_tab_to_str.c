/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:45:54 by mbonati           #+#    #+#             */
/*   Updated: 2019/06/11 12:45:57 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	fill_str(char **tab, char **str)
{
	size_t	i;
	size_t	y;
	size_t	x;

	i = 0;
	y = 0;
	x = 0;
	while (tab[i])
	{
		while (tab[i][y])
		{
			(*str)[x] = tab[i][y];
			y++;
			x++;
		}
		i++;
		y = 0;
	}
}

char		*ft_tab_to_str(char **tab)
{
	size_t	i;
	size_t	size;
	char	*result;

	i = 0;
	size = 0;
	while (tab[i])
	{
		size += ft_strlen(tab[i]);
		i++;
	}
	if (!(result = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	result[size] = '\0';
	fill_str(tab, &result);
	return (result);
}

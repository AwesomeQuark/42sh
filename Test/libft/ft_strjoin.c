/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:22:08 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:48:35 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	y;
	char	*tab;

	if (!(s1 && s2))
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(tab = malloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
	{
		tab[i + y] = s2[y];
		y++;
	}
	tab[i + y] = '\0';
	return (tab);
}

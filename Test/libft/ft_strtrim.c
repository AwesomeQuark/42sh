/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:59:54 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:44:57 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*tab;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = ft_strlen(s);
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t'\
			|| s[end] == '\0') && end > 0)
		end--;
	if (end == 0)
		return (ft_strdup(""));
	size = end - start + 1;
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (start <= end)
		tab[size++] = s[start++];
	tab[size] = '\0';
	return (tab);
}

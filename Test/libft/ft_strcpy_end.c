/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:56:54 by mbonati           #+#    #+#             */
/*   Updated: 2019/02/25 15:56:55 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_end(char *dest, const char *src)
{
	int i;
	int y;

	i = 0;
	y = ft_strlen(dest) - ft_strlen(src);
	while (src[i])
	{
		dest[y] = src[i];
		y++;
		i++;
	}
	dest[y] = src[i];
	return (dest);
}

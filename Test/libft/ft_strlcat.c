/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:54:12 by mbonati           #+#    #+#             */
/*   Updated: 2018/11/19 08:37:44 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	y;
	size_t	size_src;
	size_t	size_dest;

	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);
	if (n == 0)
		return (size_src);
	i = ft_strlen(dest);
	y = 0;
	while (src[y] && i + y < n - 1)
	{
		dest[i + y] = src[y];
		y++;
	}
	dest[i + y] = '\0';
	if (n <= size_dest)
		return (size_src + n);
	else
		return (size_src + size_dest);
}

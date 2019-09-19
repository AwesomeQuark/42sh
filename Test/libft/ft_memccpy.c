/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:09:04 by mbonati           #+#    #+#             */
/*   Updated: 2018/11/22 18:47:46 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest_v, const void *src_v, int c, size_t n)
{
	size_t	i;
	char	*src;
	char	*dest;

	i = 0;
	src = (char *)src_v;
	dest = (char *)dest_v;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}

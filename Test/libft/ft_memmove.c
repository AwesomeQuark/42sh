/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:41:03 by mbonati           #+#    #+#             */
/*   Updated: 2018/12/01 18:55:36 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_c;
	char	*src_c;

	i = n;
	dest_c = (char *)dest;
	src_c = (char *)src;
	if (src_c < dest_c)
	{
		while (i-- > 0)
			dest_c[i] = src_c[i];
	}
	i = 0;
	if (src_c > dest_c)
	{
		while (i < n)
		{
			dest_c[i] = src_c[i];
			i++;
		}
	}
	return (dest);
}

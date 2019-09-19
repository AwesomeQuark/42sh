/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:26:14 by mbonati           #+#    #+#             */
/*   Updated: 2018/11/20 17:04:47 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s_v;

	i = 0;
	s_v = (char *)s;
	while (i < n)
	{
		if (s_v[i] == (char)c)
			return (s_v + i);
		i++;
	}
	return (NULL);
}

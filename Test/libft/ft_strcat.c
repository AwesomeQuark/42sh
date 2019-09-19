/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:38:12 by mbonati           #+#    #+#             */
/*   Updated: 2018/11/22 22:53:58 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t i_dest;

	i = 0;
	i_dest = 0;
	while (dest[i_dest])
		i_dest++;
	while (src[i])
	{
		dest[i_dest] = src[i];
		i_dest++;
		i++;
	}
	dest[i_dest] = '\0';
	return (dest);
}

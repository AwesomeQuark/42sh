/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:27:56 by mbonati           #+#    #+#             */
/*   Updated: 2018/11/19 11:32:43 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i_str;
	size_t	i_tf;
	char	*str_c;
	char	*to_find_c;

	str_c = (char *)str;
	to_find_c = (char *)to_find;
	i_str = 0;
	if (to_find_c[0] == '\0')
		return (str_c);
	while (str_c[i_str])
	{
		i_tf = 0;
		while (str_c[i_str + i_tf] == to_find_c[i_tf]\
				&& to_find_c[i_tf])
			i_tf++;
		if (to_find_c[i_tf] == '\0')
			return (str_c + i_str);
		i_str++;
	}
	return (NULL);
}

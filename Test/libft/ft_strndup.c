/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:28:44 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:47:14 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*tab;

	if (!(tab = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	return (ft_strncpy(tab, s, n));
}

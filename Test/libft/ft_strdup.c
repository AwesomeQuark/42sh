/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:26:20 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:48:19 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tab;

	if (!(tab = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	return (ft_strcpy(tab, s));
}

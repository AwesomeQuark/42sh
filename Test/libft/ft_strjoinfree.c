/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:07:36 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:48:12 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int x)
{
	char *s3;

	s3 = ft_strjoin(s1, s2);
	if (x & 1)
		ft_strdel(&s1);
	if (x & 2)
		ft_strdel(&s2);
	return (s3);
}

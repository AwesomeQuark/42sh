/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pustr_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:28:09 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:48:54 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_space(char *str, size_t spaces)
{
	size_t i;

	ft_putstr(str);
	if (ft_strlen(str) < spaces)
	{
		i = spaces - ft_strlen(str);
		while (i)
		{
			ft_putchar(' ');
			i--;
		}
	}
}

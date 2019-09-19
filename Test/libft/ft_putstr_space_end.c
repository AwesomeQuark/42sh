/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_space_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:40:13 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:49:25 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_space_end(char *str, size_t spaces)
{
	size_t i;

	if (ft_strlen(str) < spaces)
	{
		i = spaces - ft_strlen(str);
		while (i)
		{
			ft_putchar(' ');
			i--;
		}
	}
	ft_putstr(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_space_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:40:32 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:49:56 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_space_end(int nbr, size_t spaces)
{
	size_t i;

	if (ft_intsize(nbr) < spaces)
	{
		i = spaces - ft_intsize(nbr);
		while (i)
		{
			ft_putchar(' ');
			i--;
		}
	}
	ft_putnbr(nbr);
}

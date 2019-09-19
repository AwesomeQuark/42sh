/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:28:19 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:51:27 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_space(int nbr, size_t spaces)
{
	size_t i;

	ft_putnbr(nbr);
	if (ft_intsize(nbr) < spaces)
	{
		i = spaces - ft_intsize(nbr);
		while (i)
		{
			ft_putchar(' ');
			i--;
		}
	}
}

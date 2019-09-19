/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:44:00 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:52:32 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_filling(size_t i, int puissance, size_t n, char *result)
{
	while (puissance > 1)
	{
		result[i] = n / puissance + '0';
		n -= (n / puissance) * puissance;
		puissance /= 10;
		i++;
	}
	result[i] = n + '0';
	result[i + 1] = '\0';
	return (result);
}

char			*ft_itoa(int n)
{
	size_t		size;
	size_t		i;
	char		*result;
	int			puissance;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_intsize(n);
	if (!(result = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		result[i] = '-';
		n = -n;
		i++;
		size--;
	}
	puissance = 1;
	while (size > 1)
	{
		puissance *= 10;
		size--;
	}
	return (ft_filling(i, puissance, n, result));
}

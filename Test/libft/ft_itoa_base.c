/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:55:47 by conoel            #+#    #+#             */
/*   Updated: 2019/04/25 20:55:58 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsize_base(int n, int base)
{
	size_t			size;

	size = 0;
	while (n)
	{
		n /= base;
		size++;
	}
	return (size);
}

char		*ft_itoa_base(int n, int base)
{
	char	*result;
	int		size;

	size = ft_intsize_base(n, base);
	if (!(result = malloc(sizeof(char) * size + 1)))
		return (NULL);
	result[size] = '\0';
	size--;
	while (n > 0)
	{
		result[size] = n % base + '0';
		n /= base;
		size--;
	}
	return (result);
}

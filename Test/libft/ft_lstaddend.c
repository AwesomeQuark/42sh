/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:15:06 by mbonati           #+#    #+#             */
/*   Updated: 2018/11/27 22:35:42 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	if ((*alst) == NULL)
		*alst = new;
	else
	{
		while ((*alst)->next != NULL)
			alst = &((*alst)->next);
		(*alst)->next = new;
	}
}

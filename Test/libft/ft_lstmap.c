/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:41:24 by mbonati           #+#    #+#             */
/*   Updated: 2018/11/27 23:09:39 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst_cpy;
	t_list *tmp;

	lst_cpy = NULL;
	while (lst != NULL)
	{
		tmp = (*f)(lst);
		ft_lstaddend(&lst_cpy, ft_lstnew(tmp->content, tmp->content_size));
		lst = lst->next;
	}
	return (lst_cpy);
}

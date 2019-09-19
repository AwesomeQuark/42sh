/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:01:40 by mbonati           #+#    #+#             */
/*   Updated: 2019/09/04 15:01:41 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char	*error_malloc(char *function_name)
{
	ft_putstr_fd("error: allocation failed in function: ", 2);
	ft_putstr_fd(function_name, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:30:42 by conoel            #+#    #+#             */
/*   Updated: 2019/08/29 12:28:17 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	handle_left(void)
{
	tgoto("cm", 1, 0);
}

void	handle_right(void)
{
	tgoto("cm", 0, 1);
}

void	handle_up(void)
{
	tgoto("cm", -1, 0);
}

void	handle_down(void)
{
	tgoto("cm", 0, -1);
}

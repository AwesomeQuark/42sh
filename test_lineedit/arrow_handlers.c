/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:30:42 by conoel            #+#    #+#             */
/*   Updated: 2019/08/29 14:34:00 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	handle_left(t_info *info)
{
	if (info->cursor_index == 0)
		return ;
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->cursor_index--;
}

void	handle_right(t_info *info)
{
	if (info->cursor_index > ft_strlen(info->command))
		return ;
	tputs(tgetstr("nd", NULL), 1, ft_putchar);
	info->cursor_index++;
}

void	handle_up(t_info *info)
{

	tputs(tgetstr("up", NULL), 1, ft_putchar);
}

void	handle_down(t_info *info)
{
	tputs(tgetstr("do", NULL), 1, ft_putchar);
}

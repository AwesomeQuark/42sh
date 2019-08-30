/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:30:42 by conoel            #+#    #+#             */
/*   Updated: 2019/08/30 16:22:28 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	handle_left(t_info *info)
{
	if (info->cursor_index == 0)
		return ;
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->cursor_index--;
}

void	handle_right(t_info *info)
{
	if (info->cursor_index >= ft_strlen(info->command))
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

void	handle_del(t_info *info)
{
	char	*str;
	int		i;

	if (info->cursor_index == 0)
		return ;
	str = info->command;
	i = info->cursor_index;
	ft_memmove(&str[i - 1], &str[i], ft_strlen(&str[i - 1]));
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	write(1, &str[i - 1], ft_strlen(&str[i - 1]));
	write(1, " ", 1);
	for (int j = ft_strlen(&str[i - 1]) + 1; j > 0; j--)
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->cursor_index--;
}

void	handle_home(t_info *info)
{
	for (int i = info->cursor_index; i > 0; i--)
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->cursor_index = 0;
}

void	handle_end(t_info *info)
{
	for (int i = ft_strlen(info->command) - info->cursor_index; i > 0; i--)
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
	info->cursor_index = ft_strlen(info->command);
}

void	handle_tab(t_info *info)
{
	int		i;
	char	*str;

	str = info->command;
	i = info->cursor_index;
	ft_memmove(&str[i + 4], &str[i], ft_strlen(&str[i]));
	ft_memcpy(&str[i], "    ", 4);
	write(1, &str[i], ft_strlen(&str[i]));
	for (int j = ft_strlen(&str[i]) - 4; j > 0; j--)
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->cursor_index += 4;
}
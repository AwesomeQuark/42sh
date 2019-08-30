/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:45:34 by conoel            #+#    #+#             */
/*   Updated: 2019/08/30 16:30:38 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

int	test_left(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
		return (1);
	else
		return (0);
}

int	test_right(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
		return (1);
	else
		return (0);
}

int	test_up(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		return (1);
	else
		return (0);
}

int	test_down(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		return (1);
	else
		return (0);
}

int	test_del(char *buff)
{
	if (buff[0] == 127 && buff[1] == 0)
		return (1);
	else
		return (0);
}

int	test_home(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 72)
		return (1);
	else
		return (0);
}

int	test_end(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 70)
		return (1);
	else
		return (0);
}

int	test_tab(char *buff)
{
	if (buff[0] == '\t' && buff[1] == 0)
		return (1);
	else
		return (0);
}
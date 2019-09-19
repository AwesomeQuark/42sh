/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:06:28 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/25 20:45:10 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	buf_split(char *buf, char **line)
{
	char	*endl_ptr;

	if (buf[0] == '\0')
		return (1);
	if ((endl_ptr = ft_strchr(buf, '\n')))
		*endl_ptr = '\0';
	if (*line == NULL)
		*line = ft_strdup(buf);
	else
		*line = ft_strjoinfree(*line, buf, 1);
	if (!(*line))
		return (0);
	if (endl_ptr)
		ft_strcpy(buf, endl_ptr + 1);
	else
		ft_bzero(buf, BUFF_SIZE);
	return (endl_ptr == NULL);
}

int			get_next_line(const int fd, char **line)
{
	int				ret_read;
	static char		*buf = NULL;

	if (line == NULL && read(fd, buf, 0) == -1)
		return (-1);
	*line = NULL;
	if (buf == NULL)
		if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
			return (-1);
	while (buf_split(buf, line))
	{
		if ((ret_read = read(fd, buf, BUFF_SIZE)) <= 0)
		{
			if (*line != NULL && ret_read == 0)
				return (1);
			ft_strdel(&buf);
			return (ret_read);
		}
		buf[ret_read] = '\0';
	}
	ft_strdel(&buf);
	return (*line == NULL ? -1 : 1);
}

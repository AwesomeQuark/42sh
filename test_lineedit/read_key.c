#include "line_edit.h"

static t_handlers g_handlers[] =
{
	{test_left, handle_left},
	{test_right, handle_right},
	{test_down, handle_down},
	{test_up, handle_up},
	{NULL, NULL}
};

int			read_key(void)
{
	char		buff[4];
	int			i;

	while (1)
	{
		i = 0;
		ft_bzero(buff, 4);
		read(0, buff, 3);
		while (1)
		{
			if (g_handlers[i].test == NULL)
			{
				write(1, buff, 1);
				break ;
			}
			if (g_handlers[i].test(buff))
			{
				g_handlers[i].handler();
				break ;
			}
			i++;
		}
	}
	return (0);
}

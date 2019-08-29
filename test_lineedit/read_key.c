#include "line_edit.h"

static t_handlers g_handlers[] =
{
	{test_left, handle_left},
	{test_right, handle_right},
	{test_down, handle_down},
	{test_up, handle_up},
	{NULL, NULL}
};

void	insert_char(char *str, char *c, int index)
{
	str[index] = *c;
	write(1, c, 1);
	//tputs(tgetstr("le", NULL), 1, ft_putchar);
}

int	exec_key(char *buff, t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		if (g_handlers[i].test == NULL)
		{
			insert_char(info->command, buff, info->cursor_index);
			info->cursor_index++;
			break ;
		}
		if (g_handlers[i].test(buff))
		{
			g_handlers[i].handler(info);
			break ;
		}
		i++;
	}
	return (1);
}

char	*read_key(void)
{
	t_info		info;
	char		buff[4];

	ft_bzero(&info, sizeof(info));
	write(1, "$>", 2);
	while (1)
	{
		ft_bzero(buff, 4);
		read(0, buff, 3);
		exec_key(buff, &info);
	}
	return (ft_strdup(info.command));
}

#include "line_edit.h"

static t_handlers g_handlers[] =
{
	{test_left, handle_left},
	{test_right, handle_right},
	{test_down, handle_down},
	{test_up, handle_up},
	{test_del, handle_del},
	{test_home, handle_home},
	{test_end, handle_end},
	{test_tab, handle_tab},
	{NULL, NULL}
};

void	insert_char(char *str, char *c, int index)
{
	ft_memmove(&str[index + 1], &str[index], ft_strlen(&str[index]));
	str[index] = *c;
	write(1, &str[index], ft_strlen(&str[index]));
	for (int i = ft_strlen(&str[index]) - 1; i > 0; i--)
		tputs(tgetstr("le", NULL), 1, ft_putchar);
}

int	exec_key(char *buff, t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		if (g_handlers[i].test == NULL)
		{
			if (buff[1] == 0)
			{			
				insert_char(info->command, buff, info->cursor_index);
				info->cursor_index++;}
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
	write(1, "$> ", 3);
	while (1)
	{
		ft_bzero(buff, 4);
		read(0, buff, 3);
		if (ft_strcmp(buff, "\n") == 0)
			return (ft_strdup(info.command));
		exec_key(buff, &info);
	}
}

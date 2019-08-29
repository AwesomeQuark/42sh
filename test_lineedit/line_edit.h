#ifndef LINE_EDIT_H
# define LINE_EDIT_H

# include <term.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include "haflib.h"

typedef struct	s_term
{
	char			*name;
	struct termios	term;
}				t_term;

typedef struct s_info
{
	int		cursor_index;
	char	command[131072];
}				t_info;

typedef struct	s_handlers
{
	int		(*test)(char *buff);
	void	(*handler)(t_info *info);
}				t_handlers;


struct termios	g_term_mem;

int				ft_putchar_stdout(int c);
void			end(int no);
char			*read_key(void);
int ft_putchar(int c);

void			handle_left(t_info *info);
int				test_left(char *buff);
void			handle_right(t_info *info);
int				test_right(char *buff);
void			handle_down(t_info *info);
int				test_down(char *buff);
void			handle_up(t_info *info);
int				test_up(char *buff);
void			handle_del(t_info *info);

#endif

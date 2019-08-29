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

typedef struct	s_handlers
{
	int		(*test)(char *buff);
	void	(*handler)(void);
}				t_handlers;

struct termios	g_term_mem;

int				ft_putchar_stdout(int c);
void			end(int no);
int				read_key(void);

void			handle_left(void);
int				test_left(char *buff);
void			handle_right(void);
int				test_right(char *buff);
void			handle_down(void);
int				test_down(char *buff);
void			handle_up(void);
int				test_up(char *buff);
void			handle_del(void);
int				test_del(char *buff);
void			handle_escape(void);
int				test_escape(char *buff);
int				test_space(char *buff);
void			handle_space(void);
int				test_enter(char *buff);
void			handle_enter(void);
int				test_completion(char *buff);
void			handle_completion(void);

#endif

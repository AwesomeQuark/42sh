/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:30:01 by mbonati           #+#    #+#             */
/*   Updated: 2019/09/12 11:30:03 by mbonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../new_lib/libft.h"
//# include "haflib.h"
# define USAGE "Usage: ./21sh"

typedef enum        e_token_type
{
    OPERATOR,
    WORD,
	SEPARATOR
}                   t_type;

typedef struct		s_token
{
	char			*value;
	int				type;
	struct s_token 	*next;
}					t_token;

typedef struct      s_ast
{
    struct s_ast	*left;
    struct s_ast	*right;
    t_type			type;
    char                    *content;
}                   t_ast;

int			cmd_handler(char *cmd_line, t_token **all_words);
void		add_token(t_token **all, t_token *new);
char		*extract_cmd(char *cmd_line, int *i);
size_t		word_len(char *cmd_line);
size_t		quote_len(char *cmd_line);
t_token		*token_init(char *item);
int			is_quote(char c);

#endif

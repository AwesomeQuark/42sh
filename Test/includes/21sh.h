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
# include "libft.h"
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
	struct s_token 	*previous;
	struct s_token 	*next;
}					t_token;

typedef struct      s_ast
{
    struct s_ast	*left;
    struct s_ast	*right;
    t_type			type;
    char                    *content;
}                   t_ast;

int			tokenization(char *line, t_token **all_words);
void		add_token(t_token **all, t_token *new);
char		*extract_cmd(char *line, int *i);
size_t		word_len(char *line);
size_t		quote_len(char *line);
t_token		*token_init(void);
int			is_quote(char c);
int			is_operator(char c);
char		*error_malloc(char *function_name);
char		*extract_separator(int *i);
char		*extract_operator(char *line, int *i);
char		*handle_word(char *line, int *i);
char		*handle_quote(char *line, int *i);
int			delete_all_token(t_token **all_token);
void		delete_token(t_token *token);

#endif

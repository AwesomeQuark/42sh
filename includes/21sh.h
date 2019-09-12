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
# include "haflib.h"
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

#endif

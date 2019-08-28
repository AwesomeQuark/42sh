#ifndef SH_H
# define SH_H

# include <unistd.h>
# include "haflib.h"
# define USAGE "Usage: ./21sh"

typedef enum        e_ast_type
{
    TYPE,
    TYPE2
}                   t_type;

typedef struct      s_sh21_ast_struct
{
    struct sh21_ast_struct  *left;
    struct sh21_ast_struct  *right;
    t_type                  type;
    char                    *content;
}                   t_ast;

#endif
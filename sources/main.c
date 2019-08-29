#include "21sh.h"

int     main(void)
{
    char    *raw_commands;
    char    **all_commands;
    char    **command;
    t_ast   *ast;
    int     i;

    i = 0;
    raw_commands = get_the_file(0);
    all_commands = ft_strsplit(raw_commands, ';');
    while (all_commands[i])
    {
        command = split_modified(all_commands[i], " "); //TODO
        ast = ast_constructor(command); // TODO
        execute(ast);  // TODO
        i++;
    }
}

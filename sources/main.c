#include "21sh.h"

void    quit(char *comm)
{
    free(comm);
    printf("quit\n");
}

int execute(char *comm)
{
    size_t i;

    i = 0;
    while (i < ft_strlen(comm))
       ft_printf("%c\n", comm[i++]);
    ft_printf("Done !");
    return (1);
}

int parse(char  **comm)
{
    *comm = get_the_file(0);
    return (1);
}

int main(void)
{
    char    *comm;

    comm = NULL;
    while (1)
    {
        if (!(parse(&comm)))
            quit(comm);
        if (!(execute(comm)))
            quit(comm);
        free(comm);
    }
}

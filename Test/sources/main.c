#include "21sh.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_token *test;

	test = NULL;
	if (ac)
	{
		tokenization(av[1], &test);
		while (test)
		{
			printf("VALUE : [%s]\n", test->value);
			if (test->type == 0)
				printf("TYPE : operator\n\n");
			if (test->type == 1)
				printf("TYPE : word\n\n");
			if (test->type == 2)
				printf("TYPE : separator\n\n");
			test = test->next;
		}
	}
	return 0;
}

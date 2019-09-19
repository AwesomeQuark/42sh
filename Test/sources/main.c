#include "21sh.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_token *test;
	t_token	*tmp;

	test = NULL;
	if (ac)
	{
		tokenization(av[1], &test);
		tmp = test;
		while (test->next)
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
		printf("- - - - - - \n\n");
		while (test->previous)
		{
			printf("VALUE : [%s]\nadd : %p\n", test->value, test->previous);
			if (test->type == 0)
				printf("TYPE : operator\n\n");
			if (test->type == 1)
				printf("TYPE : word\n\n");
			if (test->type == 2)
				printf("TYPE : separator\n\n");
			test = test->previous;
		}
		delete_all_token(&tmp);
	}
	return 0;
}

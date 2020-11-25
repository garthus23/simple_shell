#include "hsh.h"

/**
 * hsh_exit - exit builtin function
 * @str: an input string
 * @arr: an array
 * @args: an array
 * @st: a struct
 * Return: nothing
 **/

void hsh_exit(char *str, char **arr, char **args, struct stat *st)
{
	char *result = "exit";
	int ex = 1;
	int i;

	if (_strlen(str) >= 1)
	{
		for (i = 0; result[i] != '\0'; i++)
		{
			if (str[i] != result[i])
			{
				ex = 0;
				break;
			}
		}
		if (ex == 1)
		{
			free_arr(arr);
			free_arr(args);
			free(st);
			exit(0);
		}
	}
}

#include "hsh.h"

/**
 * array_PATH - concat path env to an array
 * @env: the env vars
 * @buf: the array
 * @arr: an array
 * @path: index
 * Return: a new 2D array
 **/

char **array_PATH(char **env, char **buf, char **arr, int *path)
{
	int j, k, l, index, lentot;
	char *delim = ":=";
	char *token;

	if (env[*path] != NULL)
	{
		index = 0;
		token = _strtok(env[*path], delim, &index);
		token = _strtok(env[*path], delim, &index);
		j = 0;
		while (env[*path][index] != '\0')
		{
			token = _strtok(env[*path], delim, &index);
			lentot = _strlen(token) + _strlen(*buf) + 2;
			arr[j] = malloc(sizeof(char) * lentot);
			for (k = 0; k < _strlen(token); k++)
				arr[j][k] = token[k];
			arr[j][k] = '/';
			k++;
			l = 0;
			for (; k <= lentot ; k++)
			{
				arr[j][k] = (*buf)[l];
				l++;
			}
			arr[j][k] = '\0';
			j++;
		}
		free(token);
	}
	return (arr);
}

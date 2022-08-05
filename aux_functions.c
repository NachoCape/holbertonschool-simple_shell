#include "main.h"

/**
 * _flag - aux functions to separator function
 * @str: string of char
 * @i: integer
 *
 * Description: check if the str[i+1] is a space of tab
 *
 * Return: 1 if it's a tab or space, otherwise 0
 */

int _flag(char *str, int i)
{
	int res = 0;

	if (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\n')
		res = 1;
	return (res);
}

/**
 * _getenv - get an environment variable
 * @name: array of chars (name of the varaible to search)
 * @envir: pointer to an array of pointers (all the environments variables)
 *
 * Return: an array with the environment variable, otherwise NULL
 */

char *_getenv(const char *name, char **envir)
{
	char *w = NULL;
	int i = 0, j = 0;

	for (; envir[i] != NULL; i++)/*loop to travel the environ array*/
	{
		w = envir[i];
		while (name[j] != '\0' && name[j] == w[j])
			j++;
		if (name[j] == '\0' && w[j] == '/')
			return (w);
	}
	return (NULL);
}

/**
 * cant_dir - count the directories of path
 * @path: array of chars (its the PATH environment variable
 *
 * Return: the number of directories of path
 */

int cant_dir(char *path)
{
	int res = 2, i = 0;

	for (; path[i] != '\0' ; i++)
		if (path[i] == ':')
			res++;
	return (res);
}

/**
 * _path - create an array of pointers with all the directories of PATH
 * @envir: pointer to an array of pointers (all the environments variables)
 *
 * Return: an array of pointers with the directories of PATH, otherwise NULL
 */

char **_path(char **envir)
{
	int i = 0, size = 0;
	char *path, *buf;
	char **arr_of_dir = NULL;

	path = _getenv("PATH=", envir);/*get the path environment variable*/
	if (!path/* || strlen(path) == 5*/)/*check if the path is empty*/
		return (NULL);
	size = cant_dir(path);
	arr_of_dir = malloc((size) * sizeof(char *));
	if (arr_of_dir)/*tokenize the directorys of the path*/
	{
		buf = strtok(path, ":=");

		buf = strtok(NULL, ":=");

		for (; buf; i++)
		{
			arr_of_dir[i] = strdup(buf);
			buf = strtok(NULL, ":=");
		}
		if (i > 0)
			arr_of_dir[i] = NULL;
	}
	return (arr_of_dir);
}

/**
 * _which - search a command
 * @command: array of chars (command to search)
 * @envir: pointer to an array of pointers (all the environments variables)
 * @arr: pointer to an array of pointers
 * @argv: pointer to an array of pointers
 * @res: int (status to be return)
 *
 * Description: search if command its a valid command througth the differents
 * directories of the PATH
 *
 * Return: an array of chars with the correct route of the command
 * otherwise NULL
 */

char *_which(char *command, char **envir, char **arr, char **argv, int *res)
{
	char **path = NULL;
	struct stat st;
	char *buf = NULL;
	int i = 0, size = 0;

	if (stat(command, &st) == 0)/*if the command has the correct route*/
		return (command);
	if (strcmp(arr[0], "env") == 0)/*env builtin*/
	{
		_env(envir, arr);
		return (NULL);
	}
	path = _path(envir);
	if (!path)/*case empty path*/
	{
		errors(argv, command);
		*res = 127;
		return (NULL);
	}
	while (path[i])/*search and concats the command in all dirs of path*/
	{
		size = (strlen(path[i]) + strlen(command) + 2);
		buf = malloc(size * sizeof(char));
		if (!buf)
			return (NULL);
		buf = str_concat(buf, path, command, i);
		if (stat(buf, &st) == 0)
			break;
		free(buf);
		buf = NULL;
		i++;
	}
	if (!buf)
	{
		errors(argv, command);
		*res = 127;
	}
	free_arr(path);
	return (buf);
}

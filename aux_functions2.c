#include "main.h"

/**
 * free_arr - free the memory of a grid
 * @arr: pointer to an array of pointers
 * Return: void
 */

void free_arr(char **arr)
{
	int i = 0, size = 0;

	while (arr[size] != NULL)
		size++;
	for (; i < size; i++)
		free(arr[i]);
	free(arr);
}

/**
 * freedom - free the memory of envir and buf
 * @envir: pointer to an array of pointers
 * @buf: string of chars
 *
 * Return: void
 */

void freedom(char **envir, char *buf)
{
	if (envir)
	{
		free_arr(envir);
		envir = NULL;
	}
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
}

/**
 * freedom3 - free the memory of arr, buf and envir
 * @arr: pointer to an array of pointers
 * @buf: string of chars
 * @envir: pointer to an array of pointers
 *
 * Return: void
 */

void freedom3(char **arr, char *buf, char **envir)
{
	if (envir)
	{
		free_arr(envir);
		envir = NULL;
	}
		if (buf)
	{
		free(buf);
		buf = NULL;
	}
	if (arr)
	{
		free_arr(arr);
		arr = NULL;
	}
}

/**
 * str_concat - concat two arrays with a "/" in the middle of them
 * @buf: array of chars (new buf when they will be concat)
 * @path: pointer to an array of pointers
 * @command: array of chars (command to concat)
 * @i: integer (the index of the path[i] to be concat)
 *
 * Description: concat path[i] and command with a "/" in the middle of them
 * in buf
 *
 * Return: buf
 */

char *str_concat(char *buf, char **path, char *command, int i)
{
	strcpy(buf, path[i]);
	strcat(buf, "/");
	strcat(buf, command);
	return (buf);
}

/**
 * rm_jump - remove a '\n'
 * @buf: array of chars
 *
 * Return: void
 */

void rm_jump(char *buf)
{
	int j = 0;

	for (j = 0; buf[j]; j++)
		;
	if (buf[j] == '\0' && buf[j - 1] == '\n' && j != 1)
		buf[j - 1] = '\0';
}

#include "main.h"

/**
 * mod_buf - remove the spaces or tabs in the beggining of buff
 * @buf: array of chars
 * @size: ssize_t (size of buf)
 *
 * Return: buf
 */

char *mod_buf(char *buf, size_t size)
{
	size_t i = 0, j = 0;
	char *new_buf = NULL;

	while (buf[i] && (buf[i] == ' ' || buf[i] == '\t'))
		i++;
	new_buf = malloc(sizeof(char) * (size - i + 1));
	for (; buf[i]; i++, j++)
		new_buf[j] = buf[i];
	new_buf[j] = '\0';
	return (new_buf);
}

/**
 * save_lines - manage the exit or jump line
 * @new_buf: string of chars
 * @envir: pointer to an array of pointers
 *
 * Return: 1 in case to exit main, 2 in case of jump line, otherwise 0
 */

int save_lines(char *new_buf, char **envir)
{
	if (strcmp(new_buf, "exit\n") == 0)
	{
		free(new_buf);
		return (1);
	}
	if (new_buf && new_buf[0] == '\n')
	{
		freedom(envir, new_buf);
		return (2);
	}
	return (0);
}

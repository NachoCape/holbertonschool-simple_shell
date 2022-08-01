#include "main.h"

/**
 * mod_buf - remove the spaces or tabs in the beggining of buff
 * @buf: array of chars
 *
 * Return: buf
 */

char *mod_buf(char *buf)
{
	int i = 0, j = 0, k = 0, l = 0, count = 0;
	char *new_buf = NULL;

	while (buf[k])
		k++;
	while (buf[i] && (buf[i] == ' ' || buf[i] == '\t'))
		i++;

	l = k;
	if (k >= 2)
		k = k - 2;
	while (k >= 0 && (buf[k] == ' ' || buf[k] == '\t'))
	{
		count++;
		k--;
	}
	if (count >= 1)
	{
		buf[l - count - 1] = '\n';
		buf[l - count] = '\0';
	}
	new_buf = malloc(sizeof(char) * (l - i - count + 1));
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

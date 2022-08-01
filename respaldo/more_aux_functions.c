#include "main.h"

/**
 * mod_buf - remove the spaces or tabs in the beggining of buff
 * @buf: array of chars
 * @size_buf: ssize_t (size of buf)
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
	/**if (buf)
		free(buf);
	buf = NULL;*/
	return (new_buf);
}

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

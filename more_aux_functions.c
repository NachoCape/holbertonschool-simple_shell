#include "main.h"

/**
 * mod_buf - remove the spaces or tabs in the beggining of buff
 * @buf: array of chars
 * @aux: integer (return value of getline)
 * Return: buf
 */

char *mod_buf(char *buf, int aux)
{
	int i = 0, j = 0, k = 0, l = 0, count = 0;
	char *new_buf = NULL;

	if (aux == EOF)
		return (NULL);
	while (buf[k])
		k++;
	while (buf[i] && (buf[i] == ' ' || buf[i] == '\t'))
		i++;
	l = k;
	if ((k - i) > 2)
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
	if (!new_buf)
	{
		free(new_buf);
		return (1);
	}
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

/**
 * _putchar - print one character
 * @c: char
 *
 * Return:void
 */

void _putchar(char c)
{
	write(STDERR_FILENO, &c, 1);
}

/**
 * _puts - print a string
 * @s: string of chars
 *
 * Return:void
 */

void _puts(char *s)
{
	int i = 0;

	for (; s[i]; s++)
		_putchar(s[i]);
}

/**
 * errors - aux function to print a erro message
 * @command: the command that cause the error
 * @argv: pointer to an array of pointers
 *
 * Return: void
 */

void errors(char **argv, char *command)
{
	write(2, argv[0], strlen(argv[0]));
	write(2, ": 1: ", 5);
	write(2, command, strlen(command));
	write(2, ": not found\n", 12);
}

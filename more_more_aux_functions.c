#include "main.h"

/**
 * _wait - aux function to wait and get the exit status
 * @child: pid of the child
 * @s: int status
 *
 * Return: exit status value, otherwise 1
 */

int _wait(int child, int *s)
{
	waitpid(child, s, 0);
	if (WIFEXITED(*s))/*returns true if the child terminated normally*/
		return (WEXITSTATUS(*s));/*returns the exit status of the child*/
	return (1);
}

/**
 * _env - print all environments varaibles
 * @envir: pointer to an array of pointers
 * @arr: pointer to an array of pointers
 *
 * Return: void
 */

void _env(char **envir, char **arr)
{
	int i = 0;

	if (strcmp(arr[0], "env") == 0)
		for (; envir[i] != NULL; i++)
		{
			_puts(envir[i]);
			_putchar('\n');
		}
}

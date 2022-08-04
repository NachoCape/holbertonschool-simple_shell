#include "main.h"

/**
 * separator - this functions separate the arguments readed's
 * @str: array of chars (contain all the characters written in the Std Input)
 * @del: char (space delimited to count the amount of arguments)
 *
 * Description: count the amount of arguments, and also create
 * an array of pointers that contain in each index of the array an argument
 *
 * Return: an array of pointers, otherwise NULL
 */

char **separator(char *str, char del)
{
	int count = 2, i = 0, j = 0, k = 0;
	char **out = NULL;
	char *tok = NULL, *deli = " \n\t";

	while (str[k] && (str[k] == ' ' || str[k] == '\t'))
		k++;
	for (i = k; str[i]; i++)
		if ((str[i] == del || str[i] == '\t') && _flag(str, i))
			count++;
	out = malloc(sizeof(char *) * count);
	if (!out)
	{
		free(out);
		return (NULL);
	}
	out[count - 1] = NULL;
	tok = strtok(str, deli);
	out[j] = strdup(tok);
	while (tok)
	{
		j++;
		tok = strtok(NULL, deli);
		if (tok)
			out[j] = strdup(tok);
	}
	return (out);
}

/**
 * array_copy - copy a grid of arrays in new memory
 * @arr: a pointer to an array of pointers (environ)
 * @extra: count extra spaces
 *
 * Return: a copy in new memory of arr
 */

char **array_copy(char **arr, int extra)
{
	int i = 0, len = 0;
	char **new_arr;

	for (i = 0 ; arr[i] != NULL ; i++)
	{
	}
	new_arr = malloc(sizeof(char *) * (i + extra + 1));
	if (!new_arr)
		return (NULL);
	for (i = 0 ; arr[i] != NULL ; i++)
	{
		len = strlen(arr[i]);
		new_arr[i] = malloc(sizeof(char) * (len + 1));
		if (!new_arr[i])
			free_arr(new_arr);
		strcpy(new_arr[i], arr[i]);
		new_arr[i][len] = '\0';
	}
	new_arr[i] = NULL;
	return (new_arr);
}

/**
 * interactive - aux functions to know if we are in interactive mode or not
 * @mode: size_t
 *
 * Return: 1 if we are in interactive mode, otherwise 0
 */

int interactive(size_t mode)
{
	if (!isatty(STDIN_FILENO))
		mode = 0;
	if (isatty(STDIN_FILENO))
		write(1, "#cisfun$", 8);
	return (mode);
}

/**
 * cd - manage if the std input is "ctrl + d"
 * @eof: integer (end of the file)
 * @mode: integer (flag to know if we are in interactive mode)
 * @new_buf: string of chars
 *
 * Return: 1 if "ctrl + d" was pressed, otherwise 0
 */

int cd(int eof, int mode, char *new_buf)
{
	if (eof == EOF)
	{
		if (mode == 1)
			printf("\n");
		free(new_buf);
		return (0);
	}
	return (1);
}

/**
 * main - main function
 * @argc: amount of arguments
 * @argv: pointer to an array of pointers with the differents arguments
 *
 * Description: This is a basic shell program, which try to recreat the
 * sh (shell)
 *
 * Return: 0
 */

int main(int argc  __attribute__((unused)), char **argv)
{
	size_t size_buf = 0;
	char *buf = NULL, *new_buf = NULL, *command;
	char **arr = NULL, **envir = NULL;
	int s = 0, loop = 1, child = 0, md = 0, aux = 0, e_or_j = 0, res = 0;

	for (; ; loop++)
	{
		envir = array_copy(environ, 0);
		md = interactive(md);
		aux = getline(&buf, &size_buf, stdin);
		new_buf = mod_buf(buf, aux);
		e_or_j = save_lines(new_buf, envir);
		if (e_or_j == 2)
			continue;
		if (cd(aux, md, new_buf) == 0 || e_or_j == 1)
			break;
		arr = separator(new_buf, ' ');
		command = _which(arr[0], envir, arr);
		if (!command)
		{
			/*errors(arr[0]);*/
			freedom3(arr, new_buf, envir);
			continue;
		}
		child = fork();
		if (child == 0)
		{
			if (execve(command, arr, envir) == -1)
				perror(argv[0]);
			break;
		} else if (child == -1)
			return (1);
		res = _wait(child, &s);
		if (strcmp(command, arr[0]) != 0)
			free(command);
		freedom3(arr, new_buf, envir);
	}
	freedom(envir, buf);
	return (res);
}

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

	while (str[k] && (str[k] == ' ' || str[k] == '\t'))/*skip ' ' or \t begining*/
		k++;
	for (i = k; str[i]; i++)/*count the amount of arguments*/
		if ((str[i] == del || str[i] == '\t') && _flag(str, i))
			count++;
	out = malloc(sizeof(char *) * count);
	if (!out)/*checks if mallocs fails*/
	{
		free(out);
		return (NULL);
	}
	out[count - 1] = NULL;/*assign NULL terminated*/
	tok = strtok(str, deli);/*use strtok to capture arguments*/
	out[j] = strdup(tok);/*assign the first argument*/
	while (tok)/*loop to assign all arguments to the array*/
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

	for (i = 0 ; arr[i] != NULL ; i++)/*count the large of the grid*/
	{
	}
	new_arr = malloc(sizeof(char *) * (i + extra + 1));
	if (!new_arr)/*checks for mallocs fails*/
		return (NULL);
	for (i = 0 ; arr[i] != NULL ; i++)/*loop to duplicate strings in each arr[i]*/
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
	if (!isatty(STDIN_FILENO))/*not interactive mode*/
		mode = 0;
	if (isatty(STDIN_FILENO))/*interactive mode*/
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
	if (eof == EOF)/*checks end of the file*/
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
		envir = array_copy(environ, 0);/*copy of environ*/
		md = interactive(md);/*checks interactive mode or not*/
		aux = getline(&buf, &size_buf, stdin);/*use getline to read the stdin*/
		new_buf = mod_buf(buf, aux);/*copy and remove spaces and tabs from buff*/
		e_or_j = save_lines(new_buf, envir);/*function that controls exit and \n*/
		if (e_or_j == 2)
			continue;
		if (cd(aux, md, new_buf) == 0 || e_or_j == 1)/*manage breaks cases*/
			break;
		arr = separator(new_buf, ' ');/*tokenize the buf*/
		command = _which(arr[0], envir, arr, argv, &res);/*check the command exist*/
		if (!command)
		{
			freedom3(arr, new_buf, envir);/*function that frees almost everything*/
			continue;
		}
		child = fork();/*fork starts*/
		if (child == 0)/*fork succes*/
		{
			if (execve(command, arr, envir) == -1)
				perror(argv[0]);
			break;
		} else if (child == -1)/*fork fails*/
			return (1);
		res = _wait(child, &s);/*function to manage the wait and exit state value*/
		if (strcmp(command, arr[0]) != 0)/*free command if it alloc memory in which*/
			free(command);
		freedom3(arr, new_buf, envir);
	}
	freedom(envir, buf);
	return (res);
}

<h1 align="center">Holberton shell</h1>
This repository is about hsh (Holberton shell). The hsh is a basic command line interpreter, this basic shell try to recreate some of the functions of other shells like bash or sh. This is a public repository so feel free to clone it and use it

<h2 align="center">Description</h2>

- First at all, check if the user enters in the interactive mode, otherwise the hsh will try to execute the command only ones time<br>
- If the user enters in the interactive mode, a prompt will be displayed and the hsh will wait for the user to enter a command. When a command finished the execution, the prompt will show up again<br>
- Manage border cases like: "ctrl + d", "\n", etc<br>
- Manage commands with arguments<br>
- Handle if the user enters a command with the entire path or not, if not the hsh program will search for the command in all the directories of the PATH (environment variable)<br>

<h2 align="center">List of allowed functions</h2>

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

<h2 align="center">Files</h2>

**simple_shell.c** - this file contains the code structure of main functions and other auxiliary functions
> separator - this function separates the arguments read<br>
> array_copy - copies a grid of arrays in a new memory<br>
> interactive - aux function to know if we are in interactive mode or not<br>
> cd - manages if the std input is "ctrl + d"<br>
> main - main function<br>

**aux_functions.c** - this file contain auxiliar functions 
>  _flag - aux function that helps separator function to count the arguments<br>
>  _getenv - gets an environment variable<br>
>  cant_dir - counts the directories of the path<br>
>  _path - creates an array of pointers with all the directories of PATH<br>
>  _which - searches for a command in the PATH<br>

**aux_functions2.c** - this file contain auxiliar functions
> free_arr - frees the memory of a grid<br>
> freedom - frees the memory of envir and buf<br>
> freedom3 - frees the memory of arr, buf and envir<br>
> str_concat - concats two arrays with a "\" in the middle of them<br>

**more_aux_functions.c** - this file contain auxiliar functions
> mod_buf - removes the spaces or tabs in the beggining of buff and saves it in a new space of memory<br>
> save_lines - manages the exit or jumps line<br>
> _putchar - print one character<br>
> _puts - print a string<br>
> errors - aux function to print a erro message<br>

**more_more_aux_functions.c** - this file contain auxiliar functions
> _wait - aux function to wait and get the exit status<br>
> _env - print all environments varaibles<br>

**README.md** - contain the information and instructions about the hsh program

**AUTHORS** - List of names and emails of the program creators

**man** - man file for this shell

**main.h** - header file


<h2 align="center">How to use it</h2>

<h3>Clone this repo:</h3>

`https://github.com/NachoCape/holbertonschool-simple_shell.git`

<h3>Then compile it:</h3>

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

<h3>Now proceed to run the program:</h3>

`prompt$ ./hsh`

<h3>Write a command and that's it:</h3>

`$ command`

$: a simple prompt and wait for commands<br>
command: Every Program in $PATH


<h2 align="center">Examples</h2>


<h3>example: ls -l</h3>

    username@prompt:~$ ./hsh
    #cisfun$ls -l
    total 68
    -rw-r--r-- 1 root root  1704 Jul 31 16:49 aux_functions2.c
    -rw-r--r-- 1 root root  2657 Jul 30 22:35 aux_functions.c
    -rw-r--r-- 1 root root  1005 Jul 31 10:41 main.h
    -rw-r--r-- 1 root root  1440 Jul 31 11:09 more_aux_functions.c
    -rw-r--r-- 1 root root    33 Jul 31 09:47 README.md
    -rw-r--r-- 1 root root  3560 Jul 31 11:10 simple_shell.c


<h3>example: cat, ls -l, rm</h3>


    #cisfun$cat example
    cisfun
    #cisfun$ls -l
    total 68
    -rw-r--r-- 1 root root  1704 Jul 31 16:49 aux_functions2.c
    -rw-r--r-- 1 root root  2657 Jul 30 22:35 aux_functions.c
    -rw-r--r-- 1 root root     7 Jul 31 17:12 example
    -rw-r--r-- 1 root root  1005 Jul 31 10:41 main.h
    -rw-r--r-- 1 root root  1440 Jul 31 11:09 more_aux_functions.c
    -rw-r--r-- 1 root root    33 Jul 31 09:47 README.md
    -rw-r--r-- 1 root root  3560 Jul 31 11:10 simple_shell.c
    #cisfun$rm example
    #cisfun$ls -l
    total 68
    -rw-r--r-- 1 root root  1704 Jul 31 16:49 aux_functions2.c
    -rw-r--r-- 1 root root  2657 Jul 30 22:35 aux_functions.c
    -rw-r--r-- 1 root root  1005 Jul 31 10:41 main.h
    -rw-r--r-- 1 root root  1440 Jul 31 11:09 more_aux_functions.c
    -rw-r--r-- 1 root root    33 Jul 31 09:47 README.md
    -rw-r--r-- 1 root root  3560 Jul 31 11:10 simple_shell.c


<h2>Flowchart</h2>
<img src="https://user-images.githubusercontent.com/105528074/183089037-aeaa8bf3-8fba-444d-b960-4b20b4adfea2.png"></img>


    

<h2>Authors</h2>

Ignacio Capezzolo, Mauro Trenche

<h1 align="center">Holberton shell</h1>
This repository it's about hsh (Holberton shell). The hsh it's a basic command line interpreter, this basic shell try to recreate someones of the functions of other shells like bash or sh. This is a public repository so feel free to clone it and use it

<h2 align="center">Description</h2>

- First at all checks if the user enter in the interactive mode, in negative case the will try to execute the command only one time<br>
- If user enter in the interactive mode, it shows a prompt and wait the user enter a command. When a command ends the execution the prompt shows again<br>
- Manage border cases like: "ctrl + d", "\n", etc<br>
- Manage commands with arguments<br>
- Handle if the user enter a command with the entire path or not, in negative the hsh program will search in all directories of the PATH (environment variable)<br>

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

**simple_shell.c** - contains the code structure of main functions and other auxiliar functions
> separator - this functions separate the arguments readed's<br>
> array_copy - copy a grid of arrays in new memory<br>
> interactive - aux functions to know if we are in interactive mode or not<br>
> cd - manage if the std input is "ctrl + d"<br>
> main - main function<br>

**aux_functions.c** - this file contain auxiliar functions 
>  _flag - aux functions that help separator function to count the arguments<br>
>  _getenv - get an environment variable<br>
>  cant_dir - count the directories of path<br>
>  _path - create an array of pointers with all the directories of PATH<br>
>  _which - search a command in the PATH<br>

**aux_functions2.c** - this file contain auxiliar functions
> free_arr - free the memory of a grid<br>
> freedom - free the memory of envir and buf<br>
> freedom3 - free the memory of arr, buf and envir<br>
> str_concat - concat two arrays with a "/" in the middle of them<br>

**more_functions.c** - this file contain auxiliar functions
> mod_buf - remove the spaces or tabs in the beggining of buff and save it in a new space of memory<br>
> save_lines - manage the exit or jump line<br>

**README.md** - contain the information and instructions about the hsh program

**AUTHORS** - List with names and emails of the creators of the program

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


<h2>Authors</h2>

Ignacio Capezzolo, Mauro Trenche

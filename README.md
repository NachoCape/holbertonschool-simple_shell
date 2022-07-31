<h1 align="center">Holberton shell</h1>
This repository it's about hsh (Holberton shell). The hsh it's a basic command line interpreter, this basic shell try to recreate someones of the functions of other shells like bash or sh. This is a public repository so feel free to clone it and use it

<h2 align="center">Description</h2>

- First at all checks if the user enter in the interactive mode, in negative case the will try to execute the command only one time<br>
- If user enter in the interactive mode, it shows a prompt and wait the user enter a command. When a command ends the execution the prompt shows again<br>
- Manage border cases like: "ctrl + d", "\n", etc<br>
- Manage commands with arguments<br>
- Handle if the user enter a command with the entire path or not, in negative the hsh program will search in all directories of the PATH (environment variable)<br>

<h2 align="center">List of allows functions</h2>

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

**aux_functions.c** - this file contain auxiliar functions 
>

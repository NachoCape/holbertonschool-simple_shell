#ifndef main_h
#define main_h

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

char **separator(char *str, char del);
char **array_copy(char **arr, int extra);
int cd(int eof, int mode, char *new_buf);
int interactive(size_t mode);
/**void execution(char *command, char **ar, char **nacho, char **envir);*/
char *_which(char *command, char **envir, char **arr, char **argv);
char **_path(char **envir);
char *_getenv(const char *name, char **envir);
int cant_dir(char *path);
int _flag(char *str, int i);
void free_arr(char **arr);
void freedom(char **envir, char *buf);
void freedom3(char **arr, char *buf, char **envir);
/*void freedom2(char **arr, char **envir);*/
char *str_concat(char *buf, char **path, char *command, int i);
void rm_jump(char *buf);
char *mod_buf(char *buf, int aux);
int save_lines(char *new_buf, char **envi);
void _putchar(char c);
void _puts(char *s);
void errors(char **argv, char *command);
int _wait(int child, int *s);
void _env(char **envir, char **arr);

#endif

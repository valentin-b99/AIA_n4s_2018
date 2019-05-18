/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ai
*/

#ifndef AI_H_
#define AI_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/my/mylib.h"

/* src/ai.c */
int set_dir(int mid, int left, int right);
int set_speed(int mid, int left, int right);
void set_vars(int *left, int *right, int *mid, char **array);
int ai_loop(void);

/* src/puttest.c */
int puttest(char *str, int fd);

#endif /* !AI_H_ */
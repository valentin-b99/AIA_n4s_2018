/*
** EPITECH PROJECT, 2019
** puttest.c
** File description:
** puttest
*/

#include "../include/ai.h"

int puttest(char *str, int fd)
{
    write(fd, str, my_strlen(str));
    return (0);
}
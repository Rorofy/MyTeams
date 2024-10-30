/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that removes useless newline from string
*/

#include <string.h>

char *remove_newline(char *str)
{
    const size_t len = strlen(str) - 1;

    if (str[len] == '\n')
        str[len] = '\0';
    return (str);
}
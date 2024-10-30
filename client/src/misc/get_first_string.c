/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that get the first string from a variable
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int get_quote_pos(const char *str)
{
    int res = 0;

    for (; str[res] != '"'; ++res)
        if (str[res] == '\0')
            return (-1);
    return (res);
}

char *get_first_string(const char *str)
{
    char *res = NULL;
    int closing_quote_pos = get_quote_pos(str + 1) + 1;

    if (closing_quote_pos == -1)
        return (NULL);
    res = calloc(closing_quote_pos + 1, sizeof(char));
    if (res == NULL)
        return (NULL);
    if (closing_quote_pos == 0)
        return (res);
    memcpy(res, str + 1, closing_quote_pos - 1);
    return (res);
}

/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that checks arguments
*/

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

static bool is_number(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (isdigit(str[i]) == 0)
            return (false);
    return (true);
}

bool error_management(int ac, const char **av)
{
    if (ac < 2)
        return (false);
    if (strcmp(av[1], "-help") != 0 && !is_number(av[1]))
        return (false);
    return (true);
}

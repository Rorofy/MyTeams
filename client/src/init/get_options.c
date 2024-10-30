/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that parses options from args
*/

#include <types.h>

options_t *get_options(int ac, const char **av)
{
    options_t *res;

    if (ac < 2)
        return (NULL);
    res = calloc(1, sizeof(options_t));
    if (res == NULL)
        return (NULL);
    res->ip = av[1];
    if (ac == 2)
        return (res);
    if (ac > 2)
        res->port = atoi(av[2]);
    return (res);
}
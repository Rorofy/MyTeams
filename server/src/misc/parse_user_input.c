/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that parse user input
*/

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <misc.h>

uint16_t parse_user_input(const char *arg)
{
    if (strcmp(arg, "-help") == 0) {
        display_help();
        return (0);
    }
    return (atoi(arg));
}

/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** help function
*/

#include <types.h>
#include <stdio.h>

void help(
    __attribute__((unused))client_t *client,
    __attribute__((unused))const char *input)
{
    printf(
        "The following commands are available:\n\t"
        "CREATE\n\t"
        "INFO\n\t"
        "LIST\n\t"
        "LOGIN\n\t"
        "LOGOUT\n\t"
        "MESSAGES\n\t"
        "SEND\n\t"
        "SUBSCRIBE\n\t"
        "SUBSCRIBED\n\t"
        "UNSUBSCRIBE\n\t"
        "USE\n\t"
        "USER\n\t"
        "USERS\n"
    );
}

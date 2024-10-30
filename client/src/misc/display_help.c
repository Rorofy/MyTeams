/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that prints client help
*/

#include <stdio.h>

void display_help(void)
{
    printf(
        "USAGE: ./myteams_server port\n\t"
        "ip is the server ip address on which the server socket listens\n\t"
        "port is the port number on which the server socket listens\n"
    );
}
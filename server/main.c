/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** server entry point
*/

#include <types.h>
#include <init.h>
#include <core.h>
#include <misc.h>
#include <signal.h>
#include <stdio.h>
#include <save.h>

static int driver_program(const char *args)
{
    uint16_t port = parse_user_input(args);
    server_t *server;

    if (port == 0)
        return (0);
    server = init_server_struct(port);
    if (server == NULL)
        return (84);
    load_users(server->users);
    if (!loop(server))
        return (84);
    return (0);
}

int main(int ac, const char **av)
{
    struct sigaction sa_pipe = {0};

    sa_pipe.sa_handler = SIG_IGN;
    sa_pipe.sa_flags = SA_RESTART;
    sigaction(SIGPIPE, &sa_pipe, NULL);
    if (!error_management(ac, av))
        return (84);
    return (driver_program(av[1]));
}

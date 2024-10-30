/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** server struct initialization function
*/

#include <init.h>
#include <misc.h>
#include <stdio.h>
#include "types.h"

static bool init_users(server_t *server)
{
    server->users = vector_create(user_t);
    if (server->users == NULL) {
        fprintf(stdout, "Error occurred in user vector creation process");
        return (false);
    }
    return (true);
}

static bool init_teams(server_t *server)
{
    server->teams = vector_create(team_t);
    if (server->users == NULL) {
        fprintf(stdout, "Error occurred in teams vector creation process");
        return (false);
    }
    return (true);
}

static bool init_clients(server_t *server)
{
    server->clients = vector_create(client_t);
    if (server->users == NULL) {
        fprintf(stdout, "Error occurred in clients vector creation process");
        return (false);
    }
    return (true);
}

static bool init_structures(server_t *server)
{
    if (!init_users(server))
        return (false);
    if (!init_teams(server))
        return (false);
    if (!init_clients(server))
        return (false);
    return (true);
}

server_t *init_server_struct(uint16_t port)
{
    server_t *res = calloc(1, sizeof(server_t));

    if (res == NULL)
        return (NULL);
    res->sock = init_server_socket(port);
    if (res->sock == NULL) {
        free(res);
        return (NULL);
    }
    if (!init_structures(res))
        return (NULL);
    return (res);
}

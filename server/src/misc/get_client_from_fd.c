/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that gets a client from a fd
*/

#include <types.h>
#include <misc.h>

static bool cmp_fun(client_t *client, int fd)
{
    return (client->fd == fd);
}

client_t *get_client_from_fd(server_t *server, int fd)
{
    client_t *client = NULL;

    vector_find(server->clients, client, cmp_fun, fd);
    return (client);
}

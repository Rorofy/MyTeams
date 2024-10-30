/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that init a new client
*/

#include <types.h>

void init_client(client_t *client, int client_fd)
{
    memset(client, 0, sizeof(client_t));
    client->fd = client_fd;
}

/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that disconnect a client
*/

#include <types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <myteams/logging_server.h>
#include <stdbool.h>
#include <stdio.h>

static size_t get_client_pos(server_t *server, int fd)
{
    size_t res = 0;

    vector_foreach(server->clients, e) {
        if (e->fd == fd)
            break;
        else
            ++res;
    }
    return (res);
}

static bool cmp_fun(user_t *user, uuid_t uuid)
{
    char usr_uuid[37];
    char srv_uuid[37];

    uuid_unparse_lower(uuid, usr_uuid);
    uuid_unparse_lower(user->uuid, srv_uuid);
    return (!uuid_compare(user->uuid, uuid));
}

static void free_client_buffs(client_t *client)
{
    if (client->writing_buff != NULL)
        free(client->writing_buff);
    if (client->reading_buff != NULL)
        free(client->reading_buff);
}

void disconnect_client(server_t *server, client_t *client)
{
    size_t client_pos;
    char uuid[37];
    user_t *usr = NULL;

    vector_find(server->users, usr, cmp_fun, client->uuid);
    if (usr != NULL) {
        --(usr->numberOfConnections);
        uuid_unparse_lower(usr->uuid, uuid);
        server_event_user_logged_out(uuid);
    }
    if (client->write_size > 0)
        FD_CLR(client->fd, &(server->sock->write_fd_set));
    FD_CLR(client->fd, &(server->sock->read_fd_set));
    free_client_buffs(client);
    client_pos = get_client_pos(server, client->fd);
    shutdown(client->fd, SHUT_RDWR);
    close(client->fd);
    vector_pop_elem(server->clients, client_pos);
}

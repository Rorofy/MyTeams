/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** logout command implementation
*/

#include <types.h>
#include <myteams/logging_server.h>
#include <misc.h>
#include <stdio.h>

static void broadcast_logout(server_t *server, uuid_t uuid, char *username)
{
    server_packet_t packet = {
        .header = {
            .type = EVENT_LOGGED_OUT
        }
    };

    memcpy(&packet.data.user_data.uuid, uuid, sizeof(uuid_t));
    memcpy(&packet.data.user_data.username, username, strlen(username));
    broadcast_message(server, (const char *)&packet, sizeof(server_packet_t));
}

static bool cmp_fun(user_t *user, uuid_t uuid)
{
    return (!uuid_compare(user->uuid, uuid));
}

void logout(
    server_t *server,
    client_t *client,
    __attribute__((unused))client_packet_t *packet)
{
    char uuid[37];
    user_t *target = NULL;

    if (!mem_checkval((const char *)client->uuid, 0, sizeof(uuid_t))) {
        vector_find(server->users, target, cmp_fun, client->uuid);
        uuid_unparse_lower(client->uuid, uuid);
        server_event_user_logged_out(uuid);
        if (target != NULL) {
            broadcast_logout(server, client->uuid, target->name);
            --(target->numberOfConnections);
        }
        memset(client->uuid, 0, sizeof(uuid_t));
    }
}

/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** user command implementation
*/

#include <types.h>
#include <stdio.h>
#include <core.h>

void users(
    server_t *server,
    client_t *client,
    __attribute__((unused))client_packet_t *packet)
{
    server_packet_t data;

    memset(&data, 0, sizeof(data));
    vector_foreach(server->users, e) {
        data.header.type = EVENT_USER_LISTED;
        memcpy(data.data.user_data.uuid, e->uuid, sizeof(uuid_t));
        memcpy(data.data.user_data.username, e->name, strlen(e->name));
        data.data.user_data.connected = e->numberOfConnections > 0;
        send_message(server, client, (const char *)&data, sizeof(data));
    }
}

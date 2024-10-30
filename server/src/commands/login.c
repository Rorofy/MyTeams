/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** login command implementation
*/

#include <types.h>
#include <stdio.h>
#include <stdbool.h>
#include <init.h>
#include <myteams/logging_server.h>
#include <misc.h>

static bool cmp_fun(user_t *user, char username[MAX_NAME_LENGTH])
{
    return (strcmp(user->name, username) == 0);
}

static user_t *append_user(
    server_t *server,
    const char username[MAX_BODY_LENGTH])
{
    user_t user;

    create_user(&user, username);
    vector_emplace_back((server->users), user);
    return vector_back(server->users);
}

static void send_login_message(server_t *server, char *username, uuid_t uuid)
{
    server_packet_t packet = {
        .header.type = EVENT_LOGGED_IN
    };

    memcpy(&(packet.data.user_data.username), username, strlen(username));
    memcpy(&(packet.data.user_data.uuid), uuid, sizeof(uuid_t));
    broadcast_message(server, (const char *)&packet, sizeof(server_packet_t));
}

void login(
    server_t *server,
    client_t *client,
    client_packet_t *packet)
{
    user_t *user = NULL;
    char uuid[37];

    vector_find(server->users, user, cmp_fun, packet->data.username);
    if (user == NULL) {
        user = append_user(server, packet->data.username);
        uuid_unparse_lower(user->uuid, uuid);
        server_event_user_created(uuid, user->name);
    } else
        uuid_unparse_lower(user->uuid, uuid);
    ++(user->numberOfConnections);
    memcpy(client->uuid, user->uuid, sizeof(uuid_t));
    server_event_user_logged_in(uuid);
    send_login_message(server, user->name, user->uuid);
}

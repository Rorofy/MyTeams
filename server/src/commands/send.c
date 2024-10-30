/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** send command implementation
*/

#include <types.h>
#include <stdio.h>
#include <stdbool.h>
#include <core.h>
#include <myteams/logging_server.h>

static bool user_cmp(user_t *user, uuid_t target_uuid)
{
    return (!uuid_compare(user->uuid, target_uuid));
}

static void send_msg(
    server_t *server,
    uuid_t target,
    message_t *msg,
    uuid_t sender)
{
    char snd_uuid[37];
    char rcv_uuid[37];
    server_packet_t send = {
        .header.type = EVENT_PRIVATE_MESSAGE_RECEIVED,
        .data = {
            .message_data = {
                .timestamp = msg->msg_timestamp,
            }
        }
    };

    strcpy(send.data.message_data.msg.message_body, msg->msg);
    memcpy(send.data.message_data.msg.user_uuid, sender, sizeof(uuid_t));
    uuid_unparse_lower(sender, snd_uuid);
    uuid_unparse_lower(target, rcv_uuid);
    server_event_private_message_sended(
        snd_uuid, rcv_uuid, send.data.message_data.msg.message_body);
    vector_foreach(server->clients, e)
        if (!uuid_compare(e->uuid, target))
            send_message(server, e, (const char *) &send, sizeof(send));
}

void send(
    server_t *server,
    client_t *client,
    client_packet_t *packet)
{
    user_t *target = NULL;
    message_t msg = {
        .msg = strdup(packet->data.msg_send_data.message_body),
        .msg_timestamp = time(NULL)
    };

    vector_find(
        server->users, target, user_cmp, packet->data.msg_send_data.user_uuid
    );
    if (target != NULL)
        send_msg(
            server, packet->data.msg_send_data.user_uuid, &msg, client->uuid);
}

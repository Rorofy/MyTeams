/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** private message received event
*/

#include <types.h>
#include <stdio.h>
#include <server_packet.h>
#include <myteams/logging_client.h>

void private_message_received(
    client_t *client,
    server_packet_t *packet)
{
    char uuid[37];

    uuid_unparse_lower(packet->data.message_data.msg.user_uuid, uuid);
    client_event_private_message_received(
        uuid,
        packet->data.message_data.msg.message_body
    );
}

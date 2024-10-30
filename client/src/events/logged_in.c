/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** logged in event
*/

#include <server_packet.h>
#include <types.h>
#include <myteams/logging_client.h>
#include <stdio.h>

void logged_in(
    __attribute__((unused))client_t *client,
    server_packet_t *packet)
{
    char uuid[37] = {0};

    uuid_unparse_lower(packet->data.user_data.uuid, uuid);
    client_event_logged_in(
        uuid,
        packet->data.user_data.username
    );
}

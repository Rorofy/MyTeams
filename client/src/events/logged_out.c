/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** logged out event
*/

#include <server_packet.h>
#include <types.h>
#include <myteams/logging_client.h>

void logged_out(
    __attribute__((unused))client_t *client,
    __attribute__((unused))server_packet_t *packet)
{
    char uuid[37] = {0};

    uuid_unparse_lower(packet->data.user_data.uuid, uuid);
    client_event_logged_out(
        uuid,
        packet->data.user_data.username
    );
}

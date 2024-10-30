/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** user listed event
*/

#include <server_packet.h>
#include <types.h>
#include <stdio.h>
#include <myteams/logging_client.h>

void user_listed(
    __attribute__((unused))client_t *client,
    server_packet_t *packet)
{
    char uuid[37];

    uuid_unparse_lower(packet->data.user_data.uuid, uuid);
    client_print_user(
        uuid,
        packet->data.user_data.username,
        packet->data.user_data.connected);
}

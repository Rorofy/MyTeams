/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** create command implementation
*/

#include <types.h>
#include <stdio.h>
#include <misc.h>

void parse_context(client_packet_t *packet)
{
    if (mem_checkval((const char *) packet->data.uuid, 0, sizeof(uuid_t)))
    {}
}

void create(
    __attribute__((unused))server_t *server,
    __attribute__((unused))client_t *client,
    client_packet_t *packet)
{
    printf(
        "CREATION PACKET, >%s< - >%s<\n",
        packet->data.creation_data.name,
        packet->data.creation_data.message
    );
}

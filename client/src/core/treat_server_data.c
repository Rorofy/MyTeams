/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that treats server data sent by server
*/

#include <types.h>
#include <server_packet.h>
#include <misc.h>
#include <core.h>

void treat_server_data(client_t *client)
{
    server_packet_t *packet;

    while (client->buff_size >= sizeof(server_packet_t)) {
        packet = pop_first_server_msg(client);
        parse_event(client, packet);
        free(packet);
    }
}
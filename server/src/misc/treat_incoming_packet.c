/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that treats incoming packets
*/

#include <types.h>
#include <misc.h>

void treat_incoming_packet(
    server_t *server,
    client_t *client,
    client_packet_t *packet)
{
    command_t *cmd = get_command(packet->header.type);

    if (cmd != NULL)
        cmd(server, client, packet);
}

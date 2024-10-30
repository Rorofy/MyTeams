/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that process a fd given by process_read_fds
*/

#include <types.h>
#include <core.h>
#include <misc.h>
#include <stdio.h>

void treat_read_fd(server_t *server, int fd)
{
    client_t *client = NULL;
    client_packet_t *packet;

    if (fd == server->sock->fd)
        accept_client(server);
    else {
        client = get_client_from_fd(server, fd);
        if (!buffer_user_input(client)) {
            disconnect_client(server, client);
            return;
        }
        if (client == NULL)
            return;
        while (client->read_size >= sizeof(client_packet_t)) {
            packet = get_first_packet_from_buff(client);
            treat_incoming_packet(server, client, packet);
            free(packet);
        }
    }
}

/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that pop and returns the first server message from client's buffer
*/

#include <server_packet.h>
#include <types.h>

server_packet_t *pop_first_server_msg(client_t *client)
{
    server_packet_t *res = calloc(1, sizeof(server_packet_t));

    if (res == NULL)
        return (NULL);
    memcpy(res, client->buff, sizeof(server_packet_t));
    memmove(
        client->buff,
        client->buff + sizeof(server_packet_t),
        client->buff_size - sizeof(server_packet_t)
    );
    client->buff_size -= sizeof(server_packet_t);
    client->buff = reallocarray(
        client->buff,
        client->buff_size,
        sizeof(unsigned char)
    );
    return (res);
}

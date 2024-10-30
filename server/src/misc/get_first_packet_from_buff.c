/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that reads the first packet from the reading buffer client
*/

#include <types.h>

client_packet_t *get_first_packet_from_buff(client_t *client)
{
    client_packet_t *res = calloc(1, sizeof(client_packet_t));

    if (res == NULL)
        return (NULL);
    memcpy(res, client->reading_buff, sizeof(client_packet_t));
    memmove(
        client->reading_buff,
        client->reading_buff + sizeof(client_packet_t),
        client->read_size - sizeof(client_packet_t)
    );
    client->read_size -= sizeof(client_packet_t);
    client->reading_buff = reallocarray(
        client->reading_buff,
        client->read_size,
        sizeof(unsigned char)
    );
    return (res);
}
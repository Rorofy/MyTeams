/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** users function
*/

#include <types.h>
#include <unistd.h>

void users(
    __attribute__((unused))client_t *client,
    __attribute__((unused))const char *input)
{
    client_packet_t packet = {
        .header = {
            .type = USERS
        }
    };

    write(client->fd, &packet, sizeof(client_packet_t));
}

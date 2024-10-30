/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** logout function
*/

#include <types.h>
#include <unistd.h>

void logout(
    client_t *client,
    __attribute__((unused))const char *input)
{
    client_packet_t packet = {
        .header = {
            .type = LOGOUT
        }
    };

    write(client->fd, &packet, sizeof(packet));
}

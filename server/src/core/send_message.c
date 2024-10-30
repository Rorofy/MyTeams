/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that sends a message to a client
*/

#include <types.h>

void send_message(
    server_t *server,
    client_t *client,
    const char *msg,
    size_t msg_len)
{
    client->writing_buff = reallocarray(
        client->writing_buff,
        client->write_size + msg_len,
        sizeof(char)
    );
    memcpy(client->writing_buff + client->write_size, msg, msg_len);
    client->write_size += msg_len;
    FD_SET(client->fd, &(server->sock->write_fd_set));
}

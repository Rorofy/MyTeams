/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that write buffered data to user
*/

#include <unistd.h>
#include <stdbool.h>
#include <types.h>

bool write_buffered_output(server_t *server, client_t *client)
{
    ssize_t ret = write(client->fd, client->writing_buff, client->write_size);

    if (ret < 1)
        return (false);
    memmove(
        client->writing_buff,
        client->writing_buff + ret,
        client->write_size - ret
    );
    client->write_size -= ret;
    client->writing_buff = reallocarray(
        client->writing_buff,
        client->write_size,
        sizeof(unsigned char)
    );
    if (client->write_size == 0)
        FD_CLR(client->fd, &(server->sock->write_fd_set));
    return (true);
}

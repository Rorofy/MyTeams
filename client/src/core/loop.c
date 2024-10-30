/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** client loop
*/

#include <sys/select.h>
#include <stddef.h>
#include <types.h>
#include <core.h>

static void init_fd_set(fd_set *read_fd, int fd)
{
    FD_SET(0, read_fd);
    FD_SET(fd, read_fd);
}

int loop(client_t *client)
{
    fd_set read_fd;
    fd_set active_read_fd;

    FD_ZERO(&read_fd);
    init_fd_set(&read_fd, client->fd);
    while (1) {
            active_read_fd = read_fd;
        if (select(client->fd + 1, &active_read_fd, NULL, NULL, NULL) == -1)
            return (84);
        treat_ready_fds(client, &active_read_fd);
    }
}

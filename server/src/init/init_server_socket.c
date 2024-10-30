/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** server socket initialization function
*/

#include <stdint.h>
#include <init.h>
#include <stdio.h>

socket_t *init_server_socket(uint16_t port)
{
    socket_t *res = calloc(1, sizeof(socket_t));

    if (res == NULL)
        return (NULL);
    res->port = port;
    res->fd = init_raw_socket(port);
    if (res->fd == -1) {
        fprintf(stdout, "Socket creation on port %d, failed\n", port);
        free(res);
        return (NULL);
    }
    FD_ZERO(&(res->read_fd_set));
    FD_ZERO(&(res->write_fd_set));
    FD_SET(res->fd, &(res->read_fd_set));
    return (res);
}

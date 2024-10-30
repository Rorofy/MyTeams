/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that destroy properly the socket structure
*/

#include <types.h>
#include <resolv.h>
#include <unistd.h>

void destroy_socket(socket_t *sock)
{
    shutdown(sock->fd, SHUT_RDWR);
    close(sock->fd);
    free(sock);
}
